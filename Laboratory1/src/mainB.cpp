#include <iostream>
#include "imageB.h"

int main() {
    std::string inputFilename = "../images/image.raw"; // имя файла с сырыми данными
    std::string outputFilename = "rotated_image.raw"; // имя для сохранения

    int width, height;
    std::cout << "Введите ширину изображения: ";
    std::cin >> width;
    std::cout << "Введите высоту изображения: ";
    std::cin >> height;

    // Шаг 1: Загрузка изображения
    Image img = loadRawGrayImage(inputFilename, width, height);

    // Шаг 2: Поворот изображения
    Image rotatedImg = rotateClockwise(img);

    // Шаг 3: Применение фильтра Гаусса
    Image filteredImg = applyGaussianFilter(rotatedImg);

    // Шаг 4: Сохранение результата
    saveRawImage(outputFilename, filteredImg);

    std::cout << "Обработка завершена!" << std::endl;
    return 0;
}