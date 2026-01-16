/*use of arrays*/
#include <iostream>
using namespace std;

int main() {
    int arr[50][50];
    int n;

    cout << "Enter n: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> arr[i][j];   
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i][i];  
    }


    cout << "Diagonal sum = " << sum << endl;

    return 0;
}
