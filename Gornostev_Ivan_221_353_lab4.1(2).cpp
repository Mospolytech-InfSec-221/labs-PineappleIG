#include <iostream> 
#include <cstring>
#include <stdio.h>
#include <windows.h>

using namespace std;




bool Palindrom(char* str)
{
    int len = strlen(str);
    int j = 0;
    for (int i = 0, j = len - 1; i < j; i++, j--)
    {
        if (str[i] == ' ')
        {
            i++;
        }
        if (str[j] == ' ')
        {
            j--;
        }
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] - 'A' + 'a';
        }
        if (str[j] >= 'A' && str[j] <= 'Z')
        {
            str[j] = str[j] - 'A' + 'a';
        }
        if (str[i] != str[j])
        {
            return false;
        }
    }
    return true;
}

void task1()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    char str[255];
    cout << "Введите строчку: ";
    cin.ignore();
    cin.getline(str, 255);
    if (Palindrom(str))
    {
        SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
        cout << "Палиндром" << endl;
    }
    else
    {
        SetConsoleTextAttribute(handle, FOREGROUND_RED);
        cout << "Не Палиндром" << endl;
    }
}

int sub1_search(const char* dop_str, const char* substring, int start)
{
    int len = strlen(substring);
    int s = 0;
    for (int i = start; i < start + len; i++, s++)
    {
        if (dop_str[i] != substring[s])
        {
            return 1;
        }

    }
    return start;
}

void sub2_search(const char* dop_str, const char* substring)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    int len = strlen(dop_str);
    for (int i = 0; i <= len - 1; i++)
    {
        if (sub1_search(dop_str, substring, i) != 1)
        {
            SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
            cout << sub1_search(dop_str, substring, i) << " ";
        }
    }
    cout << endl;
}

void task2()
{
    char str[255];
    char substring[255];
    cout << "Введите строчку:";
    cin.ignore();
    cin.getline(str, 255);
    cout << "Введите подстрочку: ";
    cin.getline(substring, 255);
    sub2_search(str, substring);
}

void encrypt(char* dop_str, int key)
{
    int len = strlen(dop_str);
    for (int i = 0; i < len; i++)
    {
        if (dop_str[i] != ' ')
        {
            if (dop_str[i] >= 'A' && dop_str[i] <= 'Z' || dop_str[i] >= 'a' && dop_str[i] <= 'z')
            {
                dop_str[i] = char(dop_str[i] + key);
                if (dop_str[i] > 'Z' && dop_str[i] < 'a')
                {
                    dop_str[i] = 'A' - 1 + key;
                }
                if (dop_str[i] > 'z')
                {
                    dop_str[i] = 'a' - 1 + key;
                }
            }
        }
        else
        {
            dop_str[i] == ' ';
        }
    }
    for (int j = 0; j < len; j++)
    {
        HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

        SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
        cout << dop_str[j];
    }
    cout << endl;
}

void task3()
{
    char str[255];
    int key = 0;
    cout << "Введите строчку:";
    cin.ignore();
    cin.getline(str, 255);
    cout << "Введите ключ:";
    cin >> key;
    encrypt(str, key);
}

void Oglavlenie(const char* str)
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);

    bool flag = false;
    int len, zahod = 1;
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == char(34))
        {
            if (flag == false)
            {
                flag = true;
                len = 0;
                int j = i + 1;
                while (str[j] != char(34))
                {
                    SetConsoleTextAttribute(handle, FOREGROUND_GREEN);
                    cout << str[j];
                    j++;
                    len++;
                }
            }
            else
            {
                flag = false;
            }
            cout << endl;
        }
    }
}

void task4()
{
    char str[255];
    cout << "Введите строчку:";
    cin.ignore();
    cin.getline(str, 255);
    Oglavlenie(str);
}

int main()
{
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    setlocale(LC_ALL, "rus");
    int c = 0;
    while (true)
    {
        SetConsoleTextAttribute(handle, FOREGROUND_RED);
        cout << "Выберите задачу\n";
        SetConsoleTextAttribute(handle, FOREGROUND_INTENSITY);
        cout << "1) Палиндром\n" << "2) Поиск подстрочки\n" << "3) Шифр Цезаря\n" << "4) Собственные\n" << "5) Выход\n";
        cin >> c;
        switch (c)
        {
        case 1:
        {
            task1();
            break;
        }
        case 2:
        {
            task2();
            break;
        }
        case 3:
        {
            task3();
            break;
        }
        case 4:
        {
            task4();
            break;
        }
        default:
        {
            return 0;
        }
        }
    }
}

