# include <iostream>

struct SafeArray {
    int* data;
    int size;
};

SafeArray createArray(int size){
    SafeArray arr;
    arr.data = new int[size];
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

int main(){
    setlocale(LC_ALL, ".UTF-8");
    SafeArray arr = createArray(5);
    getElement(arr,6) = 100;
}