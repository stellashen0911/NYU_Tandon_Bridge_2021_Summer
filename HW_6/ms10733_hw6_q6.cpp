//
// Created by StellaShen on 2021/8/15.
//
#include <iostream>

using namespace std;

const char SPACE = ' ';
const char ZERO = '0';

void change_num_to_x(string text);

int main() {
    string text;

    cout<<"Please enter a line of text: "<<endl;
    getline(cin, text);

    change_num_to_x(text);

    return 0;
}

void change_num_to_x(string text) {
    int i = 0;
    int k = text.find(SPACE, i);

    while (k != string::npos) {
        for (int j = i; j < k; j++) {
            if ((text[j] - ZERO < 0) || (text[j] - ZERO > 9)) {
                break;
            } else {
                text[j] = 'x';
            }
        }
        i = k + 1;
        k = text.find(SPACE, i);
    }
    cout<<text;
}
