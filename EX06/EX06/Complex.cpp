#include "Complex.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

Complex::Complex()
{
	a = 0;
	b = 0;
}

Complex::Complex(double a)
{
	this->a = a;
	b = 0;
}

Complex::Complex(double a, double b)
{
	this->a = a;
	this->b = b;
}

double Complex::getRealPart()const
{
	return a;
}

double Complex::getImaginaryPart()const
{
	return b;
}

string Complex::toString()const
{
	stringstream conv;
	if (b != 0){
		conv << "(" << a << " + " << b << "i)";
		return conv.str();
	}
	else {
		conv << a;
		return conv.str();
	}
}

Complex Complex::Add(const Complex &secondC)
{
	double A = a + (secondC.getRealPart());
	double B = b + (secondC.getImaginaryPart());
	Complex tmp(A, B);
	return tmp;
}

Complex Complex::operator+(const Complex &secondC)
{ 
	return Add(secondC); 
}

Complex Complex::operator+=(const Complex &secondC)
{
	a = a + (secondC.getRealPart());
	b = b + (secondC.getImaginaryPart());
	return *this;
}

Complex Complex::Subtract(const Complex &secondC)
{
	double A = (a - (secondC.getRealPart()));
	double B = (b - (secondC.getImaginaryPart()));
	Complex tmp(A, B);
	return tmp;
}

Complex Complex::operator-(const Complex &secondC)
{
	return Subtract(secondC);
}

Complex Complex::operator-=(const Complex &secondC)
{
	a = (a - (secondC.getRealPart()));
	b = (b - (secondC.getImaginaryPart()));
	return *this;
}

Complex Complex::Multiply(const Complex &secondC)
{
	double A = ((a*secondC.getRealPart()) - (b * secondC.getImaginaryPart()));
	double B = ((b * secondC.getRealPart()) + (a*secondC.getRealPart()));
	Complex tmp(A, B);
	return tmp;
}

Complex Complex::operator*(const Complex &secondC)
{
	return Multiply(secondC); 
}

Complex Complex::operator*=(const Complex &secondC)
{
	double A = ((a*secondC.getRealPart()) - (b * secondC.getImaginaryPart()));
	double B = ((b * secondC.getRealPart()) + (a*secondC.getRealPart()));
	a = A;
	b = B;
	return *this;
}

Complex Complex::Divide(const Complex &secondC)
{
	double c = secondC.getRealPart(), d = secondC.getImaginaryPart();
	double A = ((a*c) + (b*d)) / ((c*c) + (d*d));
	double B = ((b*c) - (a*d)) / ((c*c) + (d*d));
	Complex tmp(A, B);
	return tmp;
}

Complex Complex::operator/(const Complex &secondC)
{
	return Divide(secondC);
}

Complex Complex::operator/=(const Complex &secondC)
{
	double c = secondC.getRealPart(), d = secondC.getImaginaryPart();
	double A = ((a*c) + (b*d)) / ((c*c) + (d*d));
	double B = ((b*c) - (a*d)) / ((c*c) + (d*d));
	a = A;
	b = B;
	return *this;
}

Complex Complex::Abs()
{
	double abs = (a*a) + (b*b);
	return sqrt(abs);
}

Complex Complex::operator[](bool i)
{
	if (i = 0)
		return a;
	if (i = 1)
		return b;
}

Complex Complex::operator-()
{
	return Complex(-a, -b);
}

Complex Complex::operator+()
{
	return Complex(+a, +b);
}

Complex Complex::operator--()
{
	return Complex(--a, --b);
}

Complex Complex::operator++()
{
	return Complex(++a, ++b);
}

Complex Complex::operator--(int dummy)
{
	return Complex(--a, --b);
}

Complex Complex::operator++(int dummy)
{
	return Complex(++a, ++b);
}

ostream& operator<<(ostream& out, const Complex &complex)
{
	out << complex.toString();
	return out;
}

istream& operator>>(istream in, Complex &complex)
{
	cout << "Enter the real part: ";
	double A;
	in >> A;
	cout << "Enter the imaginary part: ";
	double B;
	in >> B;
	complex = Complex(A, B);
	return in;
}