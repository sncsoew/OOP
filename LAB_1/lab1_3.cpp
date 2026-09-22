# include <iostream>

/**
 * @brief Безопасный динамический массив.
 *
 * Структура хранит указатель на динамический массив
 * и его текущий размер.
 */

struct SafeArray {
    int* data;
    int size;
};

/**
 * @brief Создаёт безопасный динамический массив.
 * @param size Размер создаваемого массива.
 * @return SafeArray Структура с указателем на массив и его размером.
 * @details Выделяет память под массив из указанного количества элементов.
 * Все элементы инициализируются нулём.
 */

SafeArray createArray(int size){
    SafeArray arr;
    arr.data = new int[size]();
    arr.size = size;
    return arr;
}

/**
 * @brief Возвращает ссылку на элемент безопасного массива.
 * @param arr Ссылка на безопасный массив.
 * @param index Индекс требуемого элемента.
 * @return int& Ссылка на элемент массива или на переменную-заглушку,
 * если индекс некорректен.
 * @details Перед обращением к элементу проверяется,
 * находится ли индекс в допустимых пределах массива.
 * Если индекс выходит за границы, выводится сообщение об ошибке
 * и возвращается ссылка на статическую переменную-заглушку.
 */

int& getElement(SafeArray& arr, int index){
    static int wroongarr = 0;
    if (index < 0 || index >= arr.size){
        std::cout << "Ошибка! превышен размер массива" << std::endl;
        return wroongarr;
    }
    return arr.data[index];
}

/**
 * @brief Выводит элементы безопасного массива.
 * @param arr Константная ссылка на безопасный массив.
 * @details Функция выводит все элементы массива на экран
 * и не изменяет его содержимое.
 */

void printSafe(const SafeArray& arr){
    for(int i = 0; i <arr.size; ++i){
        std::cout << arr.data[i] << " ";
    }
    std::cout << std::endl;
}

/**
 * @brief Изменяет размер безопасного массива.
 * @param arr Ссылка на безопасный массив, размер которого изменяется.
 * @param M Новый размер массива.
 * @details Создаёт новый массив заданного размера и копирует
 * в него элементы из старого массива.
 *
 * Если новый размер меньше текущего, элементы,
 * которые не помещаются в новый массив, выводятся на экран.
 *
 * Если новый размер больше текущего, новые элементы
 * инициализируются нулём.
 */

void reSizeArray(SafeArray& arr, int M){
    int elementsToCopy;
    if (M < arr.size){
        for(int i = M; i <arr.size; i++){
            std::cout << arr.data[i] <<" ";
        }
    std::cout << std::endl;
    elementsToCopy = M;
    } else{
        elementsToCopy = arr.size;
    }
    int* newarr = new int[M];
    for(int i = 0; i < elementsToCopy; i++){
        newarr[i] = arr.data[i];
    }
    for(int i =arr.size; i < M; i++){
        newarr[i] = 0;
    }
    delete[] arr.data;
    arr.data = newarr;
    arr.size = M;
}

/**
 * @brief Точка входа в программу.
 * @details Создаёт безопасный динамический массив,
 * изменяет его элемент, выводит содержимое,
 * изменяет размер массива и освобождает выделенную память.
 * @return 0, если программа завершилась успешно.
 */
int main(){
    setlocale(LC_ALL, ".UTF-8");
    SafeArray arr = createArray(5);
    getElement(arr,1) = 100;
    printSafe(arr);
    reSizeArray(arr,3);
    delete[] arr.data;
    arr.data = nullptr;
    arr.size = 0;
    return 0;
}