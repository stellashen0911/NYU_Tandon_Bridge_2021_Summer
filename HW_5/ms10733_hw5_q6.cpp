//
// Created by StellaShen on 2021/8/8.
//
#include<iostream>

using namespace std;

double factorial(int n);
double eApprox(int n);

int main() {
    cout.precision(30);
    for (int n = 1; n <= 15; n++) {
        cout<<"n = "<<n<<'\t'<<eApprox(n)<<endl;
    }
    return 0;
}

double factorial(int n) {
    double result = 1.0;
    if (n == 0) {
        return result;
    }
    for (int i = 1; i <= n; i++) {
        result *= (double) i;
    }
    return result;
}

double eApprox(int n) {
    double result = 1;
    for (int i = 1; i <= n; i++) {
        result += (double) 1/ factorial(i);
    }
    return result;
}