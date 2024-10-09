// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Assignment2a

#include <iostream>
#include <fstream>
#include <filesystem>

int main()
{
    std::ifstream inFile;
    inFile.open("in_example.txt", std::ios::binary);

    std::filesystem::path filePath = "in_example.txt";
    std::int size;
    size = std::filesystem::file_size(filePath);

    char* buffer = new char[fileSize];

    inFile.read(buffer, fileSize);

    void reverseArray(char* arr, int size)
    {
        for(int i = 0; i < size / 2; ++i)
        {
            int temp = arr[i];
            arr[i] = arr[size - 1 - i];
            arr[size - 1 - i] = temp;
        }
    }

    std::ofstream outFile;
    outFile.open("out_example.txt", std::ios::binary);
    outFile.write(buffer, fileSize);

    inFile.close();
    outFile.close();

    delete[] buffer;

    return 0;
}