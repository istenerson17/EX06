#ifndef COMPLEX_H
#define COMPLEX_H
#include <string>
using namespace std;

class Complex
{
private:
	double a;
	double b;
	char i = 'i';

public:
	Complex();
	Complex(double a);
	Complex(double a, double b);

	double getRealPart() const;
	double getImaginaryPart() const;

	string toString()const;

	Complex Add(const Complex &secondC);
	Complex operator+(const Complex &secondC);
	Complex operator+=(const Complex &secondC);

	Complex Subtract(const Complex &secondC);
	Complex operator-(const Complex &secondC);
	Complex operator-=(const Complex &secondC);

	Complex Multiply(const Complex &secondC);
	Complex operator*(const Complex &secondC);
	Complex operator*=(const Complex &secondC);

	Complex Divide(const Complex &secondC);
	Complex operator/(const Complex &secondC);
	Complex operator/=(const Complex &secondC);

	Complex Abs();

	Complex operator[](bool i);
	Complex operator-();
	Complex operator+();
	Complex operator--();
	Complex operator++();
	Complex operator--(int dummy);
	Complex operator++(int dummy);

	friend ostream& operator<<(ostream& out, const Complex &complex);
	friend istream& operator>>(istream in, Complex &complex);
};
#endif