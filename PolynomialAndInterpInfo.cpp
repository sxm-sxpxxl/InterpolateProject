// ---------------------------------------------------------------------------

#pragma hdrstop

#include "PolynomialAndInterpInfo.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

BasePolynomial::BasePolynomial(const InterpInfo * info) {
	itsInfo = info;
	h = abs(itsInfo->b - itsInfo->a) / (itsInfo->N - 1);

	double x = (itsInfo->a < itsInfo->b) ? itsInfo->a : itsInfo->b;
    double end_point = (itsInfo->a < itsInfo->b) ? itsInfo->b : itsInfo->a;
	while (x <= end_point) {
		xVec.push_back(x);
		x += h;
	}
}

BasePolynomial::~BasePolynomial() {
	delete itsInfo;
}

double LagrangePolynomial::functionPolynomial(const double & x) {
	double result = 0;

	for (size_t i = 0; i < xVec.size(); i++) {
		double w = 1;
		for (size_t j = 0; j < xVec.size(); j++) {
			if (i != j) {
				w *= (x - xVec[j]) / (xVec[i] - xVec[j]);
			}
		}
		result += func(xVec[i]) * w;
	}
	return result;
}

NewtonIPoly::NewtonIPoly(const InterpInfo* info) : BaseNewtonPolynomial(info) {
	double a = 0.0;
	aVec.push_back(func(itsInfo->a));

	for (int i = 1; i < (int) itsInfo->N; i++) {
		a = deltaY(i) / (factorial(i) * pow(h, i));
        aVec.push_back(a);
	}
}

double NewtonIPoly::deltaY(const unsigned & i) {
	if (i == 0)
		return func(xVec[0]);

	std::vector<double> deltaYi;
	std::vector<double> deltaYo;

	for (size_t j = 1; j <= i; j++) {
		for (size_t k = 0; k < (itsInfo->N - j); k++) {
			if (deltaYi.size() < (itsInfo->N - 1)) {
				deltaYi.push_back(func(xVec[k + 1]) - func(xVec[k]));
			}
			else {
				deltaYi.push_back(deltaYi[k + 1] - deltaYi[k]);
            }

			if (k == 0) {
				deltaYo.push_back(deltaYi.back());
			}
		}
	}
	return deltaYo[i - 1];
}

double NewtonIPoly::functionPolynomial(const double & x) {
	double result = aVec[0]; // aVec[0] == func(0)
	for (size_t i = 1; i < xVec.size(); i++) {
		double w = 1.0;
		for (size_t j = 0; j < i; j++) {
			w *= (x - xVec[j]);
        }
		result += aVec[i] * w;
	}
	return result;
}

NewtonIIPoly::NewtonIIPoly(const InterpInfo* info) : BaseNewtonPolynomial(info) {
	double a = 0.0;
	aVec.push_back(func(itsInfo->b));

	for (int i = 1; i < (int) itsInfo->N; i++) {
		a = deltaY(i) / (factorial(i) * pow(h, i));
        aVec.push_back(a);
	}
}

double NewtonIIPoly::deltaY(const unsigned & i) {
	if (i == 0)
		return func(xVec[itsInfo->N - 1]);

	std::vector<double> deltaYi;
	std::vector<double> deltaYn;

	for (size_t j = 1; j <= i; j++) {
		for (size_t k = 0; k < (itsInfo->N - j); k++) {
			if (deltaYi.size() < (itsInfo->N - 1)) {
				deltaYi.push_back(func(xVec[k + 1]) - func(xVec[k]));
			}
			else {
				deltaYi.push_back(deltaYi[k + 1] - deltaYi[k]);
			}

			if (k == (itsInfo->N - j) - 1) {
				deltaYn.push_back(deltaYi.back());
			}
		}
	}
	return deltaYn[i - 1];
}

double NewtonIIPoly::functionPolynomial(const double & x) {
	double result = func(xVec.back());

	for (size_t i = 0; i < xVec.size() - 1; i++) {
		double w = 1.0;
		for (size_t j = (xVec.size() - 1), k = 0; k <= i; j--, k++) {
			w *= (x - xVec[j]);
		}
		result += aVec[i] * w;
	}
	return result;
}

double func(const double & x) {
	return x*exp(x);
}

long factorial(const int & n) {
	long result = 1;
	if (n == 1 || n == 0) return 1;
	else for (int i = 1; i <= n; ++i) result *= i;
    return result;
}
