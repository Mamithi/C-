#include<iostream>
#include "GradeBook.h"
using namespace std;

int main() {
    GradeBook gradeBook("Computer Science");

    gradeBook.displayMessage();

    cout << "Grade book for course: " << gradeBook.getCourseName() << endl;  
}