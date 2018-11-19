#include<iostream>
#include "Fibonacci.h"
using namespace std;

int main() {
    cout << "Enter a number to calculate fibonacci for: ";
    int number;
    cin >> number;

    Fibonacci fibonacci(number);

    cout << "Fibonacci of " << fibonacci.getNumber() << " is "
         << fibonacci.calculateFibonacci(fibonacci.getNumber()) << endl;

}