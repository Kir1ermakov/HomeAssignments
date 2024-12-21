#include "imageB.h"
#include <iostream>
#include <fstream>

Image loadRawGrayImage(const std::string& filename, int width, int height) {
    std::ifstream file(filename, std::ios::binary);
    
    // Создаем двумерный вектор для хранения пикселей
    Image img;
    img.width = width;
    img.height = height;
    img.pixels.resize(height, std::vector<int>(width));

    // Чтение данных пикселей
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            file.read(reinterpret_cast<char*>(&img.pixels[y][x]), sizeof(int));
        }
    }

    file.close();
    return img;
}

Image rotateClockwise(const Image& img) {
    Image rotated;
    rotated.width = img.height;
    rotated.height = img.width;
    rotated.pixels.resize(rotated.height, std::vector<int>(rotated.width));

    for (int y = 0; y < img.height; ++y) {
        for (int x = 0; x < img.width; ++x) {
            rotated.pixels[x][img.height - y - 1] = img.pixels[y][x];
        }
    }

    return rotated;
}

Image rotateCounterClockwise(const Image& img) {
    Image rotated;
    rotated.width = img.height;
    rotated.height = img.width;
    rotated.pixels.resize(rotated.height, std::vector<int>(rotated.width));

    for (int y = 0; y < img.height; ++y) {
        for (int x = 0; x < img.width; ++x) {
            rotated.pixels[img.width - x - 1][y] = img.pixels[y][x];
        }
    }

    return rotated;
}

std::vector<std::vector<int>> gaussianKernel = {
    {1, 2, 1},
    {2, 4, 2},
    {1, 2, 1}
};

Image applyGaussianFilter(const Image& img) {
    Image filtered = img;
    int kernelSize = 3;
    int offset = kernelSize / 2;

    // Применение фильтра Гаусса
    for (int y = offset; y < img.height - offset; ++y) {
        for (int x = offset; x < img.width - offset; ++x) {
            int sum = 0;
            int weightSum = 0;

            // Применение матрицы Гаусса
            for (int ky = -offset; ky <= offset; ++ky) {
                for (int kx = -offset; kx <= offset; ++kx) {
                    int pixel = img.pixels[y + ky][x + kx];
                    int weight = gaussianKernel[ky + offset][kx + offset];
                    sum += pixel * weight;
                    weightSum += weight;
                }
            }

            filtered.pixels[y][x] = sum / weightSum;
        }
    }

    return filtered;
}

void saveRawImage(const std::string& filename, const Image& img) {
    std::ofstream file(filename, std::ios::binary);

    for (int y = 0; y < img.height; ++y) {
        for (int x = 0; x < img.width; ++x) {
            file.write(reinterpret_cast<const char*>(&img.pixels[y][x]), sizeof(int));
        }
    }

    file.close();
}
