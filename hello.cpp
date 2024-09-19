// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Задача 1 "Hello, world! V. 2.0"


#include <iostream>
#include "hello.h"

using namespace std;

void print_hello(){
    cout << "Hello, World!\n";
}

void print_hello(std::string x){
    printf("\nHello, %s!\n", x.c_str());
}