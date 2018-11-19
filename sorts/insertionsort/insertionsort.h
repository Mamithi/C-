#include<iostream>
#include <iomanip>

using namespace std;

class Insertionsort {
    public:
        void printArray(int arr[], int n){
            for(int i = 0; i < n; i++){
                cout << setw(4) << arr[i];
            }
        }

        void sort(int arr[], int n){
            int key, j;

            for(int i = 1; i < n; i++){
                key = arr[i];
                j = i-1;

                while(j >= 0 && arr[j] > key) {
                    arr[j+1] = arr[j];
                    j = j-1;
                }

                arr[j+1] = key;
            }
        }
};
