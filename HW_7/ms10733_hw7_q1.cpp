#include <iostream>
#include <string>

using namespace std;

const char UPPER_A = 'A';
const char LOWER_A = 'a';
const char SPACE = ' ';
const int DIFF = 'a' - 'A';
const int ALPHABETIC = 26;

int count_word(string& str);
void count_letter(string str);


int main() {
    string input;
    int word;

    cout<<"Please enter a line of text:"<<endl;
    getline(cin, input);

    word = count_word(input);
    cout<<word<<"\t words"<<endl;

    count_letter(input);

    return 0;
}

int count_word(string& str) {
    int word = 1;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == SPACE) {
            word++;
        }
    }
    return word;
}

void count_letter(string str) {
    int arr[ALPHABETIC];
    for (int i = 0; i < ALPHABETIC; i++) {
        arr[i] = 0;
    }

    for (int i = 0; i < str.length(); i++) {
        //if the letter is an upper case
        if ((str[i] - UPPER_A >= 0)&&(str[i] - UPPER_A <= 25)){
            //convert to lower case
            int num = str[i] + DIFF;
            //map the lower case letter to the array
            int position = num - LOWER_A;
            arr[position] = arr[position] + 1;
        } else if ((str[i] - LOWER_A >= 0)&&(str[i] - LOWER_A <= 25)){ //if the letter is lower case
            //map the lower case letter to the array
            int position = str[i] - LOWER_A;
            arr[position] = arr[position] + 1;
        }
    }

    //print out the occurrence of the letter
    for (int i = 0; i < ALPHABETIC; i++) {
        if(arr[i] != 0) {
            char letter = LOWER_A + i;
            cout<<arr[i]<<"\t"<<letter<<"\n";
        }
    }
}
