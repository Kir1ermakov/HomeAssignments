// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment2a

#include <iostream>
#include "header.h"

using namespace std;
void reverseArray(char* arr, int size)
{
    for(int i = 0; i < size / 2; ++i)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;
    }
}

int precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }
    else if (op == '*' || op == '/')
    {
        return 2;
    }
    return 0;
}

bool isOperator(char c)
{
    return c == '+' || c == '-' || c == '*' || c == '/';
}

int do_operation(int num1, int num2, char operation)
{
    switch (operation)
    {
        case '+':
            return(num1 + num2);
            break;
        case '-':
            return(num1 - num2);
            break;
        case '*':
            return(num1 * num2);
            break;
        case '/':
            return(num1 / num2);
            break;
        default: 
            std::cout << "x is undefined" << "\n";
    }
    return 0;
}