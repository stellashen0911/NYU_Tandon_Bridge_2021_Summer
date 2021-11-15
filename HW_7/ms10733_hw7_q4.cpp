//
// Created by StellaShen on 2021/8/21.
//
#include <iostream>
#include <string>
#include <vector>

using namespace std;

const char SPACE = ' ';

string* createWordsArray(string sentence, int& outWordsArrSize);

int main() {
    int size = 0;
    string sentence;
    string* ptr = nullptr;

    sentence = "you can do it again";

    ptr = createWordsArray(sentence, size);

    for (int i = 0; i < size; i++) {
        cout<<ptr[i]<<' ';
    }

    cout<<"\n"<<size<<endl;

    delete [] ptr;
    ptr = nullptr;

    return 0;
}

string* createWordsArray(string sentence, int& outWordsArrSize) {
    int start = 0;
    int count = 0;

    string* str_ptr = new string[sentence.length()];

    for(int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' ') {
            str_ptr[count++] = sentence.substr(start, i - start);
            start = i + 1;
        }
    }

    str_ptr[count++] = sentence.substr(start);
    outWordsArrSize = count;

    return str_ptr;
}