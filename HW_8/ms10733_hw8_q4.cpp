//
// Created by StellaShen on 2021/8/29.
//
#include <iostream>

using namespace std;

int jump_it_min_cost(int arr[], int arrSize);

int main() {
    int arr[6] = {0, 3, 80, 60, 57, 10};
    int arrSize = 6;
    int result;
    result = jump_it_min_cost(arr, arrSize);
    cout<<result;

    return 0;
}
int jump_it_min_cost(int arr[], int arrSize) {
    int result, adj, jump;
    if (arrSize == 1) {
        result = arr[0];
        return result;
    } else if (arrSize == 2) {
        result = arr[0] + arr[1];
        return result;
    } else {
        adj = *(arr + 1);
        jump = *(arr + 2);
        if (adj < jump) {
            result = jump_it_min_cost(arr + 1, arrSize - 1);
            result += *arr;
        } else {
            result = jump_it_min_cost(arr + 2, arrSize - 2);
            result += *arr;
        }
        return result;
    }
}
