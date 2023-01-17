#include <iostream>
class Matrix
{
private:
    int rows, cols;
    double* elems;

    void resize(int nrows, int ncols);
public:
    Matrix();
    Matrix(int i, int j);
    Matrix(int i, int j, const double* arr);

    void input();
    void input(int i, int j);
    void input(int i, int j, double* arr);

    void print();
    double get_elem(int i, int j);
    
    bool sum(const Matrix& sum_matrix1, const Matrix& sum_matrix2);
    bool sum(const double* arr, int size, const Matrix& sum_matrix1);

    bool mult(const Matrix& mult_matrix1, const Matrix& mult_matrix2);
    bool mult(const double* arr, int size, const Matrix& mult_matrix1);

    double trace();
    double det();
    void mult_by_num(double num);
    int get_columns();
    int get_rows();

    ~Matrix();
};