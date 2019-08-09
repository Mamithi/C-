#include<iostream>
using namespace std;

int main(int argc, char** argv){
    int perfectBoard[] = {1, 1, 2, 2, 2, 8};
    int inputArr[6];
    for(int i = 0; i < 6; i++) { 
        int number;
        cin >> number;
        inputArr[i] = number;
    }
  
    for(int i = 0; i < 6; i++) {
        
        if(inputArr[i] > perfectBoard[i]) {
            cout << inputArr[i] - perfectBoard[i];
        } 
        if(inputArr[i] < perfectBoard[i]) {
            cout << perfectBoard[i] - inputArr[i];
        } else {
            cout << 0;
        }
    }

    return 0;
}

