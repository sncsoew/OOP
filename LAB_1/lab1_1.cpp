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

int main(){
    int array[10];
    fillArray(array);
    printArray(array);
    return 0;
}