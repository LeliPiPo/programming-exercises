/* 5. Write a program that finds and prints all of the prime numbers between 3 
and 100. A prime number is a number such that 1 and itself are the only 
numbers that evenly divide it (for example, 3, 5, 7, 11, 13, 17, …).
 
 One way to solve this problem is to use a doubly nested loop. The 
outer loop can iterate from 3 to 100 while the inner loop checks to 
see if the counter value for the outer loop is prime. One way to see 
if number n is prime is to loop from 2 to n 21 and if any of these 
numbers evenly divides n, then n cannot be prime. If none of the 
values from 2 to n 21 evenly divides n, then n must be prime. (Note 
that there are several easy ways to make this algorithm more efficient.*/
 #include <iostream>
using namespace std;

int main() {
    cout << "Prime numbers between 3 and 100 are:\n";

    for (int n = 3; n <= 100; n++) {
        bool isPrime = true;

        // Check divisibility from 2 up to sqrt(n)
        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                isPrime = false; //Not prime
                break;           
            }
        }

        if (isPrime) {
            cout << n << " ";
        }
    }

    cout << endl;
    return 0;
}
