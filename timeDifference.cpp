/* 7. Your time machine is capable of going forward in time up to 24 hours. 
The machine is configured to jump ahead in minutes. To enter the proper 
number of minutes into your machine, you would like a program that can 
take a start time (in hours, minutes, and a Boolean indicating AM or PM) 
and a future time (in hours, minutes, and a Boolean indicating AM or PM) 
and calculate the difference in minutes between the start and future time.
*/
#include <iostream>
using namespace std;

//Converts 12-hour format to 24-hour format
int to24Hour(int hours, bool isAM) {
    if (hours == 12) {
        return isAM ? 0 : 12;
    }
    return isAM ? hours : hours + 12;
}

//Converts full time (hours, minutes, isAM) to total minutes since midnight
int toTotalMinutes(int hours, int minutes, bool isAM) {
    int hour24 = to24Hour(hours, isAM);
    return hour24 * 60 + minutes;
}

//Computes difference between two times (start to future)
int computeDifference(int sh, int sm, bool sAM, int fh, int fm, bool fAM) {
    int startMinutes = toTotalMinutes(sh, sm, sAM);
    int futureMinutes = toTotalMinutes(fh, fm, fAM);

    int diff = futureMinutes - startMinutes;
    if (diff < 0) diff += 24 * 60; //Handle wrap-around midnight

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
