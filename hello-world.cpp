// w3schools C++ tutorial
#include <algorithm>
#include <array>
#include <assert.h>
#include <cmath>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <memory>
#include <ostream>
#include <stdexcept>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>
#include <filesystem>

// using all of namespace std is bad practice. selectively using what I need
using std::cin;
using std::cout;
using std::endl;
using std::cerr;
using std::perror;

template <typename T>
void printSmartUniquePtrArray(std::unique_ptr<T[]> theArray, int size,
                              int digitWidth) {
    for (std::size_t i = 0; i < size; i++) {
        cout << std::setfill('0') << std::setw(digitWidth) << theArray[i]
             << " ";
    }
    cout << endl;
}

template <typename T>
void printSmartUniquePtrMatrix(
    std::unique_ptr<std::unique_ptr<T[]>[]> theMatrix, int rows, int cols,
    int digitWidth) {
    for (std::size_t r = 0; r < rows; r++) {
        for (std::size_t c = 0; c < cols; c++) {
            cout << std::setfill('0') << std::setw(digitWidth)
                 << theMatrix[r][c] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

template <typename T> void printRawPtrArray(T *arr, int size, int digitWidth) {
    for (std::size_t i = 0; i < size; i++) {
        cout << std::setfill('0') << std::setw(digitWidth) << arr[i] << " ";
    }
    cout << endl;
}

template <typename T>
void printRawPtrMatrix(T **mat, int rows, int cols, int digitWidth) {
    for (std::size_t r = 0; r < rows; r++) {
        for (std::size_t c = 0; c < cols; c++) {
            cout << std::setfill('0') << std::setw(digitWidth) << mat[r][c]
                 << " ";
        }
        cout << endl;
    }
}

template <typename T>
void printVectorMatrix(std::vector<std::vector<T>> &vec, int rows, int cols,
                       int digitWidth) {
    for (std::size_t r = 0; r < rows; r++) {
        for (std::size_t c = 0; c < cols; c++) {
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
void recCountUpTo(int n) {   // init
    if (n > 0) {             // check
        recCountUpTo(n - 1); // update and recursion ABOVE code block
        cout << n << " ";    // code block left on stack (LIFO), executed
                             // as stack diminishes (pops)
    } else {
        cout << "0 ";
    }
}

//
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

    ~Vehicle() {}

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

class Car : public Vehicle {
  public:
    // hardcode all cars to have four wheels
    Car(std::string brand, std::string model, std::string sound)
        : Vehicle(brand, model, 4, sound) {}
    ~Car() {}

    void makeSound() override;
};
void Car::makeSound() { cout << this->getSound() << endl; }

class Motorbike : public Vehicle {
  public:
    // hardcode all motorbikes to have two wheels
    Motorbike(std::string brand, std::string model, std::string sound)
        : Vehicle(brand, model, 2, sound) {}
    ~Motorbike() {}

    void makeSound() override;
};
void Motorbike::makeSound() { cout << this->getSound() << endl; }

// function overloading
void vehicleSoundPassByReference(Vehicle &vehicle) { vehicle.makeSound(); }
void vehicleSoundPassByPointer(std::shared_ptr<Vehicle> vehicle) {
    vehicle->makeSound();
}

// hashing a string to an int via a consexpr recursive function
// so can use string expressions in c++ switch
// constexp functions are evaluated at compile time, ie: calcualted constants
constexpr unsigned int myStr2int(const char *str, int h = 0) {
    return !str[h] ? 5381 : (myStr2int(str, h + 1) * 33) ^ str[h];
}

int main() {
    // string type
    std::string myStr = "Hello";
    myStr += " ";
    myStr.append("World");
    cout << myStr << endl;
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

    // get user input integer
    // By default, C++ streams don't throw upon ill-formed input: it isn't
    // exceptional that input is wrong. It is normal. The C++ approach to
    // indicate input failure is to put the stream into failure state
    int numIn; // integer input expected as writing to an int, cin knows this
    cout << "Input an int: ";
    cin >> numIn;
    // cin failure template
    while (cin.fail()) {
        // clear cin as it's in failure state
        cin.clear();
        // ignore offending characters by ignoring everything
        cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // attempt to get the user input again
        cout << "Input an int: ";
        cin >> numIn;
    }
    cout << "You input integer: " << endl;

    // math
    cout << "sqrt(25) = " << sqrt(25) << endl;
    cout << "round(2.6) = " << round(2.6) << endl;

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
    cout << "hit any key: ";
    cin >> pp;

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

    // // vector push()
    myVec.push_back(1001);
    // .at() is safer then just using "i", it'll throw exception rather than
    // return garbage
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
    // not allowed, it's not a struct named type: struct101 new101;

    // struct named type (and variable declared that uses the struct type)
    struct myStructDataType {
        int i = 202;
        std::string s = "two hundred and two";
    } myStruct202;
    cout << "Struct int: " << myStruct202.i << "; struct string "
         << myStruct202.s << endl;

    // References and Pointers are important in C++, because they give you
    // the ability to manipulate the data in the computer's memory - which
    // can reduce the code and improve the performance. These two features
    // are one of the things that make C++ stand out from other programming
    // languages, like Python and Java.

    // references (alias)
    auto a = 5;
    auto &b = a;
    cout << "a = " << a << ", b = " << b << endl;
    a++;
    cout << "a = " << a << ", b = " << b << endl;

    // raw pointers
    auto x = 303;
    auto *ptr = &x;
    cout << "x = " << x << ", ptr = " << ptr << ", *ptr = " << *ptr << endl;
    (*ptr) += 7;
    cout << "x = " << x << ", ptr = " << ptr << ", *ptr = " << *ptr << endl;

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

    // polymorphism with shared smart pointers
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
    std::ofstream fhOut("zout.txt");
    fhOut << "1. Hi there\n2. How are you?\n3. Time to go, bye." << endl;
    fhOut.close();

    // read from file via input stream and getline()
    std::ifstream fhIn("zout.txt");
    std::string myString;
    // reading the file one line at a time
    while (std::getline(fhIn, myString)) {
        cout << myString << endl;
    }
    fhIn.close();
    // delete file
    std::system("del /F zout.txt");
    // attempt to open deleted file to check its existance
    std::ifstream fileOpened("zout.txt");
    if (fileOpened.good()) {
        perror("Failed to delete zout.txt");
        return EXIT_FAILURE;
    }

    return 0;
}
