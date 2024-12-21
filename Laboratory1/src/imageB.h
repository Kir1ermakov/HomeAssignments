#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>

// Класс Image для представления растрового изображения
struct Image {
    int width, height;  // Ширина и высота изображения
    std::vector<std::vector<int>> pixels;  // Двумерный массив для пикселей (8-битное изображение)
};

// Функции для работы с изображениями
Image loadRawGrayImage(const std::string& filename, int width, int height);
Image rotateClockwise(const Image& img);
Image rotateCounterClockwise(const Image& img);
Image applyGaussianFilter(const Image& img);
void saveRawImage(const std::string& filename, const Image& img);

#endif // IMAGE_H
