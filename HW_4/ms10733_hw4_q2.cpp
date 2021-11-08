//
// Created by StellaShen on 2021/8/2.
//
#include <iostream>
#include <string>
using namespace std;

//declare the roman number system break-number
const int M = 1000;
const int D = 500;
const int C = 100;
const int L = 50;
const int X = 10;
const int V = 5;
const int I = 1;

//constrain
//1. The digits form a monotonically non-increasing sequence.
//2. ‘D’, ‘L’ and ‘V’ can each appear at most one time in the number.
//   ‘C’, ‘X’ and ‘I’ can each appear at most four times in the number.

void RomanSystem(int number, string & roman);

int main(){
    int decimal_number;
    string roman_number;

    cout<<"Enter decimal number:"<<endl;
    cin>>decimal_number;
    RomanSystem(decimal_number, roman_number);

    cout<<decimal_number<<" is "<<roman_number<<endl;
    return 0;
}

void RomanSystem(int number, string & roman) {
    int number_of_M, number_of_C, number_of_X, number_of_I;
    while (number != 0) {
        if (number >= M) {
            number_of_M = number / M;
            for (int i = 0; i < number_of_M; i++) {
                roman += "M";
            }
            number = number % M;
        } else if (number >= D) {
            roman += "D";
            number = number % D;
        } else if (number >= C) {
            number_of_C = number / C;
            for (int i = 0; i < number_of_C; i++) {
                roman += "C";
            }
            number = number % C;
        } else if (number >= L) {
            roman += "L";
            number = number % L;
        } else if (number >= X) {
            number_of_X = number / X;
            for (int i = 0; i < number_of_X; i++) {
                roman += "X";
            }
            number = number % X;
        } else if (number >= V) {
            roman += "V";
            number = number % V;
        } else if (number >= I) {
            number_of_I = number / I;
            for (int i = 0; i < number_of_I; i++) {
                roman += "I";
            }
            number = number % I;
        }
    }
}
