/*10. Computer file sizes are measured in units of bytes, or higher units like 
kilobytes, megabytes, or gigabytes. Bytes, kilobytes, megabytes, and 
gigabytes are related by the following:
 a. One kilobyte is equal to 1024 bytes.
 b. One megabyte is equal to 1024 kilobytes.
 c. One gigabyte is equal to 1024 megabytes.

 Write a program that lets the user convert the size of a file from gigabytes, 
megabytes, or kilobytes to bytes. The program should prompt the user to 
enter the size of the file and the units the file size is being measured in, 
with G for gigabytes, M for Megabytes and K for Kilobytes. The program 
should then output the size of the file in each of the corresponding 
smaller file size types. For example, if the user enters the file size in 
megabytes, the program should output the file size in kilobytes and bytes. */

#include <iostream>
using namespace std;
int main()
{
    double kilobytes = 1024.0;
    // double megabytes = 2048.0;
    // double gigabytes = 3096.0;
    int size, kiloSize, megaSize, gigaSize;
    char userUnit, convertedUnit;
    
    cout << "hii please fill in the following fields.\n";
    cout << "current size of your file ";
    cin >> size;
    cout << "\ncurrent unit of your file ";
    cin >> userUnit;
    
    userUnit = toupper(userUnit);
    
    switch(userUnit){
        case 'G': 
        megaSize = gigaSize * kilobytes;
        cout << "giga to mega " << megaSize << endl;
        kiloSize = gigaSize * 1048.5;
        cout << "giga to kilo " << kiloSize << endl;
        break;
    
       case 'M':
       kiloSize = megaSize * kilobytes;
       cout << "mega to kilo " << kiloSize << endl;
       gigaSize = megaSize / kilobytes;
       cout << "mega to giga " << gigaSize;
       break;
       
       case 'K':
       megaSize = kiloSize / kilobytes ;
       cout << "kilo to mega" << megaSize << endl;
       gigaSize = kiloSize / (kilobytes*kilobytes);
       cout << "kilo to giga" << gigaSize;
      // break;
    }
    
    return 0;
}
