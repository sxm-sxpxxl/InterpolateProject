// ---------------------------------------------------------------------------

#ifndef PolynomialAndInterpInfoH
#define PolynomialAndInterpInfoH
// ---------------------------------------------------------------------------

#include <math.h>
#include <vector>

double factorial(double n);
double func(double x);

const std::wstring LAGRANGE_POLYNOMIAL_STR = L"Полином Лагранжа";
const std::wstring NEWTON_I_POLYNOMIAL_STR = L"Полином Ньютона I";
const std::wstring NEWTON_II_POLYNOMIAL_STR = L"Полином Ньютона II";

struct InterpInfo {
	std::wstring functionStr;
	std::wstring polynomialStr;

	double a, b;
	unsigned int N;
};

struct Polynomial {
	std::vector<double>aVec;
	std::vector<double>xVec;
};

class BasePolynomial {
public:
	BasePolynomial(InterpInfo* info);
	virtual double functionPolynomial(double x) = 0;

protected:
	std::vector<double>aVec;
	std::vector<double>xVec;

	InterpInfo* itsInfo;
	double h;
};

class LagrangePolynomial : public BasePolynomial {
public:
	LagrangePolynomial(InterpInfo* info) : BasePolynomial(info) {}
	double functionPolynomial(double x);
};

class BaseNewtonPolynomial : public BasePolynomial {
public:
	BaseNewtonPolynomial(InterpInfo* info) : BasePolynomial(info) { }
	virtual double functionPolynomial(double x) = 0;

protected:
	virtual double deltaY(unsigned i) = 0;
};

class NewtonIPoly : public BaseNewtonPolynomial {
public:
	NewtonIPoly(InterpInfo* info);
	double functionPolynomial(double x);

private:
	double deltaY(unsigned i);
};

class NewtonIIPoly : public BaseNewtonPolynomial {
public:
	NewtonIIPoly(InterpInfo* info);
	double functionPolynomial(double x);

private:
	double deltaY(unsigned i);
};

#endif
