//
// Created by StellaShen on 2021/8/2.
//
#include <iostream>
using namespace std;

int main() {
    int n;
    int start;

    cout<<"Please enter a positive integer:"<<endl;
    cin>>n;

    start = 1;
    while (start <= n) {
        for (int i = 1; i <= n; i++) {
            int print_num = start * i;
            cout<<print_num<<"\t";
        }
        cout<<endl;
        start++;
    }
    return 0;
}

