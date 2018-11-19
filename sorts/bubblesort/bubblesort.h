#include<iostream>
#include<iomanip>

using namespace std;

class Bubblesort {
    public:
        void printArray(int arr[], int size){
            for(int i = 0; i < size; i++){
                cout << setw(4) << arr[i];
            }
        }

        void sort(int arr[], int size){
            for(int i = 0; i < size; i++){
                for(int j = 0; j < size-i-1; j++)
                    if(arr[j] > arr[j+1])
                        swap(&arr[j], &arr[j+1]);                
            }
        }
    
    private:
        void swap(int *iPtr, int *jPtr){
            int temp = *iPtr;
            *iPtr = *jPtr;
            *jPtr = temp;
        }
};