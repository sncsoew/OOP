#include <iostream>

/**
 * @brief Заполняет массив десятью числами.
 * @param arr Массив из 10 целых чисел.
 * @details Считывает 10 чисел из стандартного ввода
 * и записывает их в элементы массива.
 */
void fillArray(int (&arr)[10]){
    for (int i = 0; i<10;i++){
        std::cin >> arr[i];
    }
}

/**
 * @brief Выводит массив на экран.
 * @param arr Массив из 10 целых чисел.
 * @details Использует range-based for цикл и auto
 * для последовательного вывода элементов массива.
 */
void printArray(int (&arr)[10]){
    for(auto n: arr){
        std::cout << n << " ";
    }
}

/**
 * @brief Меняет местами два элемента массива.
 * @param a Индекс первого элемента.
 * @param b Индекс второго элемента.
 * @param arr Массив из 10 целых чисел.
 * @details Меняет местами элементы массива с индексами a и b.
 * Индексы вводятся начиная с 1.
 */
void swapElements(int &a,int &b,int (&arr)[10]){
    int t = arr[a-1];
    arr[a-1] = arr[b-1];
    arr[b-1] = t;
}

/**
 * @brief Умножает каждый элемент массива на два.
 * @param arr Массив из 10 целых чисел.
 * @details Использует range-based for цикл с неконстантной
 * ссылкой int& для изменения каждого элемента массива.
 */
void multiplyByTwo(int (&arr)[10]){
    for (int &x: arr ){
        x = x * 2; 
    }
}

/**
 * @brief Главная функция программы.
 * @return 0 При успешном завершении программы.
 * @details Заполняет массив, выводит его на экран,
 * меняет местами два выбранных элемента и умножает
 * все элементы массива на два.
 */
int main(){
    setlocale(LC_ALL, ".UTF-8");
    int array[10];
    std::cout << "Введите 10 чисел:" << std::endl;
    fillArray(array);
    printArray(array);
    int one;
    int two;
    std::cout << "\nВведите первый индекс:" << std::endl;
    std::cin >> one;
    std::cout << "Введите второй индекс:" << std::endl;
    std::cin >> two;
    swapElements(one, two, array);
    multiplyByTwo(array);
    return 0;
}