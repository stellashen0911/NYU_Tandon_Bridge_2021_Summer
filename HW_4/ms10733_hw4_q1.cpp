#include <iostream>
using namespace std;

int main() {
    //declare the input data
    int integer_a, integer_b;
    int count_a, count_b;
    int return_a, return_b;

    //section a answer
    cout<<"section a"<<endl;
    cout<<"Please enter a positive integer:";
    cin>>integer_a;
    count_a = 1;
    while (count_a != (integer_a + 1)) {
        return_a = 2 * count_a;
        cout<<return_a<<endl;
        count_a++;
    }

    //section b answer
    cout<<"section b"<<endl;
    cout<<"Please enter a positive integer:";
    cin>>integer_b;
    for (int i = 1; i < (integer_b + 1); i++) {
        return_b = 2 * i;
        cout<<return_b<<endl;
    }
    return 0;
}
