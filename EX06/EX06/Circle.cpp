#include "Circle.h"
using namespace std;

int Circle::numberOfObjects = 0;

Circle::Circle()
{
	radius = 1;
	numberOfObjects++;
}

Circle::Circle(double radius)
{
	this->radius = radius;
	numberOfObjects++;
}

double Circle::getArea() const
{
	return radius * radius * 3.14159;
}

double Circle::getRadius() const
{
	return radius;
}

void Circle::setRadius(double radius)
{
	this->radius = (radius >= 0) ? radius : 0;
}

int Circle::getNumberOfObjects()
{
	return numberOfObjects;
}

bool Circle::operator< (Circle &c)
{
	if (radius < c.getRadius()){
		return true;
	}
	else
		return false;
}

bool Circle::operator<= (Circle &c)
{
	return (radius <= c.getRadius() ? true : false);
}

bool Circle::operator== (Circle &c)
{
	return (radius == c.getRadius() ? true : false);
}

bool Circle::operator!= (Circle &c)
{
	return (radius != c.getRadius() ? true : false);
}

bool Circle::operator> (Circle &c)
{
	return (radius > c.getRadius() ? true : false);
}

bool Circle::operator>= (Circle &c)
{
	return (radius >= c.getRadius() ? true : false);
}

void Circle::operator= (Circle &c)
{
	radius = c.getRadius();
}

Circle& Circle::operator+ (Circle &c)
{
	radius += c.getRadius();
	return *this;
}