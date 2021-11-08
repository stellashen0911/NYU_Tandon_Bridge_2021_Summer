//
// Created by StellaShen on 2021/8/2.
//
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, number_of_star;
    char hourglass = '*';
    char space = ' ';
    string print_space;
    string print_star;

    cout<<"Please enter a positive integer: ";
    cin>>n;

    //first half of the hourglass
    for(int i = n; i > 0; i--) {
        int j = n - i;
        number_of_star = 2 * (i - 1) + 1;
        print_space = string(j,space);
        print_star = string(number_of_star, hourglass);
        cout<<print_space<<print_star<<endl;
    }
    //second half of the hourglass
    for(int i = 1; i <= n; i++) {
        int j = n - i;
        number_of_star = 2 * (i - 1) + 1;
        print_space = string(j,space);
        print_star = string(number_of_star, hourglass);
        cout<<print_space<<print_star<<endl;
    }

    return 0;
}
