//
// Created by StellaShen on 2021/8/8.
//
#include <iostream>
#include <cmath>

using namespace std;

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs);
bool isPerfect(int num);

int main() {
    int M;

    cout<<"Please enter a positive integer number that is greater or equal to 2: ";
    cin>>M;

    //Prints all the perfect numbers between 2 and M.
    cout<<"The perfect numbers in the range of 2 and "<<M<<" are: "<<endl;
    for (int i = 2; i <= M; i++) {
        if (isPerfect(i)){
            cout<<i<<endl;
        }
    }
    cout<<endl;

    //Prints all pairs of amicable numbers that are between 2 and M
    cout<<"The pairs of amicable numbers in the range of 2 and "<<M<<" are: "<<endl;
    for (int i = 2; i <= M; i++) {
        int properDivisor_1 = 0;
        int divisorSum_1 = 0;
        analyzeDivisors(i, properDivisor_1, divisorSum_1);
        int properDivisor_2 = 0;
        int divisorSum_2 = 0;
        analyzeDivisors(divisorSum_1, properDivisor_2, divisorSum_2);
        if ((divisorSum_2 == i) && (divisorSum_1 <= M) && (i != divisorSum_1)){
            cout<< i <<" , "<< divisorSum_1 <<endl;
        }
    }

    return 0;
}

void analyzeDivisors(int num, int& outCountDivs, int& outSumDivs) {
    for (int i = 1; i < sqrt(num); i++) {
        if (num % i == 0) {
            outCountDivs += 1;
            outSumDivs += i;
        }
    }

    for (int i = sqrt(num); i > 1; i--) {
        if (num % i == 0) {
            outCountDivs += 1;
            outSumDivs += num / i;
        }
    }

}

bool isPerfect(int num) {
    int sum = 0;
    int count_divisor = 0;
    analyzeDivisors(num, count_divisor, sum);
    if (sum == num) {
        return true;
    } else {
        return false;
    }
}