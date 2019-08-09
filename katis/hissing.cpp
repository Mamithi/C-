#include <iostream>
using namespace std;

int main() {
  string checkString;
  cin >> checkString;
  bool check = false;
  for (int i = 0; i < checkString.size() - 1; i++) {
    if (checkString[i] == 's' and checkString[i + 1] == 's') {
      check = true;
      break;
    }
  }
  if (check) {
    cout << "hiss" << endl;
  } else {
    cout << "no hiss" << endl;
  }
  return 0;
}
