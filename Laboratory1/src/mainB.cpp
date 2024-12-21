// Кирилл Ермаков
// Б82
// st130061@student.spbu.ru
// Laboratory1

#include <iostream>
#include "imageB.h"

int main() {
    std::string inputFilename = "images/image.bin"; // имя файла с сырыми данными
    std::string outputFilename = "images/rotated_image.bin"; // имя для сохранения

    int width, height;
    std::cout << "Введите ширину изображения: ";
    std::cin >> width;
    std::cout << "Введите высоту изображения: ";
    std::cin >> height;

    // Шаг 1: Загрузка изображения
    Image img = loadBinGrayImage(inputFilename, width, height);

    printBinImage(img);

    // Шаг 2: Поворот изображения
    Image rotatedImg = rotateClockwise(img);

    printBinImage(rotatedImg);

    Image unrotatedImg = rotateCounterClockwise(rotatedImg);

    printBinImage(unrotatedImg);

    // Шаг 3: Применение фильтра Гаусса
    Image filteredImg = applyGaussianFilter(unrotatedImg);

    printBinImage(filteredImg);

    // Шаг 4: Сохранение результата
    saveBinImage(outputFilename, filteredImg);

    std::cout << "Обработка завершена!" << std::endl;
    return 0;
}