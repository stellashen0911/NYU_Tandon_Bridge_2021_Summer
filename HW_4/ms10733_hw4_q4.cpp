//
// Created by StellaShen on 2021/8/2.
//
#include <iostream>
#include <cmath>
using namespace std;

const double ONE = 1.0;

int main() {
    int length_a = 1;
    int length_b = 0;
    int number_a = 1;
    int number_b = 1;
    int product_a = 1;
    int product_b = 1;
    double geo_mean_a, geo_mean_b;
    bool stop;

    //section a answer
    cout<<"section a"<<endl;
    cout<<"Please enter the length of the sequence: ";
    cin>>length_a;
    cout<<"Please enter your sequence:"<<endl;
    for (int i = 0; i < length_a; i++) {
        cin>>number_a;
        product_a *= number_a;
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    geo_mean_a = pow((double)product_a, (ONE/length_a));

    cout<<"The geometric mean is: "<<geo_mean_a<<endl;

    //section b answer
    cout<<" Please enter a non-empty sequence of positive integers, each one in a separate line. End your\n";
    cout<<"sequence by typing -1: "<<endl;
    stop = true;
    while (stop){
        cin>>number_b;
        if (number_b == -1){
            stop = false;
        }else {
            length_b++;
            product_b *= number_b;
        }
    }

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(4);

    geo_mean_b = pow((double)product_b, (ONE/length_b));

    cout<<"The geometric mean is: "<<geo_mean_b<<endl;

    return 0;
}
