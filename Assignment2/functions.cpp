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