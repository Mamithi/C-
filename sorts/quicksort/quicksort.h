#include <iostream>
#include <string>

using namespace std;

class Quicksort
{
  public:
    Quicksort(){
    }

    void sort(int inputArray[], int length){
        quickSort(inputArray, 0, length-1);
    }

    void quickSort(int arr[], int li, int hi){
        if(li < hi){
            int index = partition(arr, li, hi);
            quickSort(arr, li, index-1);
            quickSort(arr, index+1, hi);
        }
    }

    int partition(int arr[], int li, int hi){
        int t = random(li, hi);
        swap(arr[t], arr[hi]);

        int index = li-1;
        int key = arr[hi];
        for(int i = li; i < hi; i++){
            if(arr[i] <= key)
                swap(arr[++index], arr[i]);
        }
        swap(arr[++index], arr[hi]);
        return index;
    }

    inline void swap(int &a, int &b){
        int k = a;
        a = b;
        b = k;
    }

    inline int random(int a, int b){
        int size = b - a + 1;
        return (a + rand()%size);
    }

    void printArray(int inputArray[], int length)
    {
        for (int i = 0; i < length; i++)
            cout << inputArray[i] << ", " << flush;
        cout << endl;
    }
    
};