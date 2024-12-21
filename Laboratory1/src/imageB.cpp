// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Laboratory1

#include "imageB.h"
#include <iostream>
#include <fstream>

Image loadBinGrayImage(const std::string& filename, int width, int height)
{
    std::ifstream file(filename, std::ios::binary | std::ios::ate);
    if (!file)
    {
        std::cerr << "Ошибка: файл не найден!" << std::endl;
        exit(1);
    }
    std::streamsize size = file.tellg();
    file.seekg(0, std::ios::beg);

    if (size != width * height)
    {
        std::cerr << "Ошибка: размер файла (" << size << " байт) не соответствует "
                  << width * height << " байт!" << std::endl;
        exit(1);
    }

    Image img;
    img.width = width;
    img.height = height;
    img.pixels.resize(height, std::vector<int>(width));

    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            unsigned char pixel;
            file.read(reinterpret_cast<char*>(&pixel), sizeof(unsigned char));
            img.pixels[y][x] = static_cast<int>(pixel);
        }
    }

    file.close();
    return img;
}

// Вращение изображения по часовой стрелке
void rotateClockwise(Image& img)
{

    for (int y = 0; y < img.height; ++y)
    {
        for (int x = 0; x < img.width; ++x)
        {
            img.pixels[x][img.height - y - 1] = img.pixels[y][x];
        }
    }
}

// Вращение изображения против часовой стрелки
void rotateCounterClockwise(Image& img)
{

    for (int y = 0; y < img.height; ++y)
    {
        for (int x = 0; x < img.width; ++x)
        {
            img.pixels[img.width - x - 1][y] = img.pixels[y][x];
        }
    }
}

std::vector<std::vector<int>> gaussianKernel =
{
    {5, 10, 5},
    {10, 20, 10},
    {5, 10, 5}
};

void applyGaussianFilter(Image& img)
{
    int kernelSize = 3;
    int offset = kernelSize / 2;

    for (int y = offset; y < img.height - offset; ++y)
    {
        for (int x = offset; x < img.width - offset; ++x)
        {
            double sum = 0;
            double weightSum = 0;

            for (int ky = -offset; ky <= offset; ++ky)
            {
                for (int kx = -offset; kx <= offset; ++kx)
                {
                    int pixel = img.pixels[y + ky][x + kx];
                    int weight = gaussianKernel[ky + offset][kx + offset];
                    sum += pixel * weight;
                    weightSum += weight;
                }
            }

            img.pixels[y][x] = static_cast<int>(sum / weightSum + 0.5);  // Округление к ближайшему
        }
    }

}

void saveBinImage(const std::string& filename, const Image& img)
{
    std::ofstream file(filename, std::ios::binary);

    if (!file)
    {
        std::cerr << "Ошибка: не удалось сохранить файл!" << std::endl;
        exit(1);
    }

    for (int y = 0; y < img.height; ++y)
    {
        for (int x = 0; x < img.width; ++x)
        {
            unsigned char pixel = static_cast<unsigned char>(img.pixels[y][x]);
            file.write(reinterpret_cast<const char*>(&pixel), sizeof(unsigned char));
        }
    }

    file.close();
}

void printBinImage(Image& img)
{
    std::cout << "Содержимое файла:" << std::endl;
    for (int y = 0; y < img.height; ++y)
    {
        for (int x = 0; x < img.width; ++x)
        {
            std::cout << static_cast<int>(img.pixels[y][x]) << "\t";
        }
        std::cout << std::endl;
    }
}
