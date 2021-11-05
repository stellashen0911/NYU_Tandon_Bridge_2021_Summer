//
// Created by StellaShen on 2021/7/26.
//
#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    double a, b, c;
    double x1, x2;
    string result;
    double depend, sqrt_depend;

    //ask user to input the data for a, b and c
    cout << "Please enter a value of a: ";
    cin >> a;
    cout << "Please enter a value of b: ";
    cin >> b;
    cout << "Please enter a value of c: ";
    cin >> c;

    //calculate the discriminant
    depend = (b * b) - (4 * a * c);
    sqrt_depend = sqrt(depend);

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(1);

    //case when a = 0
    if (a == 0 && b == 0 && c == 0) {
        result = "infinite number of solutions";
        cout<<"This equation has "<<result<<endl;
    } else if (a == 0 && b == 0 && c != 0) {
        result = "no result";
        cout<<"This equation has "<<result<<endl;
    } else if (a == 0 && b != 0 && c != 0) {
        result = "a single real solution ";
        x1 = (-c) / b;
        cout<<"This equation has "<<result<<"x = "<<x1<<endl;
    } else if (a == 0 && b != 0 && c == 0) {
        result = "a single real solution ";
        x1 = 0;
        cout<<"This equation has "<<result<<"x = "<<x1<<endl;
    } else if (a != 0) { //case when a != 0
        if (depend == 0) {
            result = "a single real solution ";
            x1 = (-b) / 2 * a;
            cout<<"This equation has "<<result<<"x = "<<x1<<endl;
        } else if (depend > 0) {
            result = "two real solutions ";
            x1 = (-b + sqrt_depend) / 2 * a;
            x2 = (-b - sqrt_depend) / 2 * a;
            cout<<"This equation has "<<result<<" x1 = "<<x1<<", x2 = "<<x2<<endl;
        } else if (depend < 0) {
            result = "no real solution ";
            cout<<"This equation has "<<result<<endl;
        }
    }

    return 0;
}
