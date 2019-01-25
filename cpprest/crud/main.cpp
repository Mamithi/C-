#include <iostream>
#include "Main.h"

using namespace std;

int main() {
    Main main;

    std::wcout << L"Calling Get Async method..." << std::endl;
    main.getAsync().wait();

    return 0;
}