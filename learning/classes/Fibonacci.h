#include<iostream>
#include<string>
using namespace std;


class Fibonacci {
    public:
        Fibonacci(int number){
            setNumber(number);
        }

        void setNumber(int number) {
            num = number;
        }

        int getNumber(){
            return num;
        }

        int calculateFibonacci(int a){
            if(a > 1){
                return (a * calculateFibonacci(a-1));
            } else{
                return 1;
            }            
        }

        void displayMessage() {
            cout << "Hello there" << endl;
        }
    
    private:
        int num;
};