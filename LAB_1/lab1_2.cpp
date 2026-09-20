#include <iostream>

void process(int*& arr, int size){
    int negativ = -1;
    for (int i = 0; i<size; i++){
        if (arr[i]<0){
            negativ = i;
            break;
        }
    }
    if(negativ != -1){
        int* newarr {new int[negativ]{}};
        for(int k = 0; k < negativ; k++){
            newarr[k] = arr[k];
        }
        delete[] arr;
        arr = newarr;
        std::cout << "Результат: ";
        for (int k = 0; k < negativ; k++)
        {
            std::cout << arr[k] << " ";
        }
        std::cout << std::endl;
        return;
    }
    else{
        for (int k = 0; k < size; k++)
        {
            std::cout << arr[k] << " ";
        }
        std::cout << std::endl;        
    }   
}

int main(){
    setlocale(LC_ALL, ".UTF-8");
    int n;
    std::cout << "Введите размер массива: " << std::endl;
    std::cin >> n;
    int* arra {new int[n]{}};
    for(int i = 0; i<n; i++){
        std::cout << "Введите arr[" << i << "]:";
        std::cin >> arra[i];
    }
    process(arra,n);
    delete[] arra;
    arra = nullptr;
    if (arra != nullptr)
    {
        std::cout << *arra;
    }
    else
    {
        std::cout << "Указатель равен nullptr";
    }
    return 0;
}