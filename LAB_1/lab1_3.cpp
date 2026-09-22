# include <iostream>

struct SafeArray {
    int* data;
    int size;
};

SafeArray createArray(int size){
    SafeArray arr;
    arr.data = new int[size]();
    arr.size = size;
    return arr;
}

int& getElement(SafeArray& arr, int index){
    static int wroongarr = 0;
    if (index < 0 || index >= arr.size){
        std::cout << "Ошибка! превышен размер массива" << std::endl;
        return wroongarr;
    }
    return arr.data[index];
}

void printSafe(const SafeArray& arr){
    for(int i = 0; i <arr.size; ++i){
        std::cout << arr.data[i] << " ";
    }
    std::cout << std::endl;
}

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