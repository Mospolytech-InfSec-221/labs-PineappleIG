#include <iostream>
using namespace std;
int n;

void func1()
{
	cin >> n;
	cout << endl;
	for (int count1 = 0; count1 <= n; count1++)
	{
		cout << endl;
		for (int count2 = 0; count2 <= count1; count2++)
		{
			cout << " ";
			cout << count2;
		}
	}
	cout << endl;
}

void func2()
{
	int x, y;
	cin >> x;
	y = x;
	for (int k = 1; k <= x; k++)
	{
		cout << k << ')' << y << endl;
		y *= (x - k);
		y /= (k + 1);
	}
	cout << endl;
}

void func3()
{
	double A, B, sum = 0, amount = 0;
	cin >> A >> B;
	cout << endl;
	for (A; A <= B; A++)
	{
		sum = sum + A;
		amount++;
	}
	cout << sum / amount;
	cout << endl;
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int choice = 0;
	while (true)
	{
		cout << "Что вы хотите выполнить? \n" << "Задание 1 \n" << "Задание 2 \n" << "Задание 3 \n" << "Выход" << endl;
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Выбрано задание 1" << endl;
			func1();
			break;
		}
		case 2:
		{
			cout << "Выбрано задание 2" << endl;
			func2();
			break;
		}
		case 3:
		{
			cout << "Выбрано задание 3" << endl;
			func3();
			break;
		}
		default:
		{
			return 0;
		}


		}
	}
}

