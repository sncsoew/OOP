#include <iostream>

void fillArray(int (&arr)[10]){
    for (int i = 0; i<10;i++){
        std::cin >> arr[i];
    }
}

void printArray(int (&arr)[10]){
    for(auto n: arr){
        std::cout << n << " ";
    }
}

void swapElements(int &a,int &b,int (&arr)[10]){
    int t = arr[a-1];
    arr[a-1] = arr[b-1];
    arr[b-1] = t;
}

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
    return 0;
}