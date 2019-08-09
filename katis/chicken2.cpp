#include <iostream>

using namespace std;

int main() {
    int chicken, people;
    cin >> chicken >> people;

    people -= chicken;
   

    if(people == 1) {
        cout << "Dr. Chaz will have 1 piece of chicken left over!" << endl;
    }
    else if(people == -1) {
        cout << "Dr. Chaz needs 1 more piece of chicken!" << endl;
    }
    else if(people < 0) {
        cout << "Dr. Chaz needs " << -people << " more pieces of chicken!" << endl;
    }
    else {
        cout << "Dr. Chaz will have " << people << " pieces of chicken left over!" << endl;
    }
}