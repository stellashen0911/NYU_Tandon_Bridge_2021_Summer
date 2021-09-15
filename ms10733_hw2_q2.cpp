#include <iostream>
using namespace std;

//declare some constant variables
const int NICKEL_TO_CENT = 5;
const int DIME_TO_CENT = 10;
const int QUARTER_TO_CENT = 25;
const int DOLLAR_TO_CENT = 100;

int main() {
    //declare some variables
    int total_dollars;
    int total_cents;
    int total_money_convert_to_cent;
    int number_of_Quarters;
    int number_of_Dimes;
    int number_of_Nickels;
    int number_of_pennies;

    //instruct the user to put in the raw data
    cout<<"Please enter your amount in the format of ";
    cout<<"dollars and cents separated by a space:"<<endl;
    cin>>total_dollars>>total_cents;
    cout<<total_dollars<<" dollars and "<<total_cents<<" cents are:"<<endl;

    //do some calculation to get the result
    total_money_convert_to_cent = total_dollars * DOLLAR_TO_CENT + total_cents;
    number_of_Quarters = total_money_convert_to_cent / QUARTER_TO_CENT;
    total_money_convert_to_cent -= number_of_Quarters * QUARTER_TO_CENT;
    number_of_Dimes = total_money_convert_to_cent / DIME_TO_CENT;
    total_money_convert_to_cent -= number_of_Dimes * DIME_TO_CENT;
    number_of_Nickels = total_money_convert_to_cent / NICKEL_TO_CENT;
    total_money_convert_to_cent -= number_of_Nickels * NICKEL_TO_CENT;
    number_of_pennies = total_money_convert_to_cent;

    //print out the result
    cout<<number_of_Quarters<<" quarters, "<<number_of_Dimes<<" dimes, ";
    cout<<number_of_Nickels<<" nickels and "<<number_of_pennies<<" pennies"<<endl;

    return 0;
}