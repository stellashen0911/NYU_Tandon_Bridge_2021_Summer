//
// Created by StellaShen on 2021/7/26.
//
#include <iostream>
#include <string>

using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;
const double DECIMAL_ZERO = 0.00;
const double DECIMAL_FIFTY = 0.50;

int main () {
    double input_num, fractional_part;
    int rounding_method;
    int int_part;
    int result;

    cout<<"Please enter a Real number: "<<endl;
    cin>>input_num;

    cout<<"Choose your rounding method:\n"
          "1. Floor round\n"
          "2. Ceiling round\n"
          "3. Round to the nearest whole number"<<endl;
    cin>>rounding_method;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    int_part = (int) input_num;
    if (input_num > 0) {
        fractional_part = input_num - int_part;
    } else {
        fractional_part = int_part - input_num;
    }

    switch(rounding_method) {
        case FLOOR_ROUND:
            if (input_num < 0 && fractional_part > DECIMAL_ZERO) {
                result = int_part - 1;
            } else {
                result = int_part;
            }
            break;
        case CEILING_ROUND:
            if (input_num >= 0 && fractional_part > DECIMAL_ZERO) {
                result = int_part + 1;
            } else {
                result = int_part;
            }
            break;
        case ROUND:
            if (input_num < 0) {
                if (fractional_part < DECIMAL_FIFTY) {
                    result = int_part;
                } else if (fractional_part >= DECIMAL_FIFTY) {
                    result = int_part - 1;
                }
            } else if (input_num >= 0) {
                if (fractional_part < DECIMAL_FIFTY) {
                    result = int_part;
                } else if (fractional_part >= DECIMAL_FIFTY) {
                    result = int_part + 1;
                }
            }
            break;
    }
    cout<<result<<endl;
    return 0;
}
