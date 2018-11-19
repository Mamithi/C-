#include <iostream>
using namespace std;

int main() {
    int number1 =5, number2 = 10, temp;

    cout << "Number before swapping." << endl;
    cout << "Number 1 = " << number1 << ", Number 2 = " << number2 << endl;

    temp = number1;
    number1 = number2;
    number2 = temp;

    cout << "NUmbers after swapping." << endl;
    cout << "Number 1 = " << number1 << ", Number 2 = " << number2 << endl;
 }