/* 7. A taxicab company calculates charges using a fixed $3.20 hire charge, a 
$2.05-per-kilometer charge for the distance covered, and an additional 
$0.95-per-minute charge based on the duration of the journey, in minutes. If 
the journey starts between 2300 and 0600 hours, a 15% surcharge is applied.
 Write a program that asks the user to input the duration of the journey 
(rounded up to the nearest minute), the distance traveled (in kilometers), 
and the journey start time (as a 24-hour single int value). The program 
should then output the fare that should be charged.*/
#include <iostream>
using namespace std;
int main()
{
    const double HIRE_CHARGE = 3.20;
    const double PER_KM = 2.05;
    const double PER_MINUTE = 0.95;
    const double SURCHARGE = 0.15;
   int startTime, minutes,  kilometers;
   double fare(0); 
   
   cout << "minutes \n";
   cin >> minutes;
   cout << "startTime \n";
   cin >> startTime;
   cout << "kilometers \n";
   cin >> kilometers;
   
  if(kilometers > 0){
      kilometers = kilometers * PER_KM;
  }
  else kilometers = 0;
  
  if(minutes > 0){
      minutes = minutes * PER_MINUTE;
  }
  else minutes = 0;
  
  if(startTime >= 2300 || startTime <= 0600){
      startTime = startTime * SURCHARGE;
  }
  else startTime = 0;
  
  fare = HIRE_CHARGE + kilometers + startTime + kilometers;
  cout << fare;

    return 0;
}
