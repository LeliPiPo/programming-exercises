/* 7. Your time machine is capable of going forward in time up to 24 hours. 
The machine is configured to jump ahead in minutes. To enter the proper 
number of minutes into your machine, you would like a program that can 
take a start time (in hours, minutes, and a Boolean indicating AM or PM) 
and a future time (in hours, minutes, and a Boolean indicating AM or PM) 
and calculate the difference in minutes between the start and future time.
 A time is specified in your program with three variables:
 int hours, minutes;  
bool isAM;
 For example, to represent 11:50 PM, you would store:
 hours = 11
 minutes = 50
 isAM = false;
 This means that you need six variables to store a start and future time.
 Write a program that allows the user to enter a start time and a future time. 
Include a function named computeDifference that takes the six variables 
as parameters that represent the start time and future time. Your function 
should return, as an int, the time difference in minutes. For example, 
given a start time of 11:59 AM and a future time of 12:01 PM, your 
program should compute 2 minutes as the time difference. Given a start 
time of 11:59 AM and a future time of 11:58 AM, your program should 
compute 1439 minutes as the time difference (23 hours and 59 minutes).
 You may need “AM” or “PM” from the user’s input by reading in two 
character values. (Display 2.3 illustrates character input.) Characters can 
be compared just like numbers. For example, if the variable aChar is of 
type char, then (aChar == 'A') is a Boolean expression that evaluates to 
true if aChar contains the letter A.*/
#include <iostream>
using namespace std;

// Converts 12-hour format to 24-hour format
int to24Hour(int hours, bool isAM) {
    if (hours == 12) {
        return isAM ? 0 : 12;
    }
    return isAM ? hours : hours + 12;
}

// Converts full time (hours, minutes, isAM) to total minutes since midnight
int toTotalMinutes(int hours, int minutes, bool isAM) {
    int hour24 = to24Hour(hours, isAM);
    return hour24 * 60 + minutes;
}

// Computes difference between two times (start → future)
int computeDifference(int sh, int sm, bool sAM, int fh, int fm, bool fAM) {
    int startMinutes = toTotalMinutes(sh, sm, sAM);
    int futureMinutes = toTotalMinutes(fh, fm, fAM);

    int diff = futureMinutes - startMinutes;
    if (diff < 0) diff += 24 * 60; // Handle wrap-around midnight

    return diff;
}

int main() {
    int sh, sm, fh, fm;
    char sPeriod, fPeriod;
    bool sAM, fAM;

    cout << "Enter the start time (hours minutes AM/PM): ";
    cin >> sh >> sm >> sPeriod;
    sAM = (toupper(sPeriod) == 'A');

    cout << "Enter the future time (hours minutes AM/PM): ";
    cin >> fh >> fm >> fPeriod;
    fAM = (toupper(fPeriod) == 'A');

    int diff = computeDifference(sh, sm, sAM, fh, fm, fAM);
    cout << "\nTime difference is: " << diff << " minutes." << endl;

    return 0;
}
