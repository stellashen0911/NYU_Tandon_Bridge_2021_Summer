//
// Created by StellaShen on 2021/8/21.
//
#include <iostream>
#include <vector>

using namespace std;

//version A
int main_arr();
int* input_num_arr(int size, int& arr_size);
int* search_target_num(int* arr, int size, int target_num, int& count_search);
bool is_show(int* arr, int size, int num);

//version B
int main_vector();
vector<int> input_num_vector();
bool is_show(vector<int> vector_arr, int size, int num);
vector<int> target_lines(vector<int> vector_arr, int size, int num);


int main() {
    main_vector();
    return 0;
}

int main_arr() {
    int size = 20;
    int array_size = 0;
    int* arr = nullptr;
    int* search_arr = nullptr;
    int search_num;
    int count_search = 0;

    arr = input_num_arr(size, array_size);

    cout<<"Please enter a number you want to search:"<<endl;
    cin>>search_num;

    if (is_show(arr, array_size, search_num)) {
        search_arr = search_target_num(arr, array_size, search_num, count_search);
        cout<<search_num<<" shows in lines ";
        for (int i = 0; i < count_search - 1; i++) {
            cout<<search_arr[i]<<", ";
        }
        cout<<search_arr[count_search - 1]<<".";
    } else {
        cout<<"The search number does not show in the sequence."<<endl;
    }


    return 0;
}

int main_vector() {
    vector<int> input_arr;
    vector<int> target_arr;
    int num;

    input_arr = input_num_vector();

    cout<<"Please enter a number you want to search:"<<endl;
    cin>>num;

    int vector_size = input_arr.size();

    if (is_show(input_arr, vector_size, num)) {
        target_arr = target_lines(input_arr, vector_size, num);
        cout<<num<<" shows in lines ";
        for (int i = 0; i < target_arr.size() - 1; i++) {
            cout<<target_arr[i]<<", ";
        }
        cout<<target_arr[target_arr.size() - 1]<<".";
    } else {
        cout<<"The search number does not show in the sequence."<<endl;
    }

    return 0;
}

int* input_num_arr(int size, int& arr_size) {
    int input_num;
    bool is_end = false;
    int* arr = new int[size];
    int count = 0;

    cout<<"Please enter a sequence of positive integers, each in a separate line."<<endl;
    cout<<"End you input by typing -1."<<endl;

    while (!is_end) {
        cin>>input_num;
        if (input_num == -1) {
            is_end = true;
        } else {
            if (count == size) { //resize the array to double size
                int* temp = new int[size*2];
                for (int i = 0; i < size; i++) {
                    temp[i] = arr[i];
                }
                delete []arr;
                size = size * 2;
                arr = temp;
            }
            arr[count] = input_num;
            count++;
        }
    }

    arr_size = count;

    return arr;
}

int* search_target_num(int* arr, int size, int target_num, int& count_search) {
    int* target_arr = new int[size];
    for(int i = 0; i < size; i++) {
        if (arr[i] == target_num) {
            target_arr[count_search++] = i;
        }
    }
    return target_arr;
}

bool is_show(int* arr, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == num) {
            return true;
        }
    }
    return false;
}

vector<int> input_num_vector() {
    vector<int> input_vector;
    bool is_end = false;
    int input;

    cout<<"Please enter a sequence of positive integers, each in a separate line."<<endl;
    cout<<"End you input by typing -1."<<endl;

    while (!is_end) {
        cin>>input;
        if (input == -1) {
            is_end = true;
        } else {
            input_vector.push_back(input);
        }
    }
    return input_vector;
}

bool is_show(vector<int> vector_arr, int size, int num) {
    for (int i = 0; i < size; i++) {
        if (vector_arr[i] == num) {
            return true;
        }
    }
    return false;
}

vector<int> target_lines(vector<int> vector_arr, int size, int num) {
    vector<int> target_line;
    for (int i = 0; i < size; i++) {
        if (vector_arr[i] == num) {
            target_line.push_back(i);
        }
    }
    return target_line;
}