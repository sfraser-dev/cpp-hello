#include "./test-joe.h"
#include <iostream>


extern std::string name;

int main() {
    greetings(name);
    std::cout << "Fit like from test-main.cpp";
    return 0;
}