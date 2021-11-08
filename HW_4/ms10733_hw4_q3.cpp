//
// Created by StellaShen on 2021/8/2.
//

#include <iostream>
#include <cmath>
using namespace std;

void find_binary(int number, int & binary);

int main() {
    int decimal_num;
    int binary_num = 0;

    cout<<"Enter decimal number: "<<endl;
    cin>>decimal_num;
    if (decimal_num < 0) {
        cout << "The number entered is not positive.\n";
        return 0;
    }

    find_binary(decimal_num, binary_num);

    cout<<"The binary representation of "<<decimal_num<<" is "<<binary_num<<endl;

    return 0;
}

void find_binary(int number, int & binary) {
    int power_2 = 0;
    int n = number;

    if (number == 0) {
        return;
    }

    while (n != 1) {
        n = n / 2;
        power_2++;
    }
    if (number == pow(2, power_2)) {
        binary += pow(10, power_2);
        return;
    } else {
        binary += pow(10, power_2);
        number = number - pow(2, power_2);
        find_binary(number, binary);
    }
}
