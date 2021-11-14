#include <iostream>

using namespace std;

int minInArray(int arr[], int arrSize);
void printMinIndex(int arr[], int arrSize, int min);

const int SIZE = 20;

int main() {
    int input;
    int arr[SIZE];
    int min;

    cout<<"Please enter 20 integers separated by a space: "<<endl;

    for(int i = 0; i < SIZE; i++) {
        cin>>input;
        arr[i] = input;
    }
    min = minInArray(arr, SIZE);

    cout<<"The minimum value is "<<min<<", and it is located in the following indices:";

    printMinIndex(arr, SIZE, min);

    return 0;
}

int minInArray(int arr[], int arrSize) {
    int min = arr[0];

    for (int i = 1; i <arrSize; i++) {
        if (arr[i] < min) {
            min = arr[i];
        }
    }

    return min;
}

void printMinIndex(int arr[], int arrSize, int min) {
    for (int i = 0; i < arrSize; i++) {
        if (arr[i] == min) {
            cout<<i<<" ";
        }
    }
}