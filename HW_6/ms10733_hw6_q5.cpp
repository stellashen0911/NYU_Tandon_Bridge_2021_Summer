//
// Created by StellaShen on 2021/8/15.
//
#include <iostream>
#include <string>

using namespace std;

void print_first_middle(string first_name, string middle_name);

int main() {
    string Last_Name;
    string First_Name;
    string Middle_Initial;

    cout<<"Please enter your first name, middle name and last name, separate by space: "<<endl;
    cin>>First_Name>>Middle_Initial>>Last_Name;

    print_first_middle(First_Name, Middle_Initial);

    return 0;
}

void print_first_middle(string first_name, string middle_name) {
    cout<<"User, "<<first_name<<" "<<middle_name[0]<<"."<<endl;
}
