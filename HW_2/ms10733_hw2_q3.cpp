//
// Created by Shen Stella on 7/18/21.
//
#include <iostream>
using namespace std;

const int DAY_TO_HOUR = 24;
const int HOUR_TO_MIN = 60;

int main() {
    int work_days_John;
    int work_hours_John;
    int work_min_John;

    int work_days_Bill;
    int work_hours_Bill;
    int work_min_Bill;

    int total_days;
    int total_hours;
    int total_mins;

    cout<<"Please enter the number of days John has worked: ";
    cin>>work_days_John;
    cout<<"Please enter the number of hours John has worked: ";
    cin>>work_hours_John;
    cout<<"Please enter the number of minutes John has worked: ";
    cin>>work_min_John;
    cout<<"\n";

    cout<<"Please enter the number of days Bill has worked: ";
    cin>>work_days_Bill;
    cout<<"Please enter the number of hours Bill has worked: ";
    cin>>work_hours_Bill;
    cout<<"Please enter the number of minutes Bill has worked: ";
    cin>>work_min_Bill;
    cout<<"\n";

    total_mins = (work_min_Bill + work_min_John) % HOUR_TO_MIN;
    total_hours = ((work_min_Bill + work_min_John) / HOUR_TO_MIN) + (work_hours_Bill + work_hours_John) % DAY_TO_HOUR;
    total_days = ((work_hours_Bill + work_hours_John) / DAY_TO_HOUR) + (work_days_Bill + work_days_John);


    cout<<"The total time both of them worked together is: "<<total_days;
    cout<<" days, "<<total_hours<<" hours and "<<total_mins<<" minutes."<<endl;

    return 0;
}

