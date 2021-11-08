//
// Created by StellaShen on 2021/8/2.
//
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

void check_target(int& target, int& tried_times, int& number_of_guess, int guess, int& left, int& right, bool& success);

int main() {
    //declare some variables
    int target;
    int guess;
    int left_range = 1;
    int right_range = 100;
    int number_of_guess = 5;
    int tried_times = 0;
    bool success = false;

    //create a random number for user to guess
    srand(time(0));
    target = (rand() % 100) + 1;

    //start of the game, ask the user to input guesses
    cout<<"I thought of a number between 1 and 100! Try to guess it."<<endl;

    while (!success) {
        cout<<"Range: ["<<left_range<<","<<right_range<<"], Number of guesses left: "<<number_of_guess<<endl;
        cout<<"Your guess:";
        cin>>guess;

        //compare the guess x1 with the target number
        check_target(target, tried_times, number_of_guess, guess, left_range, right_range, success);

        cout<<endl;
    }

    return 0;
}

void check_target(int& target, int& tried_times, int& number_of_guess, int guess, int& left, int& right, bool& success){
    //check the guess time left
    if(number_of_guess == 1) {
        cout<<"Out of guesses! My number is "<<target<<endl;
        success = true;
    }else {
        //check the guess vs the target
        if (guess == target) {
            tried_times++;
            cout<<"Congrats! You guessed my number in "<<tried_times<<" guesses."<<endl;
            number_of_guess--;
            success = true;
        } else if (guess < target) {
            tried_times ++;
            cout<<"Wrong! My number is bigger."<<endl;
            number_of_guess--;
            left = guess + 1;
        } else if (guess > target) {
            number_of_guess--;
            tried_times++;
            cout<<"Wrong! My number is smaller."<<endl;
            right = guess - 1;
        }
    }

}
