//---------------------------------------------------------------------------

#ifndef PolynomialAndInterpInfoH
#define PolynomialAndInterpInfoH
//---------------------------------------------------------------------------

#include <math.h>
#include <vector>

double factorial(double n);
double func(double x);

struct InterpInfo {
	std::wstring functionStr;
	double a, b;
	unsigned int N;
};

struct Polynomial {
	std::vector<double> aVec;
	std::vector<double> xVec;
};

class BasePolynomial {
public:
	BasePolynomial(InterpInfo* info);
	//~BasePolynomial();
    virtual double functionPolynomial(double x) = 0;
protected:
	std::vector<double> aVec;
	std::vector<double> xVec;
	InterpInfo* itsInfo;
	double h;
};

class LagrangePolynomial : public BasePolynomial {
public:
	LagrangePolynomial(InterpInfo* info) : BasePolynomial(info) { }
	double functionPolynomial(double x);
};

class BaseNewtonPolynomial : public BasePolynomial {
public:
	BaseNewtonPolynomial(InterpInfo* info) : BasePolynomial(info) { }
	virtual double functionPolynomial(double x) = 0;
protected:
    virtual double deltaY(int i) = 0;
};

class NewtonIPoly : public BaseNewtonPolynomial {
public:
	NewtonIPoly(InterpInfo* info);
	double functionPolynomial(double x);
private:
	double deltaY(int i);
};

class NewtonIIPoly : public BaseNewtonPolynomial {
public:
	NewtonIIPoly(InterpInfo* info);
	double functionPolynomial(double x);
private:
	double deltaY(int i);
};

#endif
