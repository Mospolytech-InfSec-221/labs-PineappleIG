#include <iostream>
#include <float.h>
#include <windows.h>
using namespace std;
HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

void task1(int* arr, int len)
{
	cout << "\n";
	SetConsoleTextAttribute(handle, FOREGROUND_RED);
	cout << "Введите элементы массива\n";
	for (int i = 0; i < len; i++)
	{
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
		cin >> arr[i];
	}
	cout << "\n";
}

void task2(int* arr, int len)
{
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
	cout << "\n";
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << endl;
	}
	cout << "\n";
}

void task3(int* arr, int len)
{
	int* copy_arr = new int[len], q, w, e, t1, t2;

	for (int i = 0;i < len;i++)
	{
		copy_arr[i] = arr[i];
	}

	for (int d = 0;d < len;d++)
	{
		q = 0;
		while (copy_arr[d] != 0)
		{
			copy_arr[d] = copy_arr[d] / 10;
			q = q + copy_arr[d] % 10;
			copy_arr[d] = copy_arr[d] / 10;
		}
		copy_arr[d] = q;
	}

	for (w = 0;w < len;w++)
	{
		for (e = 0;e < len - w - 1;e++)
		{
			if (copy_arr[e] > copy_arr[e + 1])
			{
				t1 = copy_arr[e + 1];
				copy_arr[e + 1] = copy_arr[e];
				copy_arr[e] = t1;
				t2 = arr[e + 1];
				arr[e + 1] = arr[e];
				arr[e] = t2;
			}
		}
	}
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
	cout << "\n" << "Сортировка выполнена\n" << "\n";
}

void task4(int* arr, int len)
{
	int* copy_arr = new int[len], w, e, t1, t2;

	for (int i = 0;i < len;i++)
	{
		copy_arr[i] = arr[i] % 10;
	}

	for (w = 0;w < len;w++)
	{
		for (e = 0;e < len - w - 1;e++)
		{
			if (copy_arr[e] > copy_arr[e + 1])
			{
				t1 = copy_arr[e + 1];
				copy_arr[e + 1] = copy_arr[e];
				copy_arr[e] = t1;
				t2 = arr[e + 1];
				arr[e + 1] = arr[e];
				arr[e] = t2;
			}
		}
	}

	for (w = 0;w < len;w++)
	{
		for (e = 0;e < len - w - 1;e++)
		{
			if (copy_arr[e] == copy_arr[e + 1] && arr[e] < arr[e + 1])
			{
				t1 = copy_arr[e];
				copy_arr[e] = copy_arr[e + 1];
				copy_arr[e + 1] = t1;
				t2 = arr[e];
				arr[e] = arr[e + 1];
				arr[e + 1] = t2;
			}
		}
	}
	SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
	cout << "\n" << "Сортировка выполнена\n" << "\n";
}

int main()
{
	SetConsoleTextAttribute(handle, FOREGROUND_RED);
	setlocale(LC_ALL, "rus");
	cout << "Введите длину массива\n";
	SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
	int len = 1;
	cin >> len;
	cout << "\n";
	int* arr = nullptr;
	arr = new int[len];
	int* copy_arr = new int[len], q, w, e, t1, t2;
	while (true)
	{
		SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
		cout << "1) Ввод массива\n" << "2) Вывод массива\n" << "3) Сортировка по сумме цифр, стоящих на чётных местах\n" << "4) Сортировка по возрастанию и убыванию\n" << "5) Выход\n" << "\n";
		int c = 0;
		SetConsoleTextAttribute(handle, FOREGROUND_BLUE);
		cin >> c;
		switch (c)
		{
		case 1:
			task1(arr, len);
			break;
		case 2:
			task2(arr, len);
			break;
		case 3:
			task3(arr, len);
			break;
		case 4:
			task4(arr, len);
			break;
		case 5:
			delete[] arr;
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
			return 0;
		default:
			SetConsoleTextAttribute(handle, FOREGROUND_RED);
			cout << "Некорректный ввод\n";
			SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
			delete[] arr;
			return 0;
		}
	}
}
