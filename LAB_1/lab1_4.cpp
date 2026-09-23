#include <iostream>

int** allocateMatrix(int rows, int cols){
    int** matrix {new int*[rows]};
    for(int i=0; i<rows; i++){
        matrix[i] = new int [cols]{};
    }
    return matrix;
}



int main(){
    setlocale(LC_ALL, ".UTF-8");
    int rows;
    int cols;
    std::cout << "Введите количество строк: ";
    std::cin >> rows;

    std::cout << "Введите количество столбцов: ";
    std::cin >> cols;

    int** matrix = allocateMatrix(rows, cols);
}