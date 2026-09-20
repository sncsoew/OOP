#include <iostream>

void fillArray(int (&arr)[10]){
    for (int i = 0; i<10;i++){
        std::cin >> arr[i];
    }
}

int main(){
    int array[10];
    fillArray(array);
    return 0;
}