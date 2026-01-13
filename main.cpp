/*14. Computers normally treat time as the number of seconds from an arbitrary 
starting point called an epoch. Write a C++ program that asks the user for 
the current hour of the day (from 0 to 23), the current minute of the hour 
(from 0 to 59) and the current second of the minute (from 0 to 59). Use 
the user’s input to calculate the number of seconds since midnight that 
their time represents. If the user enters an invalid input, like 67 minutes 
for the current minutes in the hour, then ask them for that value again 
until they enter a correct value. Sample input and output is shown below.
 Enter the hour of the day: 3 
Enter the minutes of the hour: 45
 Enter the seconds passed in the current minute: 25
 Enter the seconds passed in the current minute: 90
 Enter the seconds passed in the current minute: 3
 The time in seconds since midnight is: 45903*/
#include <iostream>
using namespace std;
int main()
{
    int Hours, Minutes, Seconds;
    
    do{
    cout << "Enter the hour of the day: ";
    cin >> Hours;
     if(Hours < 0){
        cout << "try again\n";
        cin >> Hours;
    }
    }while(Hours < 0);
    
    do{
    cout << "Enter the minutes of the hour: ";
    cin >> Minutes;
    if(Minutes < 0 || Minutes > 59){
        cout << "try again\n";
        cin >> Minutes;
    }
    }while(Minutes < 0 || Minutes > 59);
    
    do{
    cout << "Enter the seconds passed in the current minute: ";
    cin >> Seconds;
      if(Seconds < 0 || Seconds > 59){
        cout << "try again\n";
        cin >> Seconds;
    }
    }while(Seconds < 0 || Seconds > 59);
    
    Seconds = (Hours * 3600) + (Minutes * 60) + Seconds;
    cout << "The time in seconds since midnight is: ";
    cout << Seconds;
    return 0;
}