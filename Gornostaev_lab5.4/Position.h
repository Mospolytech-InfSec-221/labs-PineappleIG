#pragma once
#include <iostream>

class Position
{
	private:
		int x, y;
	public:
		Position();
		Position(int x,int y);
		void ChangePosition();
		void ChangePosition(int x,int y);
		~Position();
};