//
// Created by StellaShen on 2021/8/29.
//

#include <iostream>

using namespace std;

int minInArray1(int arr[], int arrSize);
int minInArray2(int arr[], int low, int high);

int main() {
    int arr[10] = {9, -2, 14, 12, 3, 6, 2, 1, -9, 15};
    int res1, res2, res3, res4;
    res1 = minInArray1(arr, 10);
    res2 = minInArray2(arr, 0, 9);
    cout<<res1<<" "<<res2<<endl; //should both be -9
    res3 = minInArray2(arr, 2, 5);
    res4 = minInArray1(arr+2, 4); //arr+2 is equivalent to &(arr[2])
    cout<<res3<<" "<<res4<<endl; //should both be 3
    return 0;
}

int minInArray1(int arr[], int arrSize) {
    int min;
    if  (arrSize == 1) {
        min = arr[0];
        return min;
    } else {
        int temp = minInArray1(arr, arrSize - 1);
        if (arr[arrSize - 1] < temp) {
            min = arr[arrSize - 1];
        } else {
            min = temp;
        }
        return min;
    }
}

int minInArray2(int arr[], int low, int high) {
    int min;
    if (low == high) {
        min = arr[low];
        return min;
    } else if (high - low == 1) {
        if (arr[high] > arr[low]) {
            min = arr[low];
        } else {
            min = arr[high];
        }
        return min;
    } else {
        min = minInArray2(arr, low + 1, high - 1);
        int temp;
        if (arr[high] > arr[low]) {
            temp = arr[low];
        } else {
            temp = arr[high];
        }
        if (temp < min) {
            return temp;
        } else {
            return min;
        }
    }
}