#include "Circle.h"


using namespace std;

Circle::Circle()
{
	this->r = 0;
	cout << "Circle()\n";
}

Circle::Circle(double rad, int x, int y):Position(x, y)
{
	this->r = rad;
	cout << "Circle(double rad)\n";
}

double Circle::CircleP(double rad)
{
	return 3,14 * r * 2;
	cout << "CircleP(double rad)\n";
}

double Circle::CircleS(double rad)
{
	return  3,14 * r * r;
	cout << "CircleS(double rad)\n";
}

Circle::~Circle()
{
	cout << "~Circle()\n";
}