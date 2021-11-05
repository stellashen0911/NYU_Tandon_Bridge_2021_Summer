//
// Created by StellaShen on 2021/7/26.
//

#include <iostream>
#include <string>
using namespace std;

int main() {
    string name, status;
    int grad_year, cur_year, diff;

    //user input the data we need
    cout<<"Please enter your name: ";
    cin>>name;
    cout<<"Please enter your graduation year: ";
    cin>>grad_year;
    cout<<"Please enter current year: ";
    cin>>cur_year;

    //do the calculation
    diff = grad_year - cur_year;
    if (diff <= 0) {
        status = "Graduated";
    } else if (diff == 4) {
        status = "a Freshman";
    } else if (diff == 3) {
        status = "a Sophomore";
    } else if (diff == 2) {
        status = "a Junior";
    } else if (diff == 1) {
        status = "a Senior";
    }

    cout<<name<<", you are "<<status<<endl;

    return 0;
}