//
// Created by StellaShen on 2021/8/8.
//

#include <iostream>
#include <string>

using namespace std;

int printMonthCalender(int numOfDays, int startingDay);
bool isLeapYear(int year);
void printYearCalender(int year, int startingDay);

int main() {
    int starting_day;
    int year;

    cout<<"Please enter the calender year: ";
    cin>>year;
    cout<<"Please enter the starting day of the year, (eg. Monday is 1, and Sunday is 7): ";
    cin>>starting_day;

    printYearCalender(year, starting_day);

    return 0;
}

int printMonthCalender(int numOfDays, int startingDay) {
    cout<<"Mon\t"<<"Tue\t"<<"Wed\t"<<"Thr\t"<<"Fri\t"<<"Sat\t"<<"Sun\t"<<endl;
    int n = startingDay;
    int x = ((8 - n) + 7 * 4) - numOfDays;
    int result = 7 - x;
    for (int i = 1; i < startingDay; i++) {
        cout<<" \t";
    }
    for(int i = 1; i <= numOfDays; i++) {
        int comp = i + startingDay - 8;
        if (comp % 7 == 0) {
            cout<<i<<"\n";
        } else {
            cout << i << "\t";
        }
    }
    cout<<endl<<endl;
    return result;
}

void printYearCalender(int year, int startingDay) {
    int end_day;

    //January
    cout<<"January "<<year<<endl;
    end_day = printMonthCalender(31, startingDay);

    //February
    cout<<"February "<<year<<endl;
    end_day = end_day % 7 + 1;
    if (isLeapYear(year)) {
        end_day = printMonthCalender(29, end_day);
    } else {
        end_day = printMonthCalender(28, end_day);
    }

    //March
    cout<<"March "<<year<<endl;
    end_day = end_day % 7 + 1;
    end_day = printMonthCalender(31, end_day);

    //April
    cout<<"April "<<year<<endl;
    end_day = end_day % 7 + 1;
    end_day = printMonthCalender(30, end_day);

    //May
    cout<<"May "<<year<<endl;
    end_day = end_day % 7 + 1;
    end_day = printMonthCalender(31, end_day);

    //June
    cout<<"June "<<year<<endl;
    end_day = end_day % 7 + 1;
    end_day = printMonthCalender(30, end_day);

    //July
    cout<<"July "<<year<<endl;
    end_day = end_day % 7 + 1;
    end_day = printMonthCalender(31, end_day);

    //August
    cout<<"August "<<year<<endl;
    end_day = end_day % 7 + 1;
    end_day = printMonthCalender(31, end_day);

    //September
    cout<<"September "<<year<<endl;
    end_day = end_day % 7 + 1;
    end_day = printMonthCalender(30, end_day);

    //October
    cout<<"October "<<year<<endl;
    end_day = end_day % 7 + 1;
    end_day = printMonthCalender(31, end_day);

    //November
    cout<<"November "<<year<<endl;
    end_day = end_day % 7 + 1;
    end_day = printMonthCalender(30, end_day);

    //December
    cout<<"December "<<year<<endl;
    end_day = end_day % 7 + 1;
    end_day = printMonthCalender(31, end_day);

}

bool isLeapYear(int year) {
    if ((year % 4 != 0) || ((year % 100 == 0) && (year % 400 != 0))){
        return false;
    }
    return true;
}
