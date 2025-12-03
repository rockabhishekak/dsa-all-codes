
#include<iostream>
using namespace std;
int factorial(int n) {
    int r=1;
    if (n == 0 || n == 1) {
        return 1;
    }
    else{
        for(int i=n;i>=1;i--   ) {
            r=r*i;
        }
    }
    return r;
}
int main() {
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;
    if (number < 0) {
        cout << "Factorial is not defined for negative numbers." << endl;
    } else {
        int result = factorial(number);
        cout << "Factorial of " << number << " is " << result << endl;
    }
    return 0;
}