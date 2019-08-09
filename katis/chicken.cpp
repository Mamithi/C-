#include<iostream>
using namespace std;

int main(){
    int a, b;
    cin >> a >> b;

    b = b - a;
    
    if(b == 1){
        cout << "Dr. Chaz will have 1 piece of chicken left over!" << endl;
    }

    else if(diff == -1){
        cout << "Dr. Chaz needs 1 more piece of chicken!" << endl;
    }

    else if(diff < 0) {
        cout <<"Dr. Chaz needs " << -diff << " more pieces of chicken!" << endl;
    }

    else {
        cout << "Dr. Chaz will have " << diff << " pieces of chicken left over!" << endl;
    }
   
}