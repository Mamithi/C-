#include <iostream>
#include "Main.h"

using namespace std;

int main() {
    Main main;

    std::wcout << L"Calling Get Test method..." << std::endl;
    try{
        main.getMethod().wait();
    } catch(const std::exception &e) {
        printf("Error exception:%s\n", e.what());
    }


    return 0;
}