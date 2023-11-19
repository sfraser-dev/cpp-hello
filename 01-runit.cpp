// w3schools C++ tutorial
#include <algorithm>
#include <array>
#include <cmath>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <memory>
#include <ostream>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

template <typename T>
void printSmartUniquePtrArray(std::unique_ptr<T[]> theArray, int size,
                              int digitWidth) {
    for (std::size_t i = 0; i < size; i++) {
        std::cout << std::setfill('0') << std::setw(digitWidth) << theArray[i]
                  << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void printSmartUniquePtrMatrix(
    std::unique_ptr<std::unique_ptr<T[]>[]> theMatrix, int rows, int cols,
    int digitWidth) {
    for (std::size_t r = 0; r < rows; r++) {
        for (std::size_t c = 0; c < cols; c++) {
            std::cout << std::setfill('0') << std::setw(digitWidth)
                      << theMatrix[r][c] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template <typename T> void printRawPtrArray(T *arr, int size, int digitWidth) {
    for (std::size_t i = 0; i < size; i++) {
        std::cout << std::setfill('0') << std::setw(digitWidth) << arr[i]
                  << " ";
    }
    std::cout << std::endl;
}

template <typename T>
void printRawPtrMatrix(T **mat, int rows, int cols, int digitWidth) {
    for (std::size_t r = 0; r < rows; r++) {
        for (std::size_t c = 0; c < cols; c++) {
            std::cout << std::setfill('0') << std::setw(digitWidth) << mat[r][c]
                      << " ";
        }
        std::cout << std::endl;
    }
}

template <typename T>
void printVectorMatrix(std::vector<std::vector<T>> &vec, int rows, int cols,
                       int digitWidth) {
    for (std::size_t r = 0; r < rows; r++) {
        for (std::size_t c = 0; c < cols; c++) {
            std::cout << std::setfill('0') << std::setw(digitWidth) << vec[r][c]
                      << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

// reference to an arr passed as parameter (brackets needed or it would
// be an array of references). template used so can capture the size of
// the array at compile time
template <typename T, std::size_t S> void myRefArr(std::array<T, S> &arr) {
    for (std::size_t i = 0; i < S; i++) {
        arr[i] = pow(arr[i], 3);
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}

void myRefSwap(int &a, int &b) {
    auto temp = a;
    a = b;
    b = temp;
}

void myPtrSwap(int *a, int *b) {
    auto temp = *a;
    *a = *b;
    *b = temp;
}

// recursion, build the stack and AFTERWARDS execute as clearing stack (code
// blocks left on stack) N = 5 5 + Fn(4) 5 + 4 + Fn(3) 5 + 4 + 3 + Fn(2) 5 +
// 4 + 3 + 2 + Fn(1) 5 + 4 + 3 + 2 + 1 + Fn(0) -> 0 + 1 + 2 + 3 + 4 + 5
void recCountUpTo(int n) {     // init
    if (n > 0) {               // check
        recCountUpTo(n - 1);   // update and recursion ABOVE code block
        std::cout << n << " "; // code block left on stack (LIFO), executed
                               // as stack diminishes (pops)
    } else {
        std::cout << "0 ";
    }
}

//
// comparison with for loop: init, check and update
// for (int i = n; i > 0; i--) { code block; }
// recursion, execute up the stack (no code blocks on stack)
void recCountDownFrom(int n) { // init
    if (n > 0) {               // check
        std::cout << n
                  << " "; // code block executed as stack builds up (pushes)
        recCountDownFrom(n - 1); // update and recursion BELOW code block
    } else {
        std::cout << "0 ";
    }
}

class Vehicle {
  private:
    std::string _brand;
    std::string _model;
    short _wheels;

  public:
    Vehicle(std::string brand, std::string model, int wheels, std::string sound)
        : _brand(brand), _model(model), _wheels(wheels)  {}

    ~Vehicle() {}

    // pure virtual function makes this Vehicle class abstract
    virtual void makeSound() = 0;

    void printInfo();

    // getters and setter
    auto getBrand() { return this->_brand; }
    auto getModel() { return this->_model; }
    auto getWheels() { return this->_wheels; }
    auto setBrand(std::string brand) { this->_brand = brand; }
    auto setModel(std::string model) { this->_model = model; }
    auto setWheels(short wheels) { this->_wheels = wheels; }
};
void Vehicle::printInfo() {
    std::cout << "Brand: " << this->getBrand()
              << ", Model: " << this->getModel()
              << ", Wheels: " << this->getWheels() << std::endl;
}

class Car : public Vehicle {
  public:
    // hardcode all cars to have four wheels
    Car(std::string brand, std::string model, std::string sound)
        : Vehicle(brand, model, 4, sound) {}
    ~Car() {}

    void makeSound() override;
};
void Car::makeSound() { std::cout << "beep beep" << std::endl; }

class Motorbike : public Vehicle {
  public:
    // hardcode all motorbikes to have two wheels
    Motorbike(std::string brand, std::string model, std::string sound)
        : Vehicle(brand, model, 2, sound) {}
    ~Motorbike() {}

    void makeSound() override;
};
void Motorbike::makeSound() { std::cout << "vroom vroom" << std::endl; }

void vehicleSound(Vehicle* v) { v->makeSound(); }

int main() {
    // string type
    std::string myStr = "Hello";
    myStr += " ";
    myStr.append("World");
    std::cout << myStr << std::endl;
    std::cout << "The length of myStr is: " << myStr.length()
              << "; and the size of myStr is: " << myStr.size() << std::endl;

    // iterate through string
    for (std::size_t i = 0; i < myStr.length(); i++) {
        std::cout << myStr[i] << " ";
    }
    std::cout << std::endl;

    // change first character of string
    myStr[0] = 'J';
    std::cout << myStr;

    // get user input
    std::string theName;
    std::cout << std::endl << "Input your name: ";
    // cin>> considers whitespace terminating char, so use getline()
    std::getline(std::cin, theName);
    std::cout << "What's up " << theName << std::endl;

    // math
    std::cout << "sqrt(25) = " << sqrt(25) << std::endl;
    std::cout << "round(2.6) = " << round(2.6) << std::endl;

    // if statement
    if (false) {
        std::cout << "If: It's true I tell you!" << std::endl;
    } else if (false) {
        std::cout << "Else If: It's true I tell you!" << std::endl;
    } else {
        std::cout << "Else: What else can I tell you!" << std::endl;
    }
    std::cout << "Ternary " << ((10 > 5) ? "Operator\n" : "Broken\n");

    // switch statement
    // while loop
    // do while loop
    // for loop
    // break / continue

    // length of an array
    std::string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
    for (std::size_t i = 0; i < sizeof(cars) / sizeof(std::string); i++) {
        std::cout << cars[i] << " ";
    }
    std::cout << std::endl;

    // 1-d vector
    std::vector<int> myVec = {100, 200, 300, 400, 500};
    // foreach to loop ALL elements VALUES (not index) of an array, ranged
    // loop
    for (std::size_t i : myVec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // // vector push()
    myVec.push_back(1001);
    // .at() is safer then just using "i", it'll throw exception rather than
    // return garbage
    for (std::size_t i = 0; i < myVec.size(); i++) {
        std::cout << myVec.at(i) << " ";
    }
    std::cout << std::endl;

    // vector pop()
    myVec.pop_back();
    myVec.pop_back();
    myVec.pop_back();
    for (std::size_t i : myVec) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // vector dynamically sized with each element initialised to zero
    auto theSize = 7;
    std::vector<int> myVec2(theSize, 0);
    for (std::size_t i : myVec2) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    // vector iterator
    std::vector<int>::iterator intIter;
    // begin() points to the beginning of the vector
    // end() points to ONE AFTER the end of the vector
    // best practice should be to use iterators on containers (but vectors
    // can use [])
    for (intIter = myVec2.begin(); intIter != myVec2.end(); intIter++) {
        std::cout << *intIter << " ";
    }
    std::cout << std::endl;

    // structs (array holds single type, struct holds multiple types)
    struct {
        int i = 101;
        std::string s = "one hundred and one";
    } myStruct101;
    std::cout << "Struct int: " << myStruct101.i << "; struct string "
              << myStruct101.s << std::endl;
    // not allowed, it's not a struct named type: struct101 new101;

    // struct named type (and variable declared that uses the struct type)
    struct myStructDataType {
        int i = 202;
        std::string s = "two hundred and two";
    } myStruct202;
    std::cout << "Struct int: " << myStruct202.i << "; struct string "
              << myStruct202.s << std::endl;

    // References and Pointers are important in C++, because they give you
    // the ability to manipulate the data in the computer's memory - which
    // can reduce the code and improve the performance. These two features
    // are one of the things that make C++ stand out from other programming
    // languages, like Python and Java.

    // references (alias)
    auto a = 5;
    auto &b = a;
    std::cout << "a = " << a << ", b = " << b << std::endl;
    a++;
    std::cout << "a = " << a << ", b = " << b << std::endl;

    // raw pointers
    auto x = 303;
    auto *ptr = &x;
    std::cout << "x = " << x << ", ptr = " << ptr << ", *ptr = " << *ptr
              << std::endl;
    (*ptr) += 7;
    std::cout << "x = " << x << ", ptr = " << ptr << ", *ptr = " << *ptr
              << std::endl;

    // pass references to function
    auto first = 100;
    auto second = 200;
    std::cout << "first = " << first << ", second = " << second << std::endl;
    std::cout << "swapping..." << std::endl;
    myRefSwap(first, second);
    std::cout << "first = " << first << ", second = " << second << std::endl;
    // pass pointers to function
    auto third = 300;
    auto fourth = 400;
    std::cout << "third = " << third << ", fourth = " << fourth << std::endl;
    std::cout << "swapping..." << std::endl;
    myPtrSwap(&third, &fourth);
    std::cout << "third = " << third << ", fourth = " << fourth << std::endl;

    // raw dynamic 2-d array (matrix)
    auto rows = 3;
    auto cols = 3;
    auto traverse = rows * cols;
    // pointer to a raw 1-d array (containing full 2-d matrix as a single
    // row) C style "raw" pointer
    auto *myArray = new int[rows * cols];
    for (std::size_t i = 0; i < rows * cols; i++) {
        myArray[i] = --traverse;
    }
    printRawPtrArray<int>(myArray, rows * cols, 2);
    // create the matrix (2-d array) via an array of pointers pointing
    // to the column starting positions in the 1-d array
    // C style "raw" pointer
    auto **myMatrix = new int *[rows];
    for (std::size_t r = 0; r < rows; r++) {
        myMatrix[r] = &(myArray[r * cols]);
    }
    printRawPtrMatrix<int>(myMatrix, rows, cols, 2);
    // clean up. for each new used need a delete. for each new[] used need a
    // delete[] C style dumb pointer
    delete[] myMatrix[0];
    myArray = 0;
    delete[] myMatrix;
    myMatrix = 0;

    rows = 5;
    cols = 5;
    traverse = rows * cols;

    // "new" array created on the heap and then passed to a smart pointer's
    // constructor. works, but best not to use new (nor delete) at all in
    // modern C++ raw pointer creation was: int *myArray = new int[rows *
    // cols];
    // std::unique_ptr<int[]> myArraySmart(new int[rows * cols]);

    // smart pointer (unique) to array
    std::unique_ptr<int[]> myArraySmart(std::make_unique<int[]>(rows * cols));
    for (std::size_t i = 0; i < rows * cols; i++) {
        myArraySmart[i] = i;
    }
    printSmartUniquePtrArray<int>(std::move(myArraySmart), rows * cols, 2);

    // 2-d array (matrix) without new keyword (make_unique() function instead)
    std::unique_ptr<std::unique_ptr<int[]>[]> smartPtr2D;
    std::unique_ptr<int[]> smartPtr1D;
    traverse = 0;
    // create an array of unique pointers that point to integers
    // these will point to the "row starts"
    smartPtr2D = std::make_unique<std::unique_ptr<int[]>[]>(rows);
    for (std::size_t i = 0; i < rows; i++) {
        // create a unique pointer that points to an array of integers
        smartPtr1D = std::make_unique<int[]>(cols);
        // fill the array with integers
        for (std::size_t j = 0; j < cols; j++) {
            smartPtr1D[j] = traverse++;
        }
        // move / copy the pointer from this "row" X to the 2d array at
        // position X the "2d" array (really 1d) will now contain at its
        // index X a pointer to elements from "row" X thus giving a "2d"
        // representation of the data
        smartPtr2D[i] = std::move(smartPtr1D);
    }
    printSmartUniquePtrMatrix<int>(std::move(smartPtr2D), rows, cols, 2);

    rows = 6;
    cols = 6;
    traverse = 0;
    // 2-d array (matrix) without new keyword, tidied up code
    std::unique_ptr<std::unique_ptr<int[]>[]> myUniqueMatrix;
    myUniqueMatrix = std::make_unique<std::unique_ptr<int[]>[]>(rows);
    std::unique_ptr<int[]> myUniqueArrayTemp;
    for (std::size_t r = 0; r < rows; r++) {
        myUniqueArrayTemp = std::make_unique<int[]>(rows * cols);
        for (std::size_t c = 0; c < cols; c++) {
            myUniqueArrayTemp[c] = traverse++;
        }
        myUniqueMatrix[r] = std::move(myUniqueArrayTemp);
    }
    printSmartUniquePtrMatrix<int>(std::move(myUniqueMatrix), rows, cols, 2);

    rows = 7;
    cols = 7;
    traverse = rows * cols;
    // 2-d vector, a vector of vectors initiallised to 0
    // size is being dynamically allocated so need to use ::vector (and not
    // ::array)
    std::vector<std::vector<int>> vecMatrix(rows, std::vector<int>(cols, 0));
    // ranged loop
    for (std::size_t r = 0; r < rows; r++) {
        for (std::size_t c = 0; c < cols; c++) {
            vecMatrix[r][c] = --traverse;
        }
    }
    printVectorMatrix<int>(vecMatrix, rows, cols, 2);

    // passing std::array to function as reference
    std::array<int, 4> stlArr = {10, 20, 30, 40};
    myRefArr(stlArr); // template argument deduction (ints, size 4)

    // recursion
    recCountUpTo(5);
    std::cout << std::endl;
    recCountDownFrom(5);
    std::cout << std::endl;

    // classes
    Car car("Honda", "Civic", "car beep beep");
    car.printInfo();
    car.setBrand("Ford");
    car.setModel("Focus");
    car.printInfo();
    Motorbike motorbike("Harley", "Fat Boy", "vroom vroom");
    motorbike.printInfo();

    // polymorphism
    vehicleSound(&car);
    vehicleSound(&motorbike);

    return 0;
}
