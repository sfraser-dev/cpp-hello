// w3schools C++ tutorial and Udemy C++ Buchalka course
#include <algorithm>
#include <array>
#include <assert.h>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <ctype.h>
#include <exception>
#include <filesystem>
#include <fstream>
#include <iomanip> //setw setfill setprecision
#include <iostream>
#include <limits>
#include <memory>
#include <ostream>
#include <stdint.h>
#include <string>
#include <utility>
#include <vector>

// using all of namespace std is bad practice. qualifying exactly what I'm using
using std::cerr;
using std::cin;
using std::cout;
using std::endl;
using std::perror;

// print an array pointed to by a smart unique pointer
template <typename T>
void printSmartUniquePtrArray(std::unique_ptr<T[]> theArray, int size,
                              int digitWidth) {
    for (std::size_t i = 0; i < size; i++) {
        // formatting the output nicely
        cout << std::setfill('0') << std::setw(digitWidth) << theArray[i]
             << " ";
    }
    cout << endl;
}

// print a matrix pointed to by smart unique pointers
template <typename T>
void printSmartUniquePtrMatrix(
    std::unique_ptr<std::unique_ptr<T[]>[]> theMatrix, int rows, int cols,
    int digitWidth) {
    for (std::size_t r = 0; r < rows; r++) {
        for (std::size_t c = 0; c < cols; c++) {
            // formatting the output nicely
            cout << std::setfill('0') << std::setw(digitWidth)
                 << theMatrix[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// old style: print array pointed to by a raw pointer
template <typename T> void printRawPtrArray(T *arr, int size, int digitWidth) {
    for (std::size_t i = 0; i < size; i++) {
        // formatting the output nicely
        cout << std::setfill('0') << std::setw(digitWidth) << arr[i] << " ";
    }
    cout << endl;
}

// old style: print matrix pointed to by raw pointers
template <typename T>
void printRawPtrMatrix(T **mat, int rows, int cols, int digitWidth) {
    for (std::size_t r = 0; r < rows; r++) {
        for (std::size_t c = 0; c < cols; c++) {
            // formatting the output nicely
            cout << std::setfill('0') << std::setw(digitWidth) << mat[r][c]
                 << " ";
        }
        cout << endl;
    }
}

// print a matrix made up of std::vectors
template <typename T>
void printVectorMatrix(std::vector<std::vector<T>> &vec, int rows, int cols,
                       int digitWidth) {
    for (std::size_t r = 0; r < rows; r++) {
        for (std::size_t c = 0; c < cols; c++) {
            // formatting the output nicely
            cout << std::setfill('0') << std::setw(digitWidth) << vec[r][c]
                 << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// reference to an arr passed as parameter (brackets needed or it would
// be an array of references). template used so can capture the size of
// the array at compile time
template <typename T, std::size_t S> void myRefArr(std::array<T, S> &arr) {
    for (std::size_t i = 0; i < S; i++) {
        arr[i] = pow(arr[i], 3);
        cout << arr[i] << " ";
    }
    cout << endl;
}

// swap using references
void myRefSwap(int &a, int &b) {
    auto temp = a;
    a = b;
    b = temp;
}

// swap using pointers
void myPtrSwap(int *a, int *b) {
    auto temp = *a;
    *a = *b;
    *b = temp;
}

// recursion, build the stack and AFTERWARDS execute as clearing stack (code
// blocks left on stack)
// N = 5
// 5 + Fn(4)
// 5 + 4 + Fn(3)
// 5 + 4 + 3 + Fn(2)
// 5 + 4 + 3 + 2 + Fn(1)
// 5 + 4 + 3 + 2 + 1 + Fn(0) -> code block execute -> 0 + 1 + 2 + 3 + 4 + 5
void recCountUpTo(int n) {   // init
    if (n > 0) {             // check
        recCountUpTo(n - 1); // update and recursion ABOVE code block
        cout << n << " ";    // code block left on stack (LIFO), executed
                             // as stack diminishes (pops)
    } else {
        cout << "0 ";
    }
}

// code block executed -> 5
// code block executed -> 4
// code block executed -> 3
// code block executed -> 2
// code block executed -> 1
// code block executed -> 0 -> all blocks executed -> done
// comparison with for loop: init, check and update
// for (int i = n; i > 0; i--) { code block; }
// recursion, execute up the stack (no code blocks on stack)
void recCountDownFrom(int n) { // init
    if (n > 0) {               // check
        cout << n << " "; // code block executed as stack builds up (pushes)
        recCountDownFrom(n - 1); // update and recursion BELOW code block
    } else {
        cout << "0 ";
    }
}

class Vehicle {
  private:
    std::string _brand;
    std::string _model;
    short _wheels;
    std::string _sound;

  public:
    Vehicle(std::string brand, std::string model, int wheels, std::string sound)
        : _brand(brand), _model(model), _wheels(wheels), _sound(sound) {}

    // Vehicle is an abstract class so need an virtual destructor
    virtual ~Vehicle() = 0;

    // pure virtual function makes this Vehicle class abstract
    virtual void makeSound() = 0;

    void printInfo();

    // getters and setter
    auto getBrand() { return this->_brand; }
    auto getModel() { return this->_model; }
    auto getWheels() { return this->_wheels; }
    auto getSound() { return this->_sound; }
    auto setBrand(std::string brand) { this->_brand = brand; }
    auto setModel(std::string model) { this->_model = model; }
    auto setWheels(short wheels) { this->_wheels = wheels; }
    auto setSound(std::string sound) { this->_sound = sound; }
};
void Vehicle::printInfo() {
    cout << "Brand: " << this->getBrand() << ", Model: " << this->getModel()
         << ", Wheels: " << this->getWheels() << ", Sound: " << this->getSound()
         << endl;
}
// virtual destructor definition
Vehicle::~Vehicle() {}

class Car : public Vehicle {
  public:
    // hardcode all cars to have four wheels
    Car(std::string brand, std::string model, std::string sound)
        : Vehicle(brand, model, 4, sound) {}
    ~Car() {}

    // overriding function from parent class
    void makeSound() override;
};
void Car::makeSound() { cout << this->getSound() << endl; }

class Motorbike : public Vehicle {
  public:
    // hardcode all motorbikes to have two wheels
    Motorbike(std::string brand, std::string model, std::string sound)
        : Vehicle(brand, model, 2, sound) {}
    ~Motorbike() {}

    // overriding function from parent class
    void makeSound() override;
};
void Motorbike::makeSound() { cout << this->getSound() << endl; }

// function overloading (take Vehicles, so Car and Motorbikes valid)
void vehicleSoundPassByReference(Vehicle &vehicle) { vehicle.makeSound(); }
void vehicleSoundPassByPointer(std::shared_ptr<Vehicle> vehicle) {
    vehicle->makeSound();
}

// hashing a string to an int via a consexpr recursive function
// so can use string expressions in c++ switch
// constexpr functions are evaluated at compile time, ie: calcualted constants
// use constexpr instead of macros
constexpr unsigned int myStr2int(const char *str, int h = 0) {
    return !str[h] ? 5381 : (myStr2int(str, h + 1) * 33) ^ str[h];
}
constexpr long myVal() { return LONG_MAX / 10; }

int main() {
    // string type
    std::string myStr = "Hello";
    myStr += " ";
    myStr.append("World");
    cout << myStr << endl;
    // string and length are exactly the same (both exist for easy of use)
    cout << "The length of myStr is: " << myStr.length()
         << "; and the size of myStr is: " << myStr.size() << endl;

    // iterate through string
    for (std::size_t i = 0; i < myStr.length(); i++) {
        cout << myStr[i] << " ";
    }
    cout << endl;

    // change first character of string
    myStr[0] = 'J';
    cout << myStr << endl;

    // get user input string
    std::string name;
    cout << "Input your name: ";
    // cin>> considers whitespace terminating char, so use getline()
    std::getline(cin, name);
    cout << "What's up " << name << endl;

    // taking advantage of cin considering whitespace as terminating character
    int yyy, zzz;
    cout << "Input two ints separeted by whitespace: ";
    cin >> yyy >> zzz;
    cout << "you typed " << yyy << " and " << zzz << endl;

    int numIn1;
    cout << "Input an int to continue: ";
    cin >> numIn1;
    while (cin.fail()) {
        cin.clear();
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        cout << "That's not an int, please try again: ";
        cin >> numIn1;
    }

    // get user input integer
    // By default, C++ streams don't throw upon ill-formed input: it isn't
    // exceptional that input is wrong. It is normal. The C++ approach to
    // indicate input failure is to put the stream into failure state
    int numIn2; // integer input expected as writing to an int, cin knows this
    cout << "Input an int: ";
    cin >> numIn2;
    // cin failure template
    while (cin.fail()) {
        // clear cin as it's in failure state
        cin.clear();
        // ignore offending characters by ignoring everything
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // attempt to get the user input again
        cout << "That's not an int, please try again: ";
        cin >> numIn2;
    }

    cout << "You input integer: " << endl;

    // math
    cout << "sqrt(25) = " << sqrt(25) << endl;
    cout << "round(2.6) = " << round(2.6) << endl;

    // four main different ways of initializing (plus overlaps)
    int w = 1;
    int x(2);
    int y{3};
    auto z = 4;
    auto xx(22);
    auto yy{33};
    cout << "w=" << w << ", x=" << x << ", y=" << y << ", z=" << z
         << ", xx=" << xx << ", yy=" << yy << endl;

    // if statement
    if (false) {
        cout << "If: It's true I tell you!" << endl;
    } else if (false) {
        cout << "Else If: It's true I tell you!" << endl;
    } else {
        cout << "Else: What else can I tell you!" << endl;
    }
    cout << "Ternary " << ((10 > 5) ? "Operator\n" : "Broken\n");

    // in c++, the switch expression cannot be a string (just an integer)
    auto day = 9;
    switch (day) {
    case 1:
        cout << "Monday" << endl;
        break;
    case 2:
        cout << "Tuesday" << endl;
        break;
    case 3:
        cout << "Wednesday" << endl;
        break;
    case 4:
        cout << "Thursday" << endl;
        break;
    case 5:
        cout << "Friday" << endl;
        break;
    case 6:
        cout << "Saturday" << endl;
        break;
    case 7:
        cout << "Sunday" << endl;
        break;
    default:
        cerr << "Warning: unknown day of the week" << endl;
    }

    // using constexpr function to get string hash int values at compile time
    // (quasi constants)
    switch (myStr2int("Jeff")) {
    case myStr2int("Linda"):
        cout << "Hi Linda" << endl;
        break;
    case myStr2int("Jeff"):
        cout << "Hi Jeff" << endl;
        break;
    case myStr2int("Gary"):
        cout << "Hi Gary" << endl;
        break;
    default:
        cout << "Error: name unknown" << endl;
    }

    // assert for debugging, often used instead of expensive exeptions
    auto pp = 5;
    auto *pp_ptr = &pp;
    // proceed if true (switch off / remove asserts via #define NDEBUG for
    // Release)
    assert(pp_ptr != NULL);
    cout << "pp = " << pp << ", pp_ptr = " << pp_ptr
         << ", *pp_ptr = " << *pp_ptr << endl;
    std::getline(cin, name);
    // exceptions - try, throw, catch, elipses(...),
    try {
        auto age = 15;
        if (age >= 18) {
            cout << "Welcome to the club" << endl;
        } else {
            // throw (int) 505;
            // throw (short)505;
            // throw std::runtime_error("runtime error");
            throw "ff3... elipses... catch all...kf3l&*(d32378kj";
        }
    } catch (int num) {
        cout << "Int: Access denied - too young" << endl;
        cout << "Int: Error: " << num << endl;
    } catch (short num) {
        cout << "Short: Access denied - too young" << endl;
        cout << "Short: Error: " << num << endl;
    } catch (std::exception &e) {
        cout << "Exception e: Access denied - too young" << endl;
        cout << "Exception e: Error: " << e.what() << endl;
    } catch (...) {
        // elipses ... mean catch all
        cout << "...: Access denied - too young" << endl;
        cout << "...: Error: ..." << endl;
    }

    // length of an array
    std::string cars[4] = {"Volvo", "BMW", "Ford", "Mazda"};
    for (std::size_t i = 0; i < sizeof(cars) / sizeof(std::string); i++) {
        cout << cars[i] << " ";
    }
    cout << endl;

    // 1-d vector
    std::vector<int> myVec = {100, 200, 300, 400, 500};
    // foreach to loop ALL elements VALUES (not index) of an array, ranged
    // loop
    for (std::size_t i : myVec) {
        cout << i << " ";
    }
    cout << endl;

    // vector push()
    myVec.push_back(1001);
    // .at() is safer then just using "i", it'll throw exception rather than
    // return garbage. Using [] with vectors has no bounds checking
    for (std::size_t i = 0; i < myVec.size(); i++) {
        cout << myVec.at(i) << " ";
    }
    cout << endl;

    // vector pop()
    myVec.pop_back();
    myVec.pop_back();
    myVec.pop_back();
    for (std::size_t i : myVec) {
        cout << i << " ";
    }
    cout << endl;

    // vector dynamically sized with each element initialised to zero
    auto theSize = 7;
    std::vector<int> myVec2(theSize, 0);
    for (std::size_t i : myVec2) {
        cout << i << " ";
    }
    cout << endl;

    // vector iterator
    std::vector<int>::iterator intIter;
    // begin() points to the beginning of the vector
    // end() points to ONE AFTER the end of the vector
    // best practice should be to use iterators on containers (but vectors
    // can use [])
    for (intIter = myVec2.begin(); intIter != myVec2.end(); intIter++) {
        cout << *intIter << " ";
    }
    cout << endl;

    // structs (array holds single type, struct holds multiple types)
    struct {
        int i = 101;
        std::string s = "one hundred and one";
    } myStruct101;
    cout << "Struct int: " << myStruct101.i << "; struct string "
         << myStruct101.s << endl;
    // struct101 new101; not allowed, it's not a struct named type

    // struct named type (and variable declared that uses the struct type)
    struct myStructDataType {
        int i = 202;
        std::string s = "two hundred and two";
    } myStruct202;
    cout << "Struct int: " << myStruct202.i << "; struct string "
         << myStruct202.s << endl;
    myStructDataType newStruct202;
    cout << "Struct int: " << newStruct202.i << "; struct string "
         << newStruct202.s << endl;

    // References and Pointers are important in C++, because they give you
    // the ability to manipulate the data in the computer's memory - which
    // can reduce the code and improve the performance. These two features
    // are one of the things that make C++ stand out from other programming
    // languages, like Python and Java.

    // references (alias). a reference IS the object. must be initialized,
    // cannot be reassigned, cannot be null. a little bit like a const pointer.
    // cleaner code, auto dereferencing, safer to use.
    auto a = 5;
    auto &b = a;
    cout << "a = " << a << ", b = " << b << endl;
    a++;
    cout << "a = " << a << ", b = " << b << endl;

    // raw pointers. pointers have their own identiy. don't need to be
    // initialised, can be reassigned, can be null.
    auto xxxx = 303;
    auto *ptr = &xxxx;
    cout << "xxxx = " << xxxx << ", ptr = " << ptr << ", *ptr = " << *ptr
         << endl;
    (*ptr) += 7;
    cout << "xxxx = " << xxxx << ", ptr = " << ptr << ", *ptr = " << *ptr
         << endl;

    // pass references to function
    auto first = 100;
    auto second = 200;
    cout << "first = " << first << ", second = " << second << endl;
    cout << "swapping..." << endl;
    myRefSwap(first, second);
    cout << "first = " << first << ", second = " << second << endl;
    // pass pointers to function
    auto third = 300;
    auto fourth = 400;
    cout << "third = " << third << ", fourth = " << fourth << endl;
    cout << "swapping..." << endl;
    myPtrSwap(&third, &fourth);
    cout << "third = " << third << ", fourth = " << fourth << endl;

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
    // clean up. for each new used need a delete.
    // for each new[] used need a delete[]
    delete[] myMatrix[0];
    myArray = 0;
    delete[] myMatrix;
    myMatrix = 0;

    rows = 5;
    cols = 5;
    traverse = rows * cols;

    // "new" array created on the heap and then passed to a smart pointer's
    // constructor. works, but best not to use new (nor delete) at all in
    // modern C++
    // std::unique_ptr<int[]> myArraySmart(new int[rows * cols]);
    // for comparison, raw pointer creation was:
    // int *myArray = new int[rows * cols];
    // modern C++: stl: vector, string
    // modern C++ uses vectors, not arrays

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
    // create an array of unique pointers that each point to the start
    // of a smart pointer array of ints - these will be the "row starts"
    smartPtr2D = std::make_unique<std::unique_ptr<int[]>[]>(rows);
    for (std::size_t i = 0; i < rows; i++) {
        // create a unique pointer that points to an array of integers
        smartPtr1D = std::make_unique<int[]>(cols);
        // fill the array with integers
        for (std::size_t j = 0; j < cols; j++) {
            smartPtr1D[j] = traverse++;
        }
        // move the pointer from this "row" X to the 2d array at
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
    cout << endl;
    recCountDownFrom(5);
    cout << endl;

    // honda is a Car instance on the main function's stack
    Car honda("Honda", "Civic", "beep beep honda");
    honda.printInfo();
    // harley is a Motorbike instance on the main function's stack
    Motorbike harley("Harley", "Fat Boy", "vroom vroom harley");
    harley.printInfo();

    // polymorphism, different sub-types behave differently
    // argument to function is a reference (alias) to a Vehicle type
    vehicleSoundPassByReference(honda);  // honda is a Vehicle (Car)
    vehicleSoundPassByReference(harley); // harley is a Vehicle (Motorbike)

    // polymorphism with SHARED smart pointers
    // argument to function is a shared smart pointer of type Vehicle
    std::shared_ptr<Car> voltswagon(std::make_shared<Car>(
        "Voltswagon", "Golf", "smart pointer shared: beep beep voltswagon"));
    vehicleSoundPassByPointer((voltswagon));
    std::shared_ptr<Motorbike> suzuki(std::make_shared<Motorbike>(
        "Suzuki", "GSX-S1000", "smart pointer shared: vroom vroom suzuki"));
    vehicleSoundPassByPointer((suzuki));

    // smart pointer ferrari should be used syntaxically just like a raw pointer
    std::shared_ptr<Car> ferrari(std::make_shared<Car>(
        "Ferrari", "F40", "smart pointer shared: beep beep ferrari"));
    vehicleSoundPassByReference(*ferrari);
    vehicleSoundPassByPointer(ferrari);

    // write to file via output stream
    std::string filename = "zout.txt";
    std::ofstream fhOut(filename);
    fhOut << "1. Hi there\n2. How are you?\n3. Time to go, bye." << endl;
    fhOut.close();

    // read from file via input stream and getline()
    std::ifstream fhIn(filename);
    std::string myString;
    // reading the file one line at a time
    while (std::getline(fhIn, myString)) {
        cout << myString << endl;
    }
    fhIn.close();
    // delete file
    try {
        if (std::filesystem::remove(filename))
            std::cout << "file " << filename << " deleted.\n";
        else
            std::cout << "file " << filename << " not found.\n";
    } catch (const std::filesystem::filesystem_error &err) {
        std::cout << "filesystem error: " << err.what() << '\n';
    }
    // attempt to open deleted file to check its existance
    std::ifstream fileOpened(filename);
    if (fileOpened.good()) {
        char formattedErrorMessageBuffer[100];
        int retVal, bufferSize = 100;
        const char *filenameCharPtr = filename.c_str();

        // format an error message
        retVal = snprintf(formattedErrorMessageBuffer, bufferSize,
                          "error: failed to delete %s", filenameCharPtr);
        if ((retVal <= 0) || (retVal >= bufferSize)) {
            cout << "snprintf: error writing to buffer" << endl;
        }
        perror(formattedErrorMessageBuffer);
        return EXIT_FAILURE;
    }

    // climits / cfloat / sizeof (type)
    cout << "size of char is " << sizeof(char) << " bytes" << endl;
    cout << "size of short is " << sizeof(short) << " bytes" << endl;
    cout << "size of int is " << sizeof(int) << " bytes" << endl;
    cout << "size of unsigned int is " << sizeof(unsigned int) << " bytes"
         << endl;
    cout << "size of long is " << sizeof(long) << " bytes" << endl;
    cout << "size of long long is " << sizeof(long long) << " bytes" << endl;
    cout << "size of float is " << sizeof(float) << " bytes" << endl;
    cout << "size of double is " << sizeof(double) << " bytes" << endl;
    cout << "size of long double is " << sizeof(long double) << " bytes"
         << endl;

    // macros for sizes
    cout << "size of CHAR_MAX is " << CHAR_MAX << endl;
    cout << "size of INT16_MAX is " << INT16_MAX << endl;
    cout << "size of INT32_MAX is " << INT32_MAX << endl;
    cout << "size of INT64_MAX is " << INT64_MAX << endl;
    cout << "size of SHRT_MAX is " << SHRT_MAX << endl;
    cout << "size of LONG_MAX is " << LONG_MAX << endl;
    cout << "size of LLONG_MAX is " << LLONG_MAX << endl;

    // constants (const, preprocessor, enum, constexpr)
    const int myConst = 12; // const
    cout << "myConst = " << myConst << endl;
    enum year { jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec };
#define MYCONST 12 // preprocessor macro constant
    cout << "MYCONST preprocessor = " << MYCONST << endl;
    for (std::size_t i = jan; i <= dec; i++) {
        cout << "i = " << i << endl;
    }
    long myval = myVal(); // constexpr
    cout << "constexpr: LONG_MAX = " << LONG_MAX << ", myval = " << myval
         << endl;

    // arrays
    int test_scores0[5];               // junk
    int test_scores1[]{1, 2, 3, 4, 5}; // array size 5 {1,2,3,4,5}
    int test_scores2[5]{1, 2};         // array size 5 {1,2,0,0,0}
    const int myfive{5};
    int test_scores3[myfive]{0}; // array size 5 {0,0,0,0,0}
    cout << "test_scores0: (junk)" << endl;
    for (std::size_t i = 0; i < 5; i++) {
        cout << test_scores0[i] << " ";
    }
    cout << endl;
    cout << "test_scores1:" << endl;
    for (std::size_t i = 0; i < 5; i++) {
        cout << test_scores1[i] << " ";
    }
    cout << endl;
    cout << "test_scores2:" << endl;
    for (std::size_t i = 0; i < 5; i++) {
        cout << test_scores2[i] << " ";
    }
    cout << endl;
    cout << "test_scores3:" << endl;
    // range based for loop
    for (std::size_t elem : test_scores3) {
        cout << elem << " ";
    }
    cout << endl;

    // range based for loop
    for (char ch : "This is a test") {
        if (ch == ' ') {
            cout << "\t";
        } else {
            cout << (char)toupper(ch);
        }
    }
    cout << endl;

    std::string mystr1 = "This is a test";
    cout << mystr1.substr(0, 4) << endl;
    std::string mystr2 = mystr1;
    reverse(mystr1.begin(), mystr1.end());
    cout << mystr1 << endl;
    cout << mystr2 << endl;

    return 0;
}
