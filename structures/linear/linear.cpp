#include<iostream>

using namespace std;

int search(int[], int, int);

int main() {
    int arr[] = {5, 8, 2, 45, 34, 1, 9, 45, 78};
    int size = sizeof(arr)/sizeof(arr[0]); 

    int value = 34;

    int result = search(arr, size, value);

    if(result != -1)
        cout << value << " is found at position " << result << endl;
    else
        cout << value << " is not found" << endl; 
}

int search(int arr[], int size, int value){
    for(int i = 0; i < size; i++)
        if(arr[i] == value)
            return i;

    return -1;   
}