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
    Matrix(const Matrix& temp);

    void input();
    void input(int i, int j);
    void input(int i, int j, double * arr);
    void print();
    double get_elem(int i, int j);
    bool sum(const Matrix& sum_matrix1, const Matrix& sum_matrix2);
    bool sum(const Matrix& sum_matrix1, const double * arr, int size);
    bool mult(const Matrix& mult_matrix1, const Matrix& mult_matrix2);
    bool mult(const Matrix& mult_matrix1, const double * arr, int size);
    double trace();
    double det();
    void mult_by_num(double num);
    int get_columns();
    int get_rows();
    void operator-= (const Matrix& temp);
    void operator+= (const Matrix& temp);
    void operator= (const Matrix& temp);
    friend std::ofstream& operator<< (std::ofstream& out, Matrix& temp);
    friend std::ifstream& operator>> (std::ifstream& in, Matrix& temp);

    ~Matrix();
};

Matrix operator+ (const Matrix& sum_matrix1, const Matrix& sum_matrix2);
Matrix operator* (const Matrix& sum_matrix1, double num);
Matrix operator* (const Matrix& sum_matrix1, const Matrix& sum_matrix2);
Matrix operator- (const Matrix& sum_matrix1, const Matrix& sum_matrix2);
