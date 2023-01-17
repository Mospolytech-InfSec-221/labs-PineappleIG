#include "Square.h"


using namespace std;

Square::Square()
{
	this->side = 0;
	cout << "Square()\n";
}
Square::Square(double a, int x, int y):Position(x, y)
{
	this->side = a;
	cout << "Square(double a)\n";
}
double Square::SquareP(double a)
{
	return a * 4;
	cout << "SquareP(double a)\n";
}

double Square::SquareS(double a)
{
	return a * a;
	cout << "SquareS(double a)\n";
}

Square::~Square()
{
	cout << "~Square()\n";
}