/*An employee is paid at a rate of $16.78 per hour for the first 40 hours 
worked in a week. Any hours over that are paid at the overtime rate of one
and-one-half times that. From the worker’s gross pay, 6% is withheld for 
Social Security tax, 14% is withheld for federal income tax, 5% is withheld 
for state income tax, and $10 per week is withheld for union dues. If the 
worker has three or more dependents, then an additional $35 is withheld 
to cover the extra cost of health insurance beyond what the employer pays. 
Write a program that will read in the number of hours worked in a week 
and the number of dependents as input and will then output the worker’s 
gross pay, each withholding amount, and the net take-home pay for the 
week.*/

  #include <iostream>
using namespace std;

int main() {
    const double RATE = 16.78;
    const double OVERTIME_RATE = 1.5 * RATE;
    const double SS_TAX = 0.06;
    const double FEDERAL_INCOME_TAX = 0.14;
    const double STATE_INCOME_TAX = 0.05;
    const double UNION_DUES = 10.00;
    const double HEALTH_INSURANCE = 35.00;

    int hoursWorked, dependents;
    double grossPay, netPay;
    double ssWithheld, federalWithheld, stateWithheld, totalDeductions;

    cout << "Enter hours worked this week: ";
    cin >> hoursWorked;

    cout << "Enter number of dependents: ";
    cin >> dependents;

    if (hoursWorked > 40) {
        grossPay = (RATE * 40) + ((hoursWorked - 40) * OVERTIME_RATE);
    } else {
        grossPay = RATE * hoursWorked;
    }

    ssWithheld = grossPay * SS_TAX;
    federalWithheld = grossPay * FEDERAL_INCOME_TAX;
    stateWithheld = grossPay * STATE_INCOME_TAX;

    totalDeductions = ssWithheld + federalWithheld + stateWithheld + UNION_DUES;

    if (dependents >= 3) {
        totalDeductions += HEALTH_INSURANCE;
    }

    netPay = grossPay - totalDeductions;

    cout << "Gross Pay: $" << grossPay << endl;
    cout << "Social Security Tax: $" << ssWithheld << endl;
    cout << "Federal Income Tax: $" << federalWithheld << endl;
    cout << "State Income Tax: $" << stateWithheld << endl;
    cout << "Union Dues: $" << UNION_DUES << endl;

    if (dependents >= 3) {
        cout << "Health Insurance: $" << HEALTH_INSURANCE << endl;
    }

    cout << "Net Take-Home Pay: $" << netPay << endl;

    return 0;
}

  
