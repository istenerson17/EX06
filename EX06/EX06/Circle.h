#ifndef CIRCLE_H
#define CIRCLE_H
using namespace std;

class Circle
{
private:
	double radius;
	static int numberOfObjects;
public:
	Circle();
	Circle(double);
	double getArea() const;
	double getRadius() const;
	void setRadius(double);
	static int getNumberOfObjects();
	bool operator< (Circle &c);
	bool operator> (Circle &c);
	bool operator== (Circle &c);
	bool operator<= (Circle &c);
	bool operator>= (Circle &c);
	bool operator!= (Circle &c);

	void operator= (Circle &c);
	Circle& operator+ (Circle &c);
};
#endif