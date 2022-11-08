#include <iostream>
using namespace std;
const int SIZE = 1000;
int len = 0;

void MergeConnect(int arr[], int start, int end)
{
    int i = start;
    int middle = start + (end - start) / 2;
    int j = middle + 1;
    int k = 0;
    int temp_arr[SIZE];

    while (i <= middle && j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp_arr[k] = arr[i];
            i++;
        }
        else
        {
            temp_arr[k] = arr[j];
            j++;
        }
        k++;
    }

    while (i <= middle)
    {
        temp_arr[k] = arr[i];
        i++; k++;
    }

    while (j <= end)
    {
        temp_arr[k] = arr[j];
        j++; k++;
    }

    for (i = 0; i < k; i++)
    {
        arr[start + i] = temp_arr[i];
    }
}

void MergeSort(int arr[], int Left, int Right)
{
    //Проверка что в массиве 1> элемента
    if (Left < Right)
        if (Right - Left == 1)
        {
            if (arr[Left] > arr[Right])
            {
                swap(arr[Left], arr[Right]);
            }
        }
        else
        {
            MergeSort(arr, Left, Left + (Right - Left) / 2);
            MergeSort(arr, Left + (Right - Left) / 2 + 1, Right);
            MergeConnect(arr, Left, Right);
        }
}

void bubble(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int k = 0; k < len - 1 - i; k++)
        {
            if (arr[k] > arr[k + 1])
            {
                swap(arr[k], arr[k + 1]);
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
}

void SortCount(char arr[], int len)
{
    int COUNT[26] = { 0 };
    int c;
    for (int i = 0; i < len; i++)
    {
        c = int(arr[i] - 97);
        COUNT[c]++;
    }
    int i = 0;
    c = 0;
    while (c < 26)
    {
        if (COUNT[c] > 0)
        {
            arr[i] = char(int(97 + c));
            i++;
            COUNT[c]--;
        }
        else
        {
            c++;
        }
    }
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
}

void arr_int1()
{
    int arr[SIZE]{ 0 };
    cout << "Введите длину массива\n";
    cin >> len;
    cout << "Введите переменную массива\n";
    for (int j = 0; j < len; j++)
    {
        cin >> arr[j];
    }
    cout << "Отсортированный массив\n";
    bubble(arr, len);
}

void arr_int2()
{
    int arr[SIZE]{ 0 };
    cout << "Введите длину массива\n";
    cin >> len;
    cout << "Введите переменную массива\n";
    for (int j = 0; j < len; j++)
    {
        cin >> arr[j];
    }
    cout << "Отсортированный массив\n";
    MergeSort(arr, 0, len - 1);

    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }
}

void arr_char()
{
    char arr[SIZE]{ 0 };
    cout << "Введите длину массива\n";
    cin >> len;
    cout << "Введите переменную массива\n";
    for (int j = 0; j < len; j++)
    {
        cin >> arr[j];
    }
    cout << "Отсортированный массив\n";
    SortCount(arr, len);
}

void main()
{
    setlocale(LC_ALL, "ru");
    int chose;
    int size;

    cout << "Выберите сортировку\n" << "1) Сортировка числового массива пузырьком\n" << "2) Сортировка символьного массива подсчётом\n" << "3) Сортировка числового массива слиянием\n";
    cin >> chose;

    switch (chose)
    {
    case 1:

        arr_int1();
        break;
    case 2:
        arr_char();
        break;
    case 3:
        arr_int2();
        break;
    default:
        cout << "Некорректные ввод" << endl;
        break;
    }
}
