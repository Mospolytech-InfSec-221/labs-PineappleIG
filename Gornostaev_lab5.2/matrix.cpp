#include "matrix.h"
#include <iostream>
using namespace std;


int main()
{
	double arr[] = {1,2,3,4,5,6,7,8,9};
	int i = 3;
	int j = 3;
	int size = i * j;
	Matrix A, B, C;
	A.input(i,j);
	B.input(i, j, arr);

	A.print();
	B.print();

	if (C.sum(arr, size, A))
	{
		C.print();
	}

	if (C.mult(arr, size, A))
	{
		C.print();
	}

	/*Matrix A, B, C;
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
	C.print();*/
	
}