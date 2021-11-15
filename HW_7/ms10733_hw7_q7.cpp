//
// Created by StellaShen on 2021/8/22.
//
#include <iostream>

using namespace std;

int* findMissing(int arr[], int n, int& resArrSize);

int main() {
    int n = 10;
    int arr[10] = {0,5,2,3,8,0,2,6,8,9};
    int* find_missing = nullptr;
    int missing_size = 0;
    find_missing = findMissing(arr, n, missing_size);

    for (int i = 0; i < missing_size; i++) {
        cout<<find_missing[i]<<" ";
    }

    return 0;
}

int* findMissing(int arr[], int n, int& resArrSize) {
    int* occurrence = new int[n];
    int* find_missing = new int[n];
    int count = 0;

    for (int i = 0; i < n; i++) {
        occurrence[arr[i]]++;
    }

    for (int i = 0; i < n; i++) {
        if (occurrence[i] == 0) {
            find_missing[count++] = i;
        }
    }

    resArrSize = count;
    return find_missing;
}