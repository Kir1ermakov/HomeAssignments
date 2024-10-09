// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment2a

#include <iostream>
#include <fstream>
#include <filesystem>
#include "header.h"
#include <string>
#include <cctype>
#include <stack>
int main()
{
    std::ifstream inFile;
    inFile.open("in_example.txt", std::ios::binary);

    std::filesystem::path filePath = "in_example.txt";
    int fileSize;
    fileSize = std::filesystem::file_size(filePath);

    char* buffer = new char[fileSize];

    inFile.read(buffer, fileSize);

    reverseArray(buffer, fileSize);

    std::ofstream outFile;
    outFile.open("out_example.txt", std::ios::binary);
    outFile.write(buffer, fileSize);

    inFile.close();
    outFile.close();

    delete[] buffer;


//Assignment2b

    std::ifstream infile;
    infile.open("math_example.txt", std::ios::in);

    std::string infix;
    std::getline(infile, infix);

    infile.close();

    std::stack<char> stack;
    std::string postfix;

    int infix_l = infix.length();

    for (int i = 0; i < infix_l; ++i)
    {
        char c = infix[i];
    
        if (isspace(c))
        {
            continue;
        }

        if (isdigit(c))
        {
            postfix += c;
        }

        else if (c == '(')
        {
            stack.push(c);
        }

        else if (c == ')')
        {
            while (!stack.empty() && stack.top() != '(')
            {
                postfix += stack.top();
                stack.pop();
            }
            if (!stack.empty() && stack.top() == '(')
            {
                stack.pop();
            }
        }

        else if (isOperator(c))
        {
            while (!stack.empty() && precedence(stack.top()) >= precedence(c))
            {
                postfix += stack.top();
                stack.pop();
            }

            stack.push(c);
        }
    }

    while (!stack.empty())
    {
        postfix += stack.top();
        stack.pop();
    }



    std::stack<int> stack_c;
    int a, b;
    int postfix_l = postfix.length();

    for (int i = 0; i < postfix_l; ++i)
    {
        char e = postfix[i];

        if (isdigit(e))
        {
            stack_c.push((int)e - '0');
        }

        if (isOperator(e))
        {
            b = stack_c.top();
            stack_c.pop();
            a = stack_c.top();
            stack_c.pop();
            stack_c.push(do_operation(a, b, e));
        }
    }

    int answer = stack_c.top();
    stack_c.pop();

    std::cout << "\nAnswer for assignment2b:\n" << infix << " = " << postfix << " = " << answer;

    return 0;
}