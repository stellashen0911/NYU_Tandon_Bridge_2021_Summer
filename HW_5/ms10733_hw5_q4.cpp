//
// Created by StellaShen on 2021/8/8.
//
#include <iostream>
#include <cmath>

using namespace std;

void printDivisors(int num);

int main() {
    int n;

    cout<<"Please enter a positive integer >= 2: ";
    cin>>n;

    printDivisors(n);

    return 0;
}

void printDivisors(int num) {
    for (int i = 1; i < sqrt(num); i++) {
        if (num % i == 0) {
            cout<<i<<" ";
        }
    }
    for (int i = sqrt(num); i >= 1; i--) {
        if (num % i == 0) {
            cout<<num / i<<" ";
        }
    }
}