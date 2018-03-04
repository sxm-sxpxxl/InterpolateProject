//---------------------------------------------------------------------------

#ifndef FunctionsH
#define FunctionsH
//---------------------------------------------------------------------------

#include <math.h>
#include <vector>

struct InterpInfo {
	std::wstring functionStr;
	double a, b;
	int N;
};

struct Polynomial {
	std::vector<double> aVec;
	std::vector<double> xVec;
};

double func(double x);
void buildPolynomialNewtonI(Polynomial* poly, InterpInfo* info);
void buildPolynomialNewtonII(Polynomial* poly, InterpInfo* info);
double polynomialNewtonI(double xCurrent, Polynomial* poly, InterpInfo* info);
double polynomialNewtonII(double xCurrent, Polynomial* poly, InterpInfo* info);
double polynomialLagrange(double xCurrent, Polynomial* poly, InterpInfo* info);
double deltaY0(int i, int N, std::vector<double> xVec);
double deltaYN(int i, int N, std::vector<double> xVec);
double factorial(double n);

#endif
