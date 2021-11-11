#include <iostream>

using namespace std;

int fib(int num);

int main() {
    int num;
    int result;

    cout<<"Please enter a positive integer: ";
    cin>>num;

    result = fib(num);
    cout<<result<<endl;

    return 0;
}

int fib(int num) {
    int result;

    if ((num == 1) || (num == 2)) {
        return 1;
    }

    result = fib(num-1) + fib(num-2);
    return result;
}
