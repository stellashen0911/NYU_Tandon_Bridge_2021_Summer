//
// Created by StellaShen on 2021/7/26.
//
#include <iostream>
#include <string>

using namespace std;

const double M_F_DAY_PRICE = 0.40;
const double M_F_NIGHT_PRICE = 0.25;
const double WEEKEND_PRICE = 0.15;

int main() {
    string day_of_week;
    char separate;
    int hour, min;
    double duration;
    double total_cost;


    //enter the day of the week
    cout<<"Please enter the day of the week (ex. Monday is 'Mo', Tuesday is 'Tu'): ";
    cin>>day_of_week;
    if ((day_of_week != "Mo") && (day_of_week != "Tu") && (day_of_week != "We") && (day_of_week != "Th") && (day_of_week != "Fr") && (day_of_week != "Sa") && (day_of_week != "Su"))
    {
        cout << "Please enter a valid two character string as given";
        return 1;
    }
    //enter the time the call started
    cout<<"Please enter the time the call started in 24-hour notation, seperated by ':': ";
    cin>>hour>>separate>>min;
    //enter the length of the call in minutes
    cout<<"Please enter the length of the call in minutes: ";
    cin>>duration;

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);

    //do the calculation
    if (day_of_week == "Sa" || day_of_week == "Su") {
        total_cost = duration * WEEKEND_PRICE;
    } else {
        if (hour >= 8 && hour <= 18) {
            total_cost = duration * M_F_DAY_PRICE;
        } else {
            total_cost = duration * M_F_NIGHT_PRICE;
        }
    }

    cout<<"The cost of the call is: $"<<total_cost<<endl;

    return 0;
}

