//
// Created by StellaShen on 2021/8/2.
//
#include <iostream>
using namespace std;

bool is_even(int number);

int main() {
    int n;
    int num;
    int evenCount, oddCount;

    cout<<"Please enter a positive integer: ";
    cin>>n;
    //exception of input n
    if (n <= 0) {
        cout << "The number entered is not positive."<<endl;
        return 0;
    }
    else if (n == 1) {
        cout << "No such number exists in the given range."<<endl;
        return 0;
    }

    num = 1;
    while (num <= n) {
        int temp = num;
        evenCount = 0;
        oddCount = 0;

        while (temp != 0) {
            if (is_even(temp % 10)) {
                evenCount++;
                temp = temp / 10;
            } else {
                oddCount++;
                temp = temp / 10;
            }
        }
        if (evenCount > oddCount) {
            cout<<num<<endl;
        }

        num++;
    }

    return 0;
}

bool is_even(int number) {
    if (number % 2 == 0) {
        return true;
    } else{
        return false;
    }
}


