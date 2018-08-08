// ---------------------------------------------------------------------------

#ifndef PolynomialAndInterpInfoH
#define PolynomialAndInterpInfoH
// ---------------------------------------------------------------------------

#include <math.h>
#include <vector>

#include <Vcl.Dialogs.hpp>

long factorial(int n);
double func(double x);

const std::wstring LAGRANGE_POLYNOMIAL_STR = L"Полином Лагранжа";
const std::wstring NEWTON_I_POLYNOMIAL_STR = L"Полином Ньютона I";
const std::wstring NEWTON_II_POLYNOMIAL_STR = L"Полином Ньютона II";

struct InterpInfo {
	std::wstring functionStr;
	std::wstring polynomialStr;

	double a, b;
	size_t N;

	InterpInfo(std::wstring funcStr, std::wstring polyStr,
			   double a, double b, size_t N) {
		functionStr = funcStr;
		polynomialStr = polyStr;
		this->a = a;
		this->b = b;
        this->N = N;
	}

	InterpInfo(const InterpInfo & baseInfo) {
		this->functionStr = baseInfo.functionStr;
		this->polynomialStr = baseInfo.polynomialStr;
		this->a = baseInfo.a;
		this->b = baseInfo.b;
		this->N = baseInfo.N;
	}
};

class BasePolynomial {
public:
	BasePolynomial(const InterpInfo* info);
	virtual ~BasePolynomial();
	virtual double functionPolynomial(double x) = 0;

protected:
	std::vector<double> aVec;
	std::vector<double> xVec;

	const InterpInfo* itsInfo;
	double h;
};

class LagrangePolynomial : public BasePolynomial {
public:
	LagrangePolynomial(const InterpInfo* info) : BasePolynomial(info) { }
	~LagrangePolynomial() override { }
	double functionPolynomial(double x) override;
};

class BaseNewtonPolynomial : public BasePolynomial {
public:
	BaseNewtonPolynomial(const InterpInfo* info) : BasePolynomial(info) { }
	virtual ~BaseNewtonPolynomial() { }
	virtual double functionPolynomial(double x) = 0;

protected:
	virtual double deltaY(unsigned i) = 0;
};

class NewtonIPoly : public BaseNewtonPolynomial {
public:
	NewtonIPoly(const InterpInfo* info);
	~NewtonIPoly() override { }
	double functionPolynomial(double x) override;

private:
	double deltaY(unsigned i) override;
};

class NewtonIIPoly : public BaseNewtonPolynomial {
public:
	NewtonIIPoly(const InterpInfo* info);
    ~NewtonIIPoly() override { }
	double functionPolynomial(double x) override;

private:
	double deltaY(unsigned i) override;
};

#endif
