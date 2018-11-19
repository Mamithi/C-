#include<iostream>
#include "bubblesort.h"

using namespace std;

int main() {

    Bubblesort bubblesort;

    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    cout << "Array before bubblesort " << endl;
    bubblesort.printArray(arr, arrSize);

    bubblesort.sort(arr, arrSize);
    cout << "\n\nArray after bubblesort " << endl;
    bubblesort.printArray(arr, arrSize);
    cout << "\n\n";


}
