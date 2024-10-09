// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment2a

#include <iostream>
#include <fstream>
#include <filesystem>
#include "header.h"

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

    return 0;
}