#include "Position.h"

using namespace std;

Position::Position()
{
	this->x = 0;
	this->y = 0;
	cout << "Position()\n";
}

Position::Position(int i,int j)
{
	this->x = i;
	this->y = j;
	cout << "Position(int i, ing j)\n";
}

void Position::ChangePosition()
{
	int newx, newy;
	cout << "Change coordinates" << endl << "x = ";
	cin >> newx;
	cout << "y = ";
	cin >> newy;
	this->x = newx;
	this->y = newy;
	cout << "change_position()\n";
}

void Position::ChangePosition(int i, int j)
{
	this->x = i;
	this->y = j;
	cout << "change_position(int i, int j)\n";
}

Position::~Position() 
{
	cout << "~Position()\n";
}
