//
// Created by StellaShen on 2021/8/14.
//

#include <ctime>
#include <cstdlib>
#include <iostream>
#include <string>

using namespace std;

//create the real pin and declare some const variables
const string REAL_PIN = "98911";
const int SIZE = 10;
const char ZERO = '0';

//initialize the functions here
void assign_random_number(int arr[], int size);
void print_PIN_NUM(int arr[], int size);
bool check_PIN(int arr[], int size, string input, string real_password);


int main() {
    int arr[SIZE];
    string input;

    assign_random_number(arr, SIZE);

    cout<<"Please enter your PIN according to the following mapping: \n";

    print_PIN_NUM(arr, SIZE);

    cin>>input;

    if (check_PIN(arr, SIZE, input, REAL_PIN)) {
        cout<<"Your PIN is correct";
    } else {
        cout<<"Your PIN is not correct";
    }

    return 0;
}

void assign_random_number(int arr[], int size) {
    srand(time(0));

    for (int i = 0; i < size; i++) {
        arr[i] = rand() % 3 + 1;
    }
}

void print_PIN_NUM(int arr[], int size) {
    //print the PIN:
    cout<<"PIN:\t";
    for (int i = 0; i < size; i++) {
        cout<<i<<" ";
    }
    cout<<"\n";

    //print the NUM:
    cout<<"NUM:\t";
    for (int i = 0; i < size; i++) {
        cout<<arr[i]<<" ";
    }
}

bool check_PIN(int arr[], int size, string input, string real_password) {
    int n = input.length();
    int m = real_password.length();

    //if the input number does not have the same size of the real PIN, then it must be wrong
    if (n != m) {
        return false;
    }

    for (int i = 0; i < n; i++) {
        int PIN_index = real_password[i] - ZERO;
        int input_num = input[i] - ZERO;
        if (arr[PIN_index] == input_num) {
            continue;
        } else {
            return false;
        }
    }
    return true;
}
