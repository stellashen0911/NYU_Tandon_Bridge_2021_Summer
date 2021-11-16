#include <iostream>

using namespace std;

void printTriangle(int n);
void printOpositeTriangles(int n);
void printRuler(int n);

int main() {
    printRuler(4);
    printOpositeTriangles(4);
    printTriangle(4);
    return 0;
}

void printTriangle(int n) {
    if (n == 1) {
        cout<<"*";
    } else {
        printTriangle(n - 1);
        cout<<"\n";
        for (int i = n; i > 0; i--) {
            cout<<"*";
        }
    }
}

void printOpositeTriangles(int n) {
    if(n == 1) {
        cout<<"*"<<endl;
        cout<<"*";
    } else {
        for (int i = n; i > 0; i--) {
            cout<<"*";
        }
        cout<<"\n";
        printOpositeTriangles(n - 1);
        cout<<"\n";
        for(int i = n; i > 0; i--) {
            cout<<"*";
        }
    }
}

void printRuler(int n) {
    if (n == 1) {
        cout<<"-"<<"\n";
    } else {
        printRuler(n - 1);
        for (int i = 0; i < n; i++) {
            cout<<"-";
        }
        cout<<"\n";
        printRuler(n - 1);
    }
}