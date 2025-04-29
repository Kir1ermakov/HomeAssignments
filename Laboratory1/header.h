#ifndef BIN_FILE_WRITER_H
#define BIN_FILE_WRITER_H

#include <iostream>
#include <fstream>
#include <vector>

/**
 * @brief Записывает матрицу чисел (char) в бинарный файл. Каждое число — 1 байт.
 * 
 * @param filename Имя файла (например, "matrix.bin").
 * @param data Вектор векторов (матрица) с данными (числа в диапазоне -128–127).
 * @return true Если запись прошла успешно.
 * @return false Если произошла ошибка.
 */
bool writeMatrixToBinaryFile(const std::string& filename, const std::vector<std::vector<char>>& data);

/**
 * @brief Читает матрицу чисел (char) из бинарного файла. 
 * 
 * @param filename Имя файла (например, "matrix.bin").
 * @param data Ссылка на вектор векторов, куда будут записаны данные.
 * @param rows Количество строк (должно быть известно заранее).
 * @param cols Количество столбцов (должно быть известно заранее).
 * @return true Если чтение прошло успешно.
 * @return false Если произошла ошибка.
 */
bool readMatrixFromBinaryFile(const std::string& filename, std::vector<std::vector<char>>& data, size_t rows, size_t cols);

#endif // BIN_FILE_WRITER_H