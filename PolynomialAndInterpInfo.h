// ---------------------------------------------------------------------------

#ifndef PolynomialAndInterpInfoH
#define PolynomialAndInterpInfoH
// ---------------------------------------------------------------------------

#include <math.h>
#include <vector>

// # DEBUG
#include <Vcl.Dialogs.hpp>

long factorial(const int & n);
double func(const double & x);

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

struct DifferenceInfo {
	double value;
	bool isFilled;

	DifferenceInfo(double value, bool isFilled) {
		this->value = value;
		this->isFilled = isFilled;
    }
};

class BasePolynomial {
public:
	BasePolynomial(const InterpInfo* info);
	virtual ~BasePolynomial();
	virtual double functionPolynomial(const double & x) const = 0;

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
	double functionPolynomial(const double & x) const override;
};

class BaseNewtonPolynomial : public BasePolynomial {
public:
	BaseNewtonPolynomial(const InterpInfo* info) : BasePolynomial(info) { }
	virtual ~BaseNewtonPolynomial();
	virtual double functionPolynomial(const double & x) const = 0;

protected:
	typedef std::vector<DifferenceInfo> vec_diff;
	std::vector<vec_diff*> main_vec;

	double delta(const unsigned & i, const unsigned & j);
};

class NewtonIPoly : public BaseNewtonPolynomial {
public:
	NewtonIPoly(const InterpInfo* info);
	~NewtonIPoly() override { }
	double functionPolynomial(const double & x) const override;

private:
};

class NewtonIIPoly : public BaseNewtonPolynomial {
public:
	NewtonIIPoly(const InterpInfo* info);
    ~NewtonIIPoly() override { }
	double functionPolynomial(const double & x) const override;

private:
};

#endif
