#include "./test-joe.h"
#include <iostream>


extern std::string name;

int main() {
    greetings(name);
    std::cout << "Hi from test-main.cpp" << std::endl;
    return 0;
}
