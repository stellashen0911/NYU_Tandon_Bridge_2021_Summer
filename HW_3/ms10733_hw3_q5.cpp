//
// Created by StellaShen on 2021/7/26.
//
#include <iostream>
#include <string>

using namespace std;

const double P_TO_KG = 0.453592;
const double INCH_TO_M = 0.0254;
const double UNDER_WEIGHT = 18.5;
const double OVER_WEIGHT = 25.0;
const double OBESE = 30.0;

int main() {
    double weight_p, height_inch, weight_kg, height_m;
    double bmi_value;
    string status;

    //user input valid data
    cout<<"Please enter weight (in pounds): ";
    cin>>weight_p;
    if (weight_p <= 0) {
        cout<<"Please enter a valid height.";
        cin>>weight_p;
    }
    cout<<"Please enter height (in inches): ";
    cin>>height_inch;
    if (height_inch <= 0) {
        cout<<"Please enter a valid height.";
        cin>>height_inch;
    }

    //convert the pound and inch to kg and meters
    weight_kg = weight_p * P_TO_KG;
    height_m = height_inch * INCH_TO_M;

    //calculate the BMI value
    bmi_value = weight_kg / (height_m * height_m);

    if (bmi_value < UNDER_WEIGHT) {
        status = "Underweight";
    } else if (bmi_value >= UNDER_WEIGHT && bmi_value < OVER_WEIGHT) {
        status = "Normal";
    } else if (bmi_value >= OVER_WEIGHT && bmi_value < OBESE) {
        status = "Overweight";
    } else {
        status = "Obese";
    }

    //return the result bmi status
    cout<<"The weight status is: "<<status<<endl;

    return 0;
}
