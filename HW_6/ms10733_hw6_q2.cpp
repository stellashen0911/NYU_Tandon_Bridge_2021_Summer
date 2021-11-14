//
// Created by StellaShen on 2021/8/14.
//
#include <iostream>
#include <string>

using namespace std;

bool isPalindrome(string str);

int main() {
    string str;

    cout<<"Please enter a word: ";
    getline(cin, str);

    if (isPalindrome(str)) {
        cout<<str<<" is a palindrome"<<endl;
    } else {
        cout<<str<<" is not a palindrome"<<endl;
    }
    return 0;
}

bool isPalindrome(string str) {
    int size = str.length();
    int i;
    int j;

    for (i = 0, j = size - 1; i < size / 2, j > size / 2; i++, j--) {
        if (str[i] != str[j]) {
            return false;
        }
    }
    return true;
}
