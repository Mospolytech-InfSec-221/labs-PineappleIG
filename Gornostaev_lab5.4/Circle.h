#pragma once
#include <iostream>
#include "Position.h"

class Circle : virtual public Position
{
	private:
		double r;
	public:
		Circle();
		Circle(double rad, int x, int y);
		double CircleP(double rad);
		double CircleS(double rad);
		~Circle();
};
