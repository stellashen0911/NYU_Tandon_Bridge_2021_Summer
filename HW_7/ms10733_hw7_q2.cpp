//
// Created by StellaShen on 2021/8/21.
//
#include <iostream>
#include <string>

using namespace std;

const int ALPHABETIC = 26;
const char UPPER_A = 'A';
const char LOW_A = 'a';

bool is_anagrams(string & str1, string & str2);

int main() {
    string str1;
    string str2;

    cout<<"Please enter the first string: "<<endl;
    getline(cin, str1);

    cout<<"Please enter the second string: "<<endl;
    getline(cin, str2);

    if (is_anagrams(str1, str2)) {
        cout<<"These two strings are anagrams."<<endl;
    } else {
        cout<<"These two strings are not anagrams."<<endl;
    }

    return 0;
}

bool is_anagrams(string & str1, string & str2) {
    int arr[ALPHABETIC] = {0};

    for (int i = 0; i < str1.length(); i++) {
        if((str1[i] - UPPER_A >= 0)&&(str1[i] - UPPER_A <= 25)) {
            int position = str1[i] - UPPER_A;
            arr[position] = arr[position] + 1;
        } else if ((str1[i] - LOW_A >= 0)&&(str1[i] - LOW_A <= 25)) {
            int position = str1[i] - LOW_A;
            arr[position] = arr[position] + 1;
        }
    }

    for (int i = 0; i < str2.length(); i++) {
        if((str1[i] - UPPER_A >= 0)&&(str1[i] - UPPER_A <= 25)) {
            int position = str1[i] - UPPER_A;
            arr[position] = arr[position] - 1;
        } else if ((str1[i] - LOW_A >= 0)&&(str1[i] - LOW_A <= 25)) {
            int position = str1[i] - LOW_A;
            arr[position] = arr[position] - 1;
        }
    }

    for (int i = 0; i < ALPHABETIC; i++) {
        if (arr[i] != 0) {
            return false;
        }
    }

    return true;
}