// ---------------------------------------------------------------------------

#pragma hdrstop

#include "PolynomialAndInterpInfo.h"
// ---------------------------------------------------------------------------
#pragma package(smart_init)

BasePolynomial::BasePolynomial(InterpInfo* info) {
	itsInfo = info;
	h = (itsInfo->b - itsInfo->a) / (itsInfo->N - 1);

	double x = itsInfo->a;
	for (unsigned int i = 0; i < itsInfo->N; i++) {
		xVec.push_back(x);
		x += h;
	}
}

double LagrangePolynomial::functionPolynomial(double x) {
	double result = 0;

	for (unsigned int i = 0; i < xVec.size(); i++) {
		double w = 1;
		for (unsigned int j = 0; j < xVec.size(); j++) {
			if (i != j) {
				w *= (x - xVec[j]) / (xVec[i] - xVec[j]);
			}
		}
		result += func(xVec[i]) * w;
	}
	return result;
}

NewtonIPoly::NewtonIPoly(InterpInfo* info) : BaseNewtonPolynomial(info) {
	double a = func(itsInfo->a);
	for (unsigned int i = 1; i < itsInfo->N; i++) {
		aVec.push_back(a);
		a = deltaY(i) / (factorial(i) * pow(h, (int)i));
	}
}

double NewtonIPoly::deltaY(unsigned i) {
	if (i == 0) return func(xVec[0]);

	std::vector<double> deltaYi;
	std::vector<double> deltaYo;

	for (unsigned j = 1; j <= i; j++) {
		for (unsigned int k = 0; k < (itsInfo->N - j); k++) {
			if (deltaYi.size() != (itsInfo->N - 1)) {
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

double NewtonIPoly::functionPolynomial(double x) {
	double result = 0;
	for (unsigned int i = 0; i < xVec.size(); i++) {
		if (i == 0) {
			result += aVec[i];
			continue;
		}

		double w = 1;
		for (unsigned int j = 0; j < i; j++) {
			w *= (x - xVec[j]);
		}
		result += aVec[i] * w;
	}
	return result;
}

NewtonIIPoly::NewtonIIPoly(InterpInfo* info) : BaseNewtonPolynomial(info) {
	double a = func(itsInfo->b);
	for (unsigned int i = 1; i < itsInfo->N; i++) {
		aVec.push_back(a);
		a = deltaY(i) / (factorial(i) * pow(h, (int)i));
	}
}

double NewtonIIPoly::deltaY(unsigned i) {
	if (i == 0) return func(xVec[itsInfo->N - 1]);

	std::vector<double>deltaYi;
	std::vector<double>deltaYn;

	for (unsigned j = 1; j <= i; j++) {

		for (unsigned j = 1; j <= i; j++) {
			for (unsigned k = 0; k < (itsInfo->N - j); k++) {
				if (deltaYi.size() < (itsInfo->N - 1)) {
					deltaYi.push_back(func(xVec[k + 1]) - func(xVec[k]));
				}
				else {
					deltaYi.push_back(deltaYi[k + 1] - deltaYi[k]);
				}

				if ((j + 1) > i && k == (itsInfo->N - 1) - i) {
					deltaYn.push_back(deltaYi.back());
				}
			}
		}
	}
    return deltaYn[0];
}

double NewtonIIPoly::functionPolynomial(double x) {
	double result = 0;
	for (unsigned i = 0; i < xVec.size(); i++) {
		if (i == (xVec.size() - 1)) {
			result += aVec[0];
			result += aVec[i];
			continue;
		}

		double w = 1;
		for (unsigned int j = (xVec.size() - 1); j > i; j--) {
			w *= (x - xVec[j]);
		}
		result += aVec[i] * w;
	}
	return result;
}

double func(double x) {
	return x*exp(x);
}

double factorial(double n) {
	if (n == 1 || n == 0)
		return 1;
	else
		return n * factorial(n - 1);
}
