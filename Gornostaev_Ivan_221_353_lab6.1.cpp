// Gornostaev_Ivan_221_353_lab6.1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool stackcheck(string& str)
{
    stack <char> s;
    double len = 0;
    len = str.length();
    if ((str[0] == ')' or str[0] == ']' or str[0] == '}'))
    {
        return 0;
    }
    for (int i = 0; i < len; i++)
    {
        
        if (str[i] == '(' or str[i] == '[' or str[i] == '{')
        {
            s.push(str[i]);
        }
        if (str[i] == ')')
        {
            if (s.top() == '(') s.pop();
            else return 0;
        }
        if (str[i] == ']')
        {
            if (s.top() == '[') s.pop();
            else return 0;
        }
        if (str[i] == '}')
        {
            if (s.top() == '{') s.pop();
            else return 0;
        }
    }
    if (s.empty()) return 1;
    else return 0;
}

int main()
{
    string str;
    cout << "Enter string: ";
    getline(cin, str);
    bool check = stackcheck(str);
    if (check != 0) 
    {
        cout << "Good" << endl;
    }
    else
    {
        cout << "Error" << endl;
    }
    return 0;
}
