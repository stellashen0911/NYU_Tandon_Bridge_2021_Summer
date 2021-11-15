//
// Created by StellaShen on 2021/8/21.
//
#include <iostream>
#include <string>

using namespace std;

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize);
int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr);
void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize);
void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr);

int main() {
    int arr[6] = {3, -1, -3, 0, 6, 4};
    int size = 6;
    int pos_size1 = 0;
    int pos_size2 = 0;
    int pos_size3 = 0;
    int pos_size4 = 0;
    int* pos_arr_ptr3 = nullptr;
    int* pos_arr_ptr4 = nullptr;

    int* pos_arr_ptr1 = getPosNums1(arr, size, pos_size1);
    int* pos_arr_ptr2 = getPosNums2(arr, size, &pos_size2);
    getPosNums3(arr, size, pos_arr_ptr3, pos_size3);
    getPosNums4(arr, size, &pos_arr_ptr4, &pos_size4);

    delete [] pos_arr_ptr1;
    delete [] pos_arr_ptr2;
    delete [] pos_arr_ptr3;
    delete [] pos_arr_ptr4;

    return 0;
}

int* getPosNums1(int* arr, int arrSize, int& outPosArrSize) {
    int* pos_arr = new int[arrSize]; //create a new dynamic integer array
    int j = 0;
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            pos_arr[j] = arr[i];
            j++;
        }
    }
    outPosArrSize = j;
    return pos_arr;
}

int* getPosNums2(int* arr, int arrSize, int* outPosArrSizePtr) {
    int* pos_arr = new int[arrSize]; //create the dynamic int array
    int j = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            pos_arr[j] = arr[i];
            j++;
        }
    }

    *outPosArrSizePtr = j;

    return pos_arr;
}

void getPosNums3(int* arr, int arrSize, int*& outPosArr, int& outPosArrSize) {
    int* pos_arr = new int[arrSize];
    int j = 0;

    for (int i = 0; i < arrSize; i++) {
        if (arr[i] > 0) {
            pos_arr[j] = arr[i];
            j++;
        }
    }
    outPosArrSize = j;
    outPosArr = pos_arr;
}

void getPosNums4(int* arr, int arrSize, int** outPosArrPtr, int* outPosArrSizePtr) {
    int* pos_arr = new int[arrSize];
    int j = 0;

    for (int i = 0; i < arrSize ; i++) {
        if (arr[i] > 0) {
            pos_arr[j] = arr[i];
            j++;
        }
    }

    *outPosArrSizePtr = j;
    *outPosArrPtr = pos_arr;
}