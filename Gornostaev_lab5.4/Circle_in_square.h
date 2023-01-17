#pragma once
#include <iostream>
#include "Circle.h"
#include "Square.h"

class Circle_in_square : virtual public Square, virtual public Circle
{
public:
	Circle_in_square();
	~Circle_in_square();
	Circle_in_square(int x, int y, double side, double r);
};