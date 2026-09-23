#include <iostream>

/**
 * @brief Выделяет память под двумерный динамический массив.
 *
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @return int** Указатель на выделенный двумерный массив.
 *
 * @details Сначала выделяется массив указателей на строки,
 * затем для каждой строки выделяется память под элементы.
 * Все элементы инициализируются нулём.
 */

int** allocateMatrix(int rows, int cols){
    int** matrix {new int*[rows]};
    for(int i=0; i<rows; i++){
        matrix[i] = new int [cols]{};
    }
    return matrix;
}

/**
 * @brief Заполняет двумерный массив с клавиатуры.
 *
 * @param matrix Указатель на двумерный массив.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 *
 * @details Пользователь поочерёдно вводит значения
 * для каждого элемента матрицы.
 */

void  fillMatrix(int** matrix, int rows, int cols){
    for(int i = 0; i<rows; i++){
        for(int j =0; j<cols; j++){
            std::cout << "Введите matrix[" << i << "][" << j << "]: ";
            std::cin >> matrix[i][j];
        }
    }
}

/**
 * @brief Выводит двумерный массив на экран.
 *
 * @param matrix Указатель на двумерный массив.
 * @param rows Количество строк.
 * @param cols Количество столбцов.
 * @param showBorders Показывать ли рамку вокруг матрицы.
 * @param title Заголовок матрицы.
 *
 * @details Если параметр showBorders равен true,
 * вокруг матрицы выводится рамка из символов.
 * Параметры showBorders и title имеют значения по умолчанию.
 */

void printMatrix(int** matrix, int rows, int cols, bool showBorders = true, std::string title = "Matrix"){
    std::cout << "\n" << title << std::endl;
    if (showBorders){
        std::cout << "*";
        for (int j = 0; j < cols; j++) {
            std::cout << "---";
        }
        std::cout << "*" << std::endl;
    }
    for (int i = 0; i < rows; i++) {

        if (showBorders) {
            std::cout << "|";
        }

        for (int j = 0; j < cols; j++) {
            std::cout << " " << matrix[i][j] << " ";
        }

        if (showBorders) {
            std::cout << "|";
        }

        std::cout << std::endl;
    }
    if (showBorders) {
        std::cout << "*";
        for (int j = 0; j < cols; j++) {
            std::cout << "---";
        }
        std::cout << "*" << std::endl;
    }
}

/**
 * @brief Освобождает память двумерного динамического массива.
 *
 * @param matrix Указатель на двумерный массив.
 * @param rows Количество строк.
 *
 * @details Сначала освобождается память каждой строки
 * с помощью delete[], после чего освобождается массив указателей.
 */

void freeMatrix(int** matrix, int rows){
    for(int i = 0; i< rows; i++){
        delete[] matrix[i];
    }
    delete[] matrix;
}

/**
 * @brief Точка входа в программу.
 *
 * @return 0 Если программа завершилась успешно.
 *
 * @details Запрашивает размеры матрицы, выделяет память,
 * заполняет матрицу и выводит её на экран тремя способами:
 * с параметрами по умолчанию, с указанным заголовком
 * и со всеми параметрами.
 * После завершения работы освобождает выделенную память.
 */

int main(){
    setlocale(LC_ALL, ".UTF-8");
    int rows;
    int cols;
    std::cout << "Введите количество строк: ";
    std::cin >> rows;

    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    int** matrix = allocateMatrix(rows, cols);
    fillMatrix(matrix,rows,cols);

    printMatrix(matrix, rows, cols);
    printMatrix(matrix, rows, cols, false);
    printMatrix(matrix, rows, cols, true, "Оценки студентов");

    freeMatrix(matrix, rows);

    matrix = nullptr;

    return 0;
}