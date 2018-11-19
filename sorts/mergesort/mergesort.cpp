#include<iostream>
#include "mergesort.h"
#include<string>

using namespace std;

int main() {
    Mergesort mergesort;
    int array[] = {94, 42, 50, 95, 333, 65, 54, 456, 1, 1234};
    int n = sizeof(array)/sizeof(array[0]);

    cout << "Before Merge Sort :" << endl;
    mergesort.printArray(array, n);

    mergesort.sort(array, n);

    cout << "After Merge Sort :" << endl;
    mergesort.printArray(array, n);

    return(0);
    

}