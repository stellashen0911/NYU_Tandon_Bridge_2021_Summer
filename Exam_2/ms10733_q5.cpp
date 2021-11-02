//
// Created by StellaShen on 2021/9/3.
//
#include <iostream>

using namespace std;


int* intersectSortedArrays(int srtArr1[], int n1, int srtArr2[], int n2, int& resArrSize) {
    int p1 = 0;
    int p2 = 0;
    int* result = new int[n1+n2];
    int count = 0;

    while ((p1 != n1) && (p2 != n2)) {
        if (srtArr1[p1] < srtArr2[p2]) {
            p1++;
        } else if (srtArr1[p1] > srtArr2[p2]) {
            p2++;
        } else {
            result[count] = srtArr1[p1];
            p1++;
            p2++;
            count++;
        }
    }

    resArrSize = count;
    return result;
}