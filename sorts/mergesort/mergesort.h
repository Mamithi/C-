#include<iostream>

using namespace std;

class Mergesort {
    public:
        void printArray(int *array, int n){
            for(int i = 0; i < n; ++i)
                cout << array[i] << " " << flush;
            cout << endl;
        }

        void sort(int arr[], int arr_size){
            mergeSort(arr, 0, arr_size-1);
        }

        void mergeSort(int arr[], int li, int hi){
            int middle;
            if(li < hi){
                middle = (li + hi) >> 1;
                mergeSort(arr, li, middle);
                mergeSort(arr, middle+1, hi);
                merger(arr, li, middle, hi);
            }
        }

        void merger(int arr[], int li, int middle, int hi){
            int *temp = new int[hi-li+1];
            int i = li, j = middle+1;
            int k =0;

            while(i <= middle && j <= hi){
                if(arr[i] <= arr[j])
                    temp[k++] = arr[i++];
                else   
                    temp[k++] = arr[j++];
            }

            while(i <= middle)
                temp[k++] = arr[i++];

            while(j <= hi)
                temp[k++] = arr[j++];

            for(k = 0, i = li; i <= hi; ++i, ++k)
                arr[i] = temp[k];

            delete []temp;
            
        }
};