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

BaseNewtonPolynomial::~BaseNewtonPolynomial() {
	for (auto sub_vec : main_vec) delete sub_vec;
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

double BaseNewtonPolynomial::delta(const unsigned & order, const unsigned & index) {
	// order - порядок конечной разности
	// index - индекс конечной разности порядка order

	if (order == 0) {
		return func(xVec[index]);
	}

	if (main_vec.empty()) {
		// Предварительное вычисление вектора конечных разностей первого порядка
		// и добавление на хранение в общий вектор
		vec_diff* first_order_vec = new vec_diff;
		for (size_t i = 0; i < (itsInfo->N - 1); ++i) {
			first_order_vec->push_back( { func(xVec[i + 1]) - func(xVec[i]), true } );
		}
		main_vec.push_back(first_order_vec);

		// Начальная инициализация вектора конечных разностей, необходимая для
		// для дальнейшего переопределения реальными значениями
		for (size_t i = 1; i < (itsInfo->N - 1); ++i) {
			main_vec.push_back(new vec_diff( (itsInfo->N - 1) - i, { 0.0, false } ));
		}
	}

	// Пересчет индекса конечной разности для вектора, поскольку индексация в векторе
	// начинается с 0, а в order с 1
	const unsigned order_recalc = order - 1;

	// Эффективное рекурсивное заполнение только необходимых полей (значений конечных разностей)
	if (main_vec[order_recalc]->operator[](index).isFilled) {
		return main_vec[order_recalc]->operator[](index).value;
	}
	else {
		main_vec[order_recalc]->operator[](index).value = delta(order_recalc - 1, index + 1) - delta(order_recalc - 1, index);
		main_vec[order_recalc]->operator[](index).isFilled = true;
		return main_vec[order_recalc]->operator[](index).value;
	}
}

NewtonIPoly::NewtonIPoly(const InterpInfo* info) : BaseNewtonPolynomial(info) {
	double a = 0.0;
	aVec.push_back(func(itsInfo->a));

	for (int i = 1; i < (int) itsInfo->N; i++) {
		a = delta(i, 0) / (factorial(i) * pow(h, i));
        aVec.push_back(a);
	}
}

double NewtonIPoly::functionPolynomial(const double & x) {
	double result = aVec[0]; // aVec[0] == func(0)
	for (size_t i = 1; i < itsInfo->N; i++) {
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

	for (int i = 0; i < (int)itsInfo->N - 1; i++) {
		a = delta(i, (itsInfo->N - 1) - i) / (factorial(i) * pow(h, i));
        aVec.push_back(a);
	}
}

double NewtonIIPoly::functionPolynomial(const double & x) {
	double result = func(xVec.back());

	for (size_t i = 0; i < itsInfo->N - 1; i++) {
		double w = 1.0;
		for (size_t j = (itsInfo->N - 1), k = 0; k <= i; j--, k++) {
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
