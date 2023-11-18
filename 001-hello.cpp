// w3schools C++ tutorial
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <array>

void myRefSwap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

void myPtrSwap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// reference to an arr passed as parameter (brackets needed or it would 
// be an array of references). template used so can capture the size of 
// the array at compile time
template<typename T, size_t S>
void myRefArr(std::array<T, S>& arr) {
    for (size_t i = 0; i < S; i++) {
        arr[i] = pow(arr[i], 3);
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

// recursion, build the stack and AFTERWARDS execute as clearing stack (code blocks left on stack)
// N = 5
// 5 + Fn(4)
// 5 + 4 + Fn(3)
// 5 + 4 + 3 + Fn(2)
// 5 + 4 + 3 + 2 + Fn(1)
// 5 + 4 + 3 + 2 + 1 + Fn(0) -> 0 + 1 + 2 + 3 + 4 + 5    
void recCountUpTo(int n) {      // init
    if (n > 0) {                // check
        recCountUpTo(n - 1);    // update and recursion ABOVE code block
        std::cout << n << " ";       // code block left on stack (LIFO), executed as stack diminishes (pops)
    }
    else {
        std::cout << "0 ";
    }
}

// 
// for loop init, check and update
// for (int i = n; i > 0; i--) { code block; }
// recursion, execute up the stack (no code blocks on stack)
void recCountDownFrom(int n) {  // init
    if (n > 0) {                // check
        std::cout << n << " ";       // code block executed as stack builds up (pushes)
        recCountUpTo(n - 1);    // update and recursion BELOW code block
    }
    else {
        std::cout << "0 ";
    }
}

int main() {
    // string type
    std::string myStr = "Hello";
    myStr += " ";
    myStr.append("World");
    std::cout << myStr << std::endl;
    std::cout << "The length of myStr is: " << myStr.length()
        << "; and the size of myStr is: " << myStr.size() << std::endl;

    // iterate through string
    for (int i = 0; i < myStr.length(); i++) {
        std::cout << myStr[i] << " ";
    }
    std::cout << std::endl;

    // change first character of string
    myStr[0] = 'J';
    std::cout << myStr;

    // get user input
    std::string theName;
    std::cout << std::endl
        << "Input your name: ";
    // cin>> considers whitespace terminating char, so use getline()
    getline(std::cin, theName);
    std::cout << "What's up " << theName << std::endl;

    // math
    std::cout << "sqrt(25) = " << sqrt(25) << std::endl;
    std::cout << "round(2.6) = " << round(2.6) << std::endl;

    // if statement
    if (false) {
        std::cout << "If: It's true I tell you!" << std::endl;
    }
    else if (false) {
        std::cout << "Else If: It's true I tell you!" << std::endl;
    }
    else {
        std::cout << "Else: What else can I tell you!" << std::endl;
    }
    std::cout << "Ternary " << ((10 > 5) ? "Operator\n" : "Broken\n");

    // switch statement
    // while loop
    // do while loop
    // for loop
    // break / continue

    // length of an array
    std::string cars[4] = { "Volvo", "BMW", "Ford", "Mazda" };
    for (short i = 0; i < sizeof(cars) / sizeof(std::string); i++) {
        std::cout << cars[i] << " ";
    }
    std::cout << std::endl;

    // vector
    std::vector<int> myVec = { 100, 200, 300, 400, 500 };
    // foreach to loop ALL elements VALUES (not index) of an array, ranged loop
    for (auto i : myVec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // // vector push()
    myVec.push_back(1001);
    // .at() is safer then just using "i", it'll throw exception rather than return garbage
    for (int i = 0; i < myVec.size(); i++) {
        std::cout << myVec.at(i) << " ";
    }
    std::cout << std::endl;

    // vector pop()
    myVec.pop_back();
    myVec.pop_back();
    myVec.pop_back();
    for (auto i : myVec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // vector dynamically sized with each element initialised to zero
    int theSize = 7;
    std::vector<int> myVec2(theSize, 0);
    for (auto i : myVec2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // vector iterator
    std::vector<int>::iterator intIter;
    // begin() points to the beginning of the vector
    // end() points to ONE AFTER the end of the vector
    for (intIter = myVec2.begin(); intIter != myVec2.end(); *intIter++) {
        std::cout << *intIter << " ";
    }
    std::cout << std::endl;

    // clear / delete vectors
    myVec.clear();
    myVec2.clear();

    // structs (array holds single type, struct holds multiple types)
    struct {
        int i = 101;
        std::string s = "one hundred and one";
    } myStruct101;
    std::cout << "Struct int: " << myStruct101.i << "; struct string " << myStruct101.s << std::endl;
    // not allowed: struct101 new101;

    // struct named type (and variable declared that uses the struct type)
    struct myStructDataType {
        int i = 202;
        std::string s = "two hundred and two";
    } myStruct202;
    std::cout << "Struct int: " << myStruct202.i << "; struct string " << myStruct202.s << std::endl;

    // References and Pointers are important in C++, because they give you the ability
    // to manipulate the data in the computer's memory - which can reduce the code and
    // improve the performance.
    // These two features are one of the things that make C++ stand out from other programming
    // languages, like Python and Java.

    // references (alias)
    int a = 5;
    int& b = a;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    a++;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    // pointers
    int x = 303;
    int* ptr;
    ptr = &x;
    std::cout << "x = " << x << ", ptr = " << ptr << ", *ptr = " << *ptr << std::endl;
    (*ptr) += 7;
    std::cout << "x = " << x << ", ptr = " << ptr << ", *ptr = " << *ptr << std::endl;

    // pass references to function
    int first = 100;
    int second = 200;
    std::cout << "first = " << first << ", second = " << second << std::endl;
    std::cout << "swapping..." << std::endl;
    myRefSwap(first, second);
    std::cout << "first = " << first << ", second = " << second << std::endl;

    // pass pointers to function
    int third = 300;
    int fourth = 400;
    std::cout << "third = " << third << ", fourth = " << fourth << std::endl;
    std::cout << "swapping..." << std::endl;
    myPtrSwap(&third, &fourth);
    std::cout << "third = " << third << ", fourth = " << fourth << std::endl;

    // dynamic array for image processing
    int rows = 3;
    int cols = 3;
    // pointer to a 1-d array of the whole image
    int* myArray = new int[rows * cols];
    for (int i = 0; i < rows * cols; i++) {
        myArray[i] = i;
        std::cout << myArray[i] << " ";
    }
    std::cout << std::endl;

    // create the matrix via an array of pointers pointing to the
    // column starting positions in the 1-d image array
    int** myMatrix = new int* [rows];
    for (int r = 0; r < rows; r++) {
        myMatrix[r] = &(myArray[r * cols]);
    }
    // print the matrix
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            std::cout << myMatrix[r][c] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;

    // 2-d vector, a vector of vectors initiallised to 0
    std::vector<std::vector<int>> vecMatrix(rows, std::vector<int>(cols, 0));
    // ranged loop
    int traverse = rows * cols;
    for (int r = 0; r < rows; r++) {
        for (int c = 0; c < cols; c++) {
            vecMatrix[r][c] = --traverse;
            std::cout << vecMatrix[r][c] << " ";
        }
        std::cout << std::endl;
    }

    // passing array to function as pointer
    std::array<int, 4> newArr = { 10, 20, 30, 40 };
    myRefArr(newArr); // template argument deduction (ints, size 4)

    // recursion
    recCountUpTo(5);
    std::cout << std::endl;
    recCountDownFrom(5);
    std::cout << std::endl;

    return 0;
}
