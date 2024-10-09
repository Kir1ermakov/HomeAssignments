// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Задача 1 "Hello, world! V. 2.0"


#include <iostream>
#include "hello.h"

using namespace std;

int main(){
    string say, say_p;
    bool flag;

    flag = true;

    print_hello();
    cout << "Введите имя:";
    getline(cin, say);

    while (flag){
        say_p = say;
        print_hello(say);
        cout << "\nЕсли хотите закончить, введите 'Goodbye'.\nВведите имя:";
        getline(cin, say);
        
        if (say == "goodbye" || say == "Goodbye"){
            flag = false;
            printf("\nGoodbye, %s!", say_p.c_str());
        }
         
    }
    return 0;
}