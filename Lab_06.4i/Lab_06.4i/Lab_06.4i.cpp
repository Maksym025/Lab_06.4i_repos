#include <iostream>
#include <time.h>
using namespace std;


void CreateArray(int* arr, const int size, const int Low, const int High) {
    for (int i = 0; i < size; i++) {
        arr[i] = Low + rand() % (High - Low + 1);
    }
}


int FindMaxIndex(const int* arr, const int size) {
    int maxIndex = 0;
    for (int i = 1; i < size; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i;
        }
    }
    return maxIndex;
}


int ProductBetweenZeros(const int* arr, const int size) {
    int firstZero = -1, secondZero = -1;
    int product = 1;
    bool foundFirst = false;

    for (int i = 0; i < size; i++) {
        if (arr[i] == 0) {
            if (!foundFirst) {
                firstZero = i;
                foundFirst = true;
            }
            else {
                secondZero = i;
                break;
            }
        }
    }

    if (firstZero != -1 && secondZero != -1) {
        for (int i = firstZero + 1; i < secondZero; i++) {
            product *= arr[i];
        }
    }
    else {
        return 0; 
    }

    return product;
}

void TransformArray(int* arr, const int size) {
    int* temp = new int[size];
    int oddIndex = 0, evenIndex = size / 2;

   
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            temp[evenIndex++] = arr[i]; 
        }
        else {
            temp[oddIndex++] = arr[i];   
        }
    }

 
    for (int i = 0; i < size; i++) {
        arr[i] = temp[i];
    }

    delete[] temp; 
}


int main() {
    srand((unsigned)time(NULL)); 

    int n;
    cout << "Enter the size of the array (n): ";
    cin >> n;

    if (n <= 0) {
        cout << "Size must be positive." << endl;
        return 1;
    }

    int* arr = new int[n]; 
    int Low = 0; 
    int High = 10; 

    CreateArray(arr, n, Low, High);  

   
    cout << "Original array:    ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    // 1.1. Знаходимо номер максимального елемента
    int maxIndex = FindMaxIndex(arr, n);
    cout << "Index of the maximum element: " << maxIndex << endl;

    // 1.2. Обчислюємо добуток елементів між першим і другим нулями
    int product = ProductBetweenZeros(arr, n);
    cout << "Product of elements between the first and second zeroes: " << product << endl;

    // 2. Перетворюємо масив
    TransformArray(arr, n);

   
    cout << "Transformed array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;


    delete[] arr;

    return 0;
}
