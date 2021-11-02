//
// Created by StellaShen on 2021/9/3.
//
#include <iostream>

using namespace std;

int minValueInEvenIndices(int arr[], int arrSize){
    if ((arrSize == 1) || (arrSize == 0)) {
        return arr[0];
    } else {
        int min = minValueInEvenIndices(arr, arrSize - 2);
        if (arrSize % 2 == 0) {
            if (arr[arrSize-2] > min) {
                return min;
            } else {
                return arr[arrSize-2];
            }
        } else {
            if (arr[arrSize - 1] > min) {
                return min;
            } else {
                return arr[arrSize - 1];
            }
        }
    }
}