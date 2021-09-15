//
// Created by Shen Stella on 7/18/21.
//
#include <iostream>
using namespace std;

int main() {
    int int1;
    int int2;
    int mul;
    int sub;
    int add;
    int div;
    double div_double;
    int mod;


    cout<<"Please enter two positive integers, separated by a space: "<<endl;
    cin>>int1>>int2;

    add = int1 + int2;
    sub = int1 - int2;
    mul = int1 * int2;
    div = int1 / int2;
    div_double = (double) int1 / int2;
    mod = int1 % int2;

    cout<<int1<<" + "<<int2<<" = "<<add<<endl;
    cout<<int1<<" - "<<int2<<" = "<<sub<<endl;
    cout<<int1<<" * "<<int2<<" = "<<mul<<endl;
    cout<<int1<<" / "<<int2<<" = "<<div_double<<endl;
    cout<<int1<<" div "<<int2<<" = "<<div<<endl;
    cout<<int1<<" mod "<<int2<<" = "<<mod<<endl;

    return 0;
}

