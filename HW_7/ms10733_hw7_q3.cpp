//
// Created by StellaShen on 2021/8/21.
//

#include <iostream>

using namespace std;

void oddsKeepEvensFlip(int arr[], int arrSize);
bool is_odd(int n);

int main() {
    int arr[13] = {5, 2, 11, 7, 6, 4, 9, 3, 5 ,2 , 4 ,1 ,6};
    int size = 13;

    for (int i = 0; i < size; i++) {
        cout<<arr[i]<<' ';
    }

    cout<<"\n"<<endl;

    oddsKeepEvensFlip(arr, size);

    for (int i = 0; i < size; i++) {
        cout<<arr[i]<<' ';
    }

    return 0;
}

bool is_odd(int n) {
    if (n % 2 == 0) {
        return false;
    } else {
        return true;
    }
}

void oddsKeepEvensFlip(int arr[], int arrSize) {
    int i = 0;
    int j = arrSize - 1;

    while (i != j) {
        if (is_odd(arr[i])) {
            i++;
        } else {
            int temp = arr[i];
            for (int k = i; k < j; k++) {
                arr[k] = arr[k + 1];
            }
            arr[j] = temp;
            j--;
        }
    }

}