#include <iostream>
#include "matrix.h"

using std::endl;
using std::cin;
using std::cout;


int main()
{
    Matrix Task1, Task2, Task3, Task4;
    double arr[9] = {-3,5,7,1,6,7,10,23,11};
    int cols = 3;
    int rows = 3;
    int size = cols * rows;


    Task1.input(cols, rows);
    Task1.print();

    Task2.input(cols, rows, arr);
    Task2.print();

    Task3 = Task1 + Task2;
    Task3.print();
    Task4 = Task1 - Task2;
    Task4.print();
    Task3 = Task1 * Task2;
    Task4= Task1 * 2;
    Task3.print();
    Task4.print();


















}
