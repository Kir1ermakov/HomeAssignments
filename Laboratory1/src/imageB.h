// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Laboratory1

#ifndef IMAGE_H
#define IMAGE_H

#include <vector>
#include <string>

struct Image {
    int width, height;  
    std::vector<std::vector<int>> pixels;
};

Image loadBinGrayImage(const std::string& filename, int width, int height);
Image rotateClockwise(const Image& img);
Image rotateCounterClockwise(const Image& img);
Image applyGaussianFilter(const Image& img);
void saveBinImage(const std::string& filename, const Image& img);
void printBinImage(const Image& img);

#endif // IMAGE_H
