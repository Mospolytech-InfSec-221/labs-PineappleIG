#include "matrix.h"
#include <iostream>
using namespace std;


int main()
{
	Matrix A, B, C;
	A.input();
	A.print();
	if (A.get_columns() == A.get_rows())
	{
		cout << "Matrix Trace: ";
		cout << A.trace();
		cout << endl;
	}
	B.input();
	B.print();
	if (C.mult(A, B))
	{
		cout << "Matrix Mult: ";
		cout << endl;
		C.print();
	}
	if (C.sum(A, B))
	{
		cout << "Matrix Sum: ";
		cout << endl;
		C.print();
	}
	
	double num = 0;
	cout << "Enter number: ";
	cin >> num;

	C.mult_by_num(num);
	C.print();
	
}