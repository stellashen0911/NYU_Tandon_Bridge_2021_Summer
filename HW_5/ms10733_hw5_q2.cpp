//
// Created by StellaShen on 2021/8/8.
//
#include <iostream>
#include <string>

using namespace std;

void printShiftedTriangle(int n, int m, char symbol);
void printPineTree(int n, char symbol);

int main() {
    int num;
    char symbol;

    cout<<"Please enter the number of triangles you want to build: ";
    cin>>num;

    cout<<"Please enter the symbol for your tree: ";
    cin>>symbol;

    printPineTree(num, symbol);

    return 0;
}

void printShiftedTriangle(int n, int m, char symbol) {
    for (int i = 1; i <= n; i++) {
        cout<<string(m + n - i, ' ')<<string(2*i - 1, symbol)<<endl;
    }
}

void printPineTree(int n, char symbol) {
    int count = 0;
    while (count < n) {
        printShiftedTriangle(2 + count, n - 1 - count, symbol);
        count++;
    }
}

