//
// Created by StellaShen on 2021/7/26.
//
#include <iostream>
using namespace std;

const double HALF = 0.5;
const double CLUB_DIS = 0.9;

int main() {
    double first_price, second_price;
    char club;
    double taxRate;
    double base_price, after_discount_price;
    double total_price;

    //user enter the input data
    cout<<"Enter price of first item: ";
    cin>>first_price;
    cout<<"Enter price of second item: ";
    cin>>second_price;
    cout<<"Does customer have a club card? (Y/N): ";
    cin>>club;
    cout<<"Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin>>taxRate;

    //do the calculation based on user input
    base_price = first_price + second_price;
    if (first_price > second_price) {
        after_discount_price = first_price + HALF * second_price;
    } else {
        after_discount_price = HALF * first_price + second_price;
    }
    if (club == 'Y' || club == 'y') {
        after_discount_price = after_discount_price * CLUB_DIS;
    }
    total_price = after_discount_price * (1 - (taxRate / 100));

    cout<<"Base price: "<<base_price<<endl;
    cout<<"Price after discounts: "<<after_discount_price<<endl;
    cout<<"Total price: "<<total_price<<endl;

    return 0;
}
