#include <iostream>
using namespace std;

size_t getSize(double *);

int main() {
    double array[20];

    cout << "The number of bytes in the array is " << sizeof(array) << endl;

    cout << "\nThe number of bytes returned by getSize is "
        << getSize(array) << endl;
}

size_t getSize(double *ptr){
    return sizeof(ptr);
}