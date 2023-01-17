#include "matrix.h"

using std::endl;
using std::cin;
using std::cout;

Matrix::Matrix()
{
    this -> rows = 0;
    this -> cols = 0;
    this -> elems = nullptr;
}
Matrix::Matrix(int i, int j)
{
    this -> rows = i;
    this -> cols = j;
    this -> elems = nullptr;
}
Matrix::Matrix(int i, int j, const double* arr)
{
    this -> rows = i;
    this -> cols = j;
    this -> elems = new double[this->rows * this->cols];
    for (int k = 0; i < this->rows; k++)
    {
        for (int p = 0; j < this->cols; p++)
        {
            this -> elems[i * this->cols + j] = arr[i * this->cols + j];
        }
    }
}
Matrix::Matrix(const Matrix& temp)
{
    this -> cols = temp.cols;
    this -> rows = temp.rows;
    this -> elems = new double[this->rows * this->cols];
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols; j++)
        {
            this -> elems[i * this->cols + j] = temp.elems[i * this->cols + j];
        }
    }
}

Matrix::~Matrix()
{
    if (this->elems != nullptr)
        delete[] this->elems;
}

void Matrix::input()
{
    int nrows, ncols;
    cout << "Enter number of rows: ";
    cin >> nrows;
    cout << "Enter number of cols: ";
    cin >> ncols;
    this -> rows = nrows;
    this -> cols = ncols;
    if (this -> elems != nullptr) delete[]this->elems;
    this -> elems = new double[this->rows * this->cols];
    for (int i = 0; i < nrows; i++)
    {
        for (int j = 0; j < ncols; j++)
        {
            double temp = 0;
            cout << "Enter element of matrix" << "[" << i << "]" << "[" << j << "]" << ": ";
            cin >> temp;
            this -> elems[i * this->cols + j] = temp;
        }
    }
}
void Matrix::input(int i, int j)
{
    this -> rows = i;
    this -> cols = j;
    if (this -> elems != nullptr) delete[]this->elems;
    this -> elems = new double[this->rows * this->cols];
    for (int i = 0; i < this -> rows; i++)
    {
        for (int j = 0; j < this -> cols; j++)
        {
            double temp = 0;
            cout << "Enter element of matrix" << "[" << i << "]" << "[" << j << "]" << ": ";
            cin >> temp;
            this -> elems[i * this->cols + j] = temp;
        }
    }
}
void Matrix::input(int i, int j, double * arr)
{
    this -> rows = i;
    this -> cols = j;
    if (this -> elems != nullptr) delete[]this->elems;
    this -> elems = new double[this->rows * this->cols];
    for (int i = 0; i < this -> rows; i++)
    {
        for (int j = 0; j < this -> cols; j++)
        {
            this -> elems[i * this->cols + j] = arr[i * this->cols + j];
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
            cout << this -> elems[i * this->cols + j] << "\t";
        }
        cout << endl;
    }
}

int Matrix::get_columns()
{
    return this -> cols;
}

int Matrix::get_rows()
{
    return this -> rows;
}

double Matrix::get_elem(int i, int j)
{
    return this -> elems[i * this -> cols + j];
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
                this -> elems[i*cols + j] = 0;
                for (int k = 0; k < mult_matrix1.cols; k++)
                this -> elems[i*cols + j] +=  mult_matrix1.elems[i * mult_matrix1.cols + k] * mult_matrix2.elems[k * mult_matrix2.cols + j];
            }
        }
    }
    else
    {
        cout << "Error" << endl;
        return 0;
    }
     return 1;
}

bool Matrix::mult(const Matrix& mult_matrix1, const double * arr, int size)
{
    if (mult_matrix1.cols * mult_matrix1.rows == size)
    {
        //int cols_arr = size % mult_matrix1.rows;
        this->rows = mult_matrix1.rows;
        if (this->elems != nullptr) delete[]this->elems;
        this->elems = new double[this->rows * this->cols];
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                this -> elems[i*cols + j] = 0;
                for (int k = 0; k < mult_matrix1.cols; k++)
                this -> elems[i*cols + j] +=  mult_matrix1.elems[i * mult_matrix1.cols + k] * arr[k * mult_matrix1.cols + j];
            }
        }
    }
    else
    {
        cout << "Error" << endl;
        return 0;
    }
     return 1;
}

bool Matrix::sum(const Matrix& sum_matrix1, const Matrix& sum_matrix2)
{
    if (sum_matrix1.rows == sum_matrix2.rows && sum_matrix1.cols == sum_matrix2.cols)
    {
        this->rows = sum_matrix1.rows;
        this->cols = sum_matrix2.cols;
        if (this->elems != nullptr) delete[]this->elems;
        this->elems = new double[this->rows * this->cols];
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                this -> elems[i * this -> cols + j] = sum_matrix1.elems[i * sum_matrix1.cols + j] + sum_matrix2.elems[i * sum_matrix2.cols + j];
            }
        }
    }
    else
    {
        return 0;
    }
    return 1;
}
bool Matrix::sum(const Matrix& sum_matrix1, const double * arr, int size)
{
    if (sum_matrix1.cols * sum_matrix1.rows == size)
    {
        this->rows = sum_matrix1.rows;
        this->cols = sum_matrix1.cols;
        if (this->elems != nullptr) delete[]this->elems;
        this->elems = new double[this->rows * this->cols];
        for (int i = 0; i < this->rows; i++)
        {
            for (int j = 0; j < this->cols; j++)
            {
                this -> elems[i * this -> cols + j] = sum_matrix1.elems[i * sum_matrix1.cols + j] + arr[i * sum_matrix1.cols  + j];
            }
        }
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
            this -> elems[i * this -> cols + j] = elems[i * this -> cols + j] * num;
        }
    }
}

double Matrix::trace()
{
    if (this->rows != this->cols)
    {
        return 0;
    }
    double sum_trace = 0;
    for (int i = 0; i < this->rows; i++)
    {
        for (int j = 0; j < this->cols;j++)
        {
            if (i == j)
            {
                sum_trace = sum_trace + this->elems[i * this->cols + j];
            }
        }
    }
    return sum_trace;
}

Matrix operator+ (const Matrix& sum_matrix1, const Matrix& sum_matrix2)
{
    Matrix res(sum_matrix1);
    res.sum(sum_matrix1, sum_matrix2);
    //cout << res.get_elem(0,0);
    return res;
}
Matrix operator- (const Matrix& sum_matrix1, const Matrix& sum_matrix2)
{
    return sum_matrix1 + sum_matrix2 * (-1);
}

void Matrix::operator+= (const Matrix& temp)
{
    Matrix res(temp);
    res.mult_by_num(-1);
    this->sum(Matrix(this -> cols,this -> rows,this -> elems), res);

}

void Matrix::operator-= (const Matrix& temp)
{
    this->sum(Matrix(this -> cols,this -> rows,this -> elems), temp);
}
void Matrix::operator= (const Matrix& temp)
{
    input(temp.cols, temp.rows, temp.elems);
}
Matrix operator* (const Matrix& temp, double num)
{
    Matrix res(temp);
    res.mult_by_num(num);
    return res;
}

Matrix operator* (const Matrix& sum_matrix1, const Matrix& sum_matrix2)
{
    Matrix res1(sum_matrix1);
    res1.mult(sum_matrix1, sum_matrix2);
    return res1;
}
