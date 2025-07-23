#include <iostream>

int main() {
    auto arrSize = 5;
    auto arr = new int[arrSize] {1, 2, 3, 4, 5};
    // leaky access of array
    for (auto i=0; i<arrSize+3; ++i) {
        std::cout << arr[i] << std::endl;
    }
    delete[] arr;
    return 0;
}
