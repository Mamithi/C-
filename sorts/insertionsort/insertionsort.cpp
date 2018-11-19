#include<iostream>
#include "insertionsort.h"

using namespace std;

int main() {

    Insertionsort insertionsort;

    int arr[] = { 4, 2, 19, 3, 67, 1, 48};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    cout << "Array before insertion sort " << endl;
    insertionsort.printArray(arr, arrSize);

    insertionsort.sort(arr, arrSize);

    cout << "\n\nArray after insertion sort " << endl;
    insertionsort.printArray(arr, arrSize);

    cout << "\n\n";



}