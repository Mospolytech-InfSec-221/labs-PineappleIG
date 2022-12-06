// Gornostaev_Ivan_221_353_lab6.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}

void task3(int* arr, int len)
{
	int* copy_arr = new int[len], q, w, e, t1, t2;

	for (int i = 0; i < len; i++)
	{
		copy_arr[i] = arr[i];
	}

	for (int d = 0; d < len; d++)
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

	for (w = 0; w < len; w++)
	{
		for (e = 0; e < len - w - 1; e++)
		{
			if (copy_arr[e] > copy_arr[e + 1])
			{
				t1 = copy_arr[e + 1];
				copy_arr[e + 1] = copy_arr[e];
			}
		}
	}
}
