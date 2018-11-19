#include <iostream>
#include <iomanip>

using namespace std;

void printArray(int * const, const int);
void selectionSort(int * const, const int);
void swap (int * const, int *const);

int main() {
    const int arraySize  = 10;
    int a[arraySize] = { 2, 6, 4, 8, 10, 12, 89, 68, 45, 37 };

    cout << "Data items in original order\n";

    printArray(a, arraySize);

    selectionSort(a, arraySize);

    cout << "\nData items in ascending order\n";

    printArray(a, arraySize);

    cout << endl;
}

void printArray(int * const array, const int size){
    for(int i = 0; i < size; i++)
        cout << setw(4) << array[i];
}

void selectionSort(int * const array, const int size) {
    int smallest;

    for(int i = 0; i < size-1; i++){
        smallest = i;

        for(int index = i+1; index < size; index++){
            if(array[index] < array[smallest]){
                smallest = index;
            }
        }

        swap(&array[i], &array[smallest]);
    }
}

void swap(int * const element1Ptr, int * const element2Ptr){
    int hold = *element1Ptr;
    *element1Ptr = *element2Ptr;
    *element2Ptr = hold; 
}
