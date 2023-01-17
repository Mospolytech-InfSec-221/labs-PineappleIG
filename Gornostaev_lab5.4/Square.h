#pragma once
#include <iostream>
#include "Position.h"

class Square: virtual public Position
{
	private:
		int side;
	public:
		Square();
		Square(double a, int x, int y);
		double SquareP(double a);
		double SquareS(double a);
		~Square();
};
