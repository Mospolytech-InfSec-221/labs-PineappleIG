#include "matrix.h"

using namespace std;

Matrix::Matrix()
{
	this->rows = 0;
	this->cols = 0;
	this->elems = nullptr;
}

Matrix::Matrix(int i, int j)
{
	this->rows = i;
	this->cols = j;
	this->elems = nullptr;
}

Matrix::Matrix(int i, int j, const double* arr)
{
	this->rows = i;
	this->cols = j;
	this->elems = new double[this->rows * this->cols];
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				this->elems[i * this->cols + j] = arr[i * this->cols + j];
			}
		}
}

Matrix::~Matrix()
{
	if (elems != nullptr) delete[] elems;
}

void Matrix::input()
{
	int nrows, ncols;
	cout << "Enter the number of rows: ";
	cin >> nrows;
	cout << "Enter the number of cols: ";
	cin >> ncols;
	this->rows = nrows;
	this->cols = ncols;
	if (this->elems != nullptr) delete[] this->elems;
	this->elems = new double[this->rows * this->cols];
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			double s = 0;
			cout << "Enter element of matrix" << "[" << i << "]" << "[" << j << "]" << ": ";
			cin >> s;
			this->elems[i * this->cols + j] = s;
		}
	}
}

void Matrix::input(int i, int j)
{
	this->rows = i;
	this->cols = j;
	if (this->elems != nullptr) delete[] this->elems;
	this->elems = new double[this->rows * this->cols];
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			double s = 0;
			cout << "Enter element of matrix" << "[" << i << "]" << "[" << j << "]" << ": ";
			cin >> s;
			this->elems[i * this->cols + j] = s;
		}
	}
}

void Matrix::input(int i, int j, double* arr)
{
	this->rows = i;
	this->cols = j;
	this->elems = new double[this->rows * this->cols];
	if (this->elems != nullptr) delete[] this->elems;
	this->elems = new double[this->rows * this->cols];
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			this->elems[i * this->cols + j] = arr[i * this->cols + j];
		}
	}
}

void Matrix::print()
{
	cout << "Matrix: " << endl;
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			cout << this->elems[i * this->cols + j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

double Matrix::get_elem(int i, int j)
{
	return this->elems[i * this->cols + j];
}

int Matrix::get_columns()
{
	return this->cols;
}

int Matrix::get_rows()
{
	return this->rows;
}

bool Matrix::mult(const Matrix& mult_matrix1, const Matrix& mult_matrix2)
{
	if (mult_matrix1.cols == mult_matrix2.rows)
	{
		this->rows = mult_matrix1.rows;
		this->cols = mult_matrix2.cols;
		if (this->elems != nullptr) delete[]this->elems;
		this->elems = new double[this->rows * this->cols];
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				this->elems[i * cols + j] = 0;
				for (int x = 0; x < mult_matrix1.cols; x++)
					this->elems[i * cols + j] += mult_matrix1.elems[i * mult_matrix1.cols + x] * mult_matrix2.elems[x * mult_matrix2.cols + j];
			}
			cout << endl;
		}
		cout << endl;
	}
	else
	{
		return 0;
	}
	return 1;
}

bool Matrix::mult(const double* arr, int size, const Matrix& mult_matrix1)
{
	if (size == mult_matrix1.rows * mult_matrix1.cols)
	{
		this->cols = mult_matrix1.cols;
		this->rows = mult_matrix1.rows;
		if (this->elems != nullptr) delete[] this->elems;
		this->elems = new double[this->rows * this->cols];
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				this->elems[i * cols + j] = 0;
				for (int x = 0; x < this -> cols; x++)
					this->elems[i * this->cols + j] += mult_matrix1.elems[i * this -> cols + x] * arr[x * this -> cols + j];
			}
			cout << endl;
		}
		cout << endl;
	}
	else
	{
		return 0;
	}
	return 1;
}

bool Matrix::sum(const Matrix& sum_matrix1, const Matrix& sum_matrix2)
{
	if (sum_matrix1.rows == sum_matrix2.rows && sum_matrix1.cols == sum_matrix2.cols)
	{
		this->rows = sum_matrix1.rows;
		this->cols = sum_matrix1.cols;
		if (this->elems != nullptr) delete[] this->elems;
		this->elems = new double[this->rows * this->cols];	
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				this->elems[i * cols + j] = 0;
				this->elems[i * cols + j] += sum_matrix1.elems[i * sum_matrix1.cols + j] + sum_matrix2.elems[i * sum_matrix2.cols + j];
			}
			cout <<  endl;
		}
		cout  << endl;
	}
	else
	{
		return 0;
	}
}

bool Matrix::sum(const double* arr, int size, const Matrix& sum_matrix1)
{
	if (size == sum_matrix1.cols * sum_matrix1.rows)
	{
		this->cols = sum_matrix1.cols;
		this->rows = sum_matrix1.rows;
		if (this->elems != nullptr) delete[] this->elems;
		this->elems = new double[this->rows * this->cols];
		for (int i = 0; i < this->rows; i++)
		{
			for (int j = 0; j < this->cols; j++)
			{
				this->elems[i * this ->cols + j] = sum_matrix1.elems[i * this -> cols + j] + arr[i * this -> cols + j];
			}
			cout << endl;
		}
		cout << endl;
	}
	else
	{
		return 0;
	}
	return 1;
}

void Matrix::mult_by_num(double num)
{
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			this -> elems[i * this -> cols + j] = this -> elems[i * this -> cols + j] * num;
		}
		cout << endl;
	}
	cout << endl;

}

//double Matrix::det()
//{
//
//}

double Matrix::trace()
{
	double trace = 0;
	for (int i = 0; i < this->rows; i++)
	{
		for (int j = 0; j < this->cols; j++)
		{
			if (i == j)
			{
				trace += this->elems[i * cols + j];
			}
		}
	}
	return trace;
}