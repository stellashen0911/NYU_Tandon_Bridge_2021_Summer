//
// Created by StellaShen on 2021/8/29.
//
#include <iostream>

using namespace std;

int sumOfSquares(int arr[], int arrSize);
bool isSorted(int arr[], int arrSize);

int main() {
    int arr[4] = {2, 4, 6, 8};
    int arrSize = 4;
    int sum;
    sum = sumOfSquares(arr, arrSize);
    cout<<sum<<endl;
    bool sort = isSorted(arr, arrSize);
    cout<<sort;
    return 0;
}

int sumOfSquares(int arr[], int arrSize) {
    int result;
    if (arrSize == 1) {
        result = arr[0] * arr[0];
        return result;
    } else {
        result = sumOfSquares(arr, arrSize - 1);
        result += arr[arrSize - 1] * arr[arrSize - 1];
        return result;
    }
}
bool isSorted(int arr[], int arrSize) {
    if (arrSize == 1 || arrSize == 0) {
        return true;
    } else {
        return (isSorted(arr, arrSize - 1)) && (arr[arrSize - 1] > arr[arrSize - 2]);
    }
}
