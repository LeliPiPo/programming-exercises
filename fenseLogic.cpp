
 /*41. You have a fence that is to be 100 meters long. Your fence posts are to 
be placed every 10 feet. How many fence posts do you need? Why is 
the presence of this problem in a programming book not as silly as it 
might seem? What problem that programmers have does this question 
address?

You need to convert 100 meters to feet first.

1 meter = 3.28084 feet

So 100 meters = 328.084 feet*/
#include <iostream>
using namespace std;

int main() {
    double fence_length_feet = 328.084;
    int spacing = 10;
    int post_count = 0;

    for (double pos = 0; pos <= fence_length_feet; pos += spacing) {
        post_count++;
    }

    cout << "Number of fence posts needed: " << post_count << endl;

    return 0;
}
