#include "Circle_in_square.h"

using namespace std;

Circle_in_square::Circle_in_square()
{
	cout << "Circle_in_Square()\n";
};

Circle_in_square::Circle_in_square(int x, int y, double side, double r) : Square(side, x, y), Circle(r, x, y), Position(x, y) 
{
	cout << "Circle_in_Square(int x, int y, double side, double r)\n";
};

Circle_in_square::~Circle_in_square() 
{
	cout << "~Circle_in_Square\n";
};