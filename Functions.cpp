//---------------------------------------------------------------------------

#pragma hdrstop

#include "Functions.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

double func(double x) {
	return x*exp(x);
}

void buildPolynomialNewtonI(Polynomial* poly, InterpInfo* info) {
	const double h = (info->b - info->a) / (info->N - 1);

	double x = info->a;
	poly->xVec.push_back(x);
	for(int i = 0; i < info->N; i++) {
		x += h;
		poly->xVec.push_back(x);
	}

	double a = func(info->a);
	poly->aVec.push_back(a);
	for(int i = 1; i < info->N; i++) {
		a = deltaY0(i, info->N, poly->xVec) / (factorial(i) * pow(h, i));
		poly->aVec.push_back(a);
	}

	return;
}

void buildPolynomialNewtonII(Polynomial* poly, InterpInfo* info) {
	const double h = (info->b - info->a) / (info->N - 1);

	double x = info->a;
	poly->xVec.push_back(x);
	for(int i = 0; i < info->N; i++) {
		x += h;
		poly->xVec.push_back(x);
	}

	double a = func(info->b);
	poly->aVec.push_back(a);
	for(int i = 1; i < info->N; i++) {
		a = deltaYN(i, info->N, poly->xVec) / (factorial(i) * pow(h, i));
		poly->aVec.push_back(a);
	}

	return;
}

double polynomialNewtonI(double xCurrent, Polynomial* poly, InterpInfo* info) {
	double result = 0;
	for(int i = 0; i < poly->xVec.size(); i++) {
		if(i == 0) {
			result += poly->aVec[i];
			continue;
		}

		double res = 1;
		for(int j = 0; j < i; j++) {
			res *= (xCurrent - poly->xVec[j]);
		}
        result += poly->aVec[i]*res;
	}
	return result;
}

double polynomialNewtonII(double xCurrent, Polynomial* poly, InterpInfo* info) {
	double result = 0;

	// poly->xVec.size() = N -> (poly->xVec.size() - 1) = N - 1 = n
	for(int i = 0; i < poly->xVec.size(); i++) {
		if(i == (poly->xVec.size() - 1)) {
			result += poly->aVec[i];
			continue;
		}

		double res = 1;
		for(int j = poly->xVec.size() - 1; j > i; j--) {
			res *= (xCurrent - poly->xVec[j]);
		}
		result += poly->aVec[i]*res;
	}
	return result;
}

double polynomialLagrange(double xCurrent, Polynomial* poly, InterpInfo* info) {
	double result = 0;

	for(int i = 0; i < poly->xVec.size(); i++) {
		double res = 1;
		for(int j = 0; j < poly->xVec.size(); j++) {
			if(i != j) {
                res *= (xCurrent - poly->xVec[j]) / (poly->xVec[i] - poly->xVec[j]);
			}
		}
		result += func(poly->xVec[i])*res;
	}
	return result;
}

double deltaY0(int i, int N, std::vector<double> xVec) {
	if(i == 0) return func(xVec[0]);

	std::vector<double> deltaYi;
	std::vector<double> deltaYo;

	for(int j = 1; j <= i; j++) {
		for(int k = 0; k < (N - j); k++) {
			if(deltaYi.size() != (N - 1)) {
				deltaYi.push_back(func(xVec[k + 1]) - func(xVec[k]));
			}
			else {
				deltaYi.push_back(deltaYi[k + 1] - deltaYi[k]);
			}

			if(k == 0) {
				deltaYo.push_back(deltaYi.back());
			}
		}
	}
	return deltaYo[i - 1];
}

double deltaYN(int i, int N, std::vector<double> xVec) {
	if(i == 0) return func(xVec[N-1]);

	std::vector<double> deltaYi;
	std::vector<double> deltaYn;

	for(int j = 1; j <= i; j++) {
		for(int k = 0; k < (N - j); k++) {
			if(deltaYi.size() != (N - 1)) {
				deltaYi.push_back(func(xVec[k + 1]) - func(xVec[k]));
			}
			else {
				deltaYi.push_back(deltaYi[k + 1] - deltaYi[k]);
			}

			if(k == (N-1)-i) {
				deltaYn.push_back(deltaYi.back());
			}
		}
	}
	return deltaYn[i - 1];
}

double factorial(double n) {
	if (n == 1 || n == 0)
		return 1;
    else
        return n * factorial(n - 1);
}
