#include <iostream>
#include "quicksort.h"
#include <string>

using namespace std;

int main()
{
    Quicksort quicksort;
    int array[] = {9, 12, 9,2, 17, 1, 6, 90, 6, 89, 5};
    int length = sizeof(array)/sizeof(array[0]);

    cout << "Array before sorting: ";
    quicksort.printArray(array, length);

    quicksort.sort(array, length);

    cout << "Array after sorting: ";
    quicksort.printArray(array, length);

}