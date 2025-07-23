#include "hello2.h"
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <ostream>
#include <string>
#include <vector>

#define _CRT_SECURE_NO_WARNINGS

using std::cout;
using std::endl;

// static variable
short Vehicle2::_amount_of_vehicles = 0;

int main() {
    // range based for loop
    for (std::size_t ch : "This is a test") {
        if (ch == ' ') {
            cout << "\t";
        } else {
            cout << (char)toupper(ch);
        }
    }
    cout << endl;

    // begin, end, reverse, substr, substr, find, rfind, length (size), erase, +
    std::string mystr1 = "This is a test";
    cout << mystr1.substr(0, 4) << endl;
    std::string mystr2 = mystr1;
    reverse(mystr1.begin(), mystr1.end()); // in-place reversal
    cout << mystr1 << endl;
    cout << mystr2 << endl;
    cout << myStringRev(mystr2) << endl;
    cout << "mystr2.find('This') " << mystr2.find("This") << endl;
    cout << "mystr2.find('is') " << mystr2.find("is") << endl; // Th*is*
    cout << "mystr2.find('e') " << mystr2.find("e") << endl;
    cout << "mystr2.find('is', 4) " << mystr2.find("is", 4) << endl; // offset
    cout << "mystr2.rfind('is') " << mystr2.rfind("is")
         << endl; // search from RHS
    if (mystr2.find("XXX") == std::string::npos) {
        cout << "cannout find 'XXX'" << endl;
    }
    cout << "mystr2.length() = " << mystr2.length() << endl;
    cout << "mystr2.erase(0,4) = " << mystr2.erase(0, 4) << endl; // erase
    cout << "mystr2.length() = " << mystr2.length() << endl;
    cout << "mystr1 + mystr2 = " << mystr1 + mystr2 << endl; // concat
    cout << endl;

    // letter pyramid
    std::string input("abc");
    // Display the Letter Pyramid
    for (std::size_t i = 0; i < input.length(); ++i) {
        // Print leading spaces
        for (std::size_t j = 0; j < input.length() - i - 1; ++j) {
            cout << " ";
        }
        // Print characters in ascending order
        for (std::size_t j = 0; j <= i; ++j) {
            cout << input[j];
        }
        // Print characters in descending order
        // issue in the descending order loop where unsigned integer
        // (std::size_t) used for the for the loop variable j, and it
        // becomes problematic when j reaches 0.
        for (int j = i - 1; j >= 0; --j) {
            cout << input[j];
        }
        // Move to the next line
        cout << std::endl;
    }
    cout << endl;

    // recursion: factorial
    cout << "my_factorial(12) = " << my_factorial(12) << endl;
    cout << "sum_of_digits(101) = " << sum_of_digits(101) << endl;
    cout << "sum_from_0_to_n(6) = " << sum_from_0_to_n(6) << endl;
    cout << "a_penny_doubled_everyday(18) = " << a_penny_doubled_everyday(18)
         << endl;
    cout << endl;

    // pointers!
    short sh{1};
    short *sh_ptr{&sh};
    cout << "*sh_ptr = " << *sh_ptr << endl;
    ptr_add_one(sh_ptr);
    cout << "*sh_ptr = " << *sh_ptr << endl;
    ref_add_one(*sh_ptr);
    cout << "*sh_ptr = " << *sh_ptr << endl;
    sh_ptr = nullptr;
    // pointers on the heap
    int *heap1_ptr{new int};
    *heap1_ptr = 101;
    cout << "heap1_ptr = " << heap1_ptr << endl;
    cout << "*heap1_ptr = " << *heap1_ptr << endl;
    delete heap1_ptr;
    heap1_ptr = nullptr;
    // pointer arithmetic
    short *sharr = new short[]{1, 2, 3, 4, 5};
    // cannot use range based for loop with dynamically allocated arrays (use
    // vectors!)
    for (short i = 0; i < 5; i++) {
        cout << sharr[i] << " ";
    }
    cout << endl;
    // pointer subscript notation
    sharr[0] = 11;
    sharr[1] = 22;
    sharr[2] = 33;
    sharr[3] = 44;
    sharr[4] = 55;
    for (short i = 0; i < 5; i++) {
        cout << sharr[i] << " ";
    }
    cout << endl;
    // pointer offset notation, compiler knows array type will increment
    // appropriately to next element
    // nb: pointer subscript and pointer offset are equivalent
    *(sharr + 0) = 101;
    *(sharr + 1) = 102;
    *(sharr + 2) = 103;
    *(sharr + 3) = 104;
    *(sharr + 4) = 105;
    for (short i = 0; i < 5; i++) {
        cout << sharr[i] << " ";
    }
    cout << endl;
    delete[] sharr;
    sharr = nullptr;

    // create new array on the heap from a function
    short *funheap = fun_heap_alloc();
    for (int i = 0; i < 5; i++) {
        cout << funheap[i] << " ";
    }
    cout << endl;
    delete[] funheap;
    funheap = nullptr;

    // reverse string in a function
    std::string instring = "String Bling Wing Fling";
    std::string outstring = reverse_string1(instring);
    cout << "instring = " << instring << endl;
    cout << "outstring = " << outstring << endl;
    outstring = reverse_string2(outstring);
    cout << "outstring = " << outstring << endl;
    cout << endl;

    // reference in ranged for loop
    std::string strarr[] = {"Homer", "Lisa", "Marge"};
    // const ref when reading
    for (auto const &el : strarr) {
        cout << el << " ";
    }
    cout << endl;
    // just ref when changing permanently
    for (auto &el : strarr) {
        if (el == "Homer") {
            el = "D'oh";
        }
        cout << el << " ";
    }
    cout << endl << endl;

    // delegated constructors ("normal" constructor)
    cout << "----- constructor" << endl;
    Vehicle2 veh1;
    veh1.printInfo();
    cout << "----- constructor done" << endl;

    // deep copy constructor used to create veh2 from veh1
    cout << "----- copy constructor" << endl;
    Vehicle2 veh2(veh1);
    change_vehicle_attributes(veh2);
    cout << "back in main(): " << endl;
    cout << "veh1 info: " << endl;
    veh1.printInfo();
    cout << "veh2 info: " << endl;
    veh2.printInfo();
    cout << "----- copy constructor done" << endl;

    // move constructor execution (beware of elison copying optimising away the
    // call to a move constructor sometimes)
    cout << "----- move constructor" << endl;
    std::vector<Vehicle2> vehvec;
    // instaniating object in arg list (r-val), "normal" constructor called to
    // create unnamed temp obj, then move constructor "steals" the temp objs
    // heap data (so no need to copy it, much more efficient)
    vehvec.push_back(Vehicle2("Bentley", "Baby", 4, "money money money"));
    cout << "vehvec[0] info: " << endl;
    (vehvec.at(0)).printInfo();
    cout << "----- move constructor done" << endl;

    // const correctness
    cout << "const correctness" << endl;
    const Vehicle2 veh3_con("Jaguar");
    // veh3_con.setBrand("Not allowed as setBrand() is not a const function");
    cout << "veh3_con.getBrand() = " << veh3_con.getBrand() << endl;
    cout << "const correctness done" << endl;

    // static variable objects created counter
    cout << "Vehicle2::getAmountOfVehicles() = "
         << Vehicle2::getAmountOfVehicles()
         << " 'Vehicle2 objects' in existance" << endl;

    // structs (essentially the same as classes in c++)
    cout << "structs" << endl;
    PersonStruct jsmith("John Smith", 34);
    jsmith.printInfo();
    cout << endl;

    // MyString operator overloading
    Mystring empty;          // no args constructor
    Mystring larry("Larry"); // overloaded
    Mystring stooge{larry};  // copy constructor
    empty.display();
    larry.display();
    stooge.display();
    cout << endl;

    cout << endl << endl << endl;
    return 0;
}

// No-args constructor
Mystring::Mystring() : str{nullptr} {
    // initialise string to an explicit null char \0 rather than nullpointer
    str = new char[1];
    *str = '\0';
}

// Overloaded constructor
Mystring::Mystring(const char *s) : str{nullptr} {
    if (s == nullptr) {
        str = new char[1];
        *str = '\0';
    } else {
        str = new char[std::strlen(s) + 1];
        std::strcpy(str, s);
    }
}

// Copy constructor
Mystring::Mystring(const Mystring &source) : str{nullptr} {
    str = new char[std::strlen(source.str) + 1];
    std::strcpy(str, source.str);
}

// Destructor
Mystring::~Mystring() { delete[] str; }

// Display method
void Mystring::display() const {
    std::cout << str << " : " << get_length() << std::endl;
}

// length getter
int Mystring::get_length() const { return std::strlen(str); }

// string getter
const char *Mystring::get_str() const { return str; }

// move constructor (the Vehicle2 "normal" constructor will be called first)
Vehicle2::Vehicle2(Vehicle2 &&sourceTempCopy)
    : _brand(sourceTempCopy.getBrand()), _model(sourceTempCopy.getModel()),
      _wheels(sourceTempCopy.getWheels()), _sound(sourceTempCopy.getSound()),
      // stealing the pointer pointing to the heap data
      _heap_arr(sourceTempCopy._heap_arr) {
    cout << "Vehicle2 move constructor called" << endl;
    // nulling the source's pointer
    sourceTempCopy._heap_arr = nullptr;
}

// copy constructor
Vehicle2::Vehicle2(const Vehicle2 &source)
    : _brand(source._brand), _model(source._model), _wheels(source._wheels),
      _sound(source._sound) {
    cout << "Vehicle2 copy constructor called" << endl;
    // create new array on heap (deep copy)
    _heap_arr = new short[]{2001, 2002, 2003, 2004, 2005};
}

// pass Vehicle2 by reference
void change_vehicle_attributes(Vehicle2 &v) {
    cout << "Entering change_vehicle_attributes()..." << endl;
    cout << "changing brand..." << endl;
    v.setBrand("HHOONNDDAA");
    cout << "changing heap arr value..." << endl;
    v.setHeapArr(0, 2222);
    v.printInfo();
    cout << "Exiting change_vehicle_attributes()..." << endl;
}

void Vehicle2::printInfo() {
    cout << "Brand: " << this->getBrand() << ", Model: " << this->getModel()
         << ", Wheels: " << this->getWheels() << ", Sound: " << this->getSound()
         << ", Heap Arr: ";
    this->getHeapArr();
}

std::string reverse_string1(const std::string &str) {
    std::string reversed;
    reversed = str;
    short len = str.length();
    int j = len - 1;
    for (std::size_t i = 0; i < len; i++) {
        reversed.at(j--) = str.at(i);
    }
    return reversed;
}

std::string reverse_string2(const std::string &str) {
    std::string reversed;
    reversed = str;
    reverse(reversed.begin(), reversed.end());
    return reversed;
}

short *fun_heap_alloc() {
    short *ptr{new short[]{100, 101, 102, 103, 104}};
    return ptr;
}

void ptr_add_one(short *n) { (*n)++; }
void ref_add_one(short &n) { n++; }

double a_penny_doubled_everyday(int n) {
    if (n == 1) {
        return 0.01f;
    }
    return 2 * a_penny_doubled_everyday(n - 1);
}

int sum_of_digits(int n) { // 123=6, 1234=10, 101=2
    if (n < 10) {
        cout << "final case reached! ";
        return n;
    } else {
        cout << n << " ";
        int tot = (n % 10) + sum_of_digits(n / 10);
        return tot;
    }
}

int sum_from_0_to_n(int n) {
    if (n == 1) {
        cout << n << " ";
        return 1;
    } else {
        cout << n << " ";
        return n + (sum_from_0_to_n(n - 1));
    }
}

unsigned long long my_factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * my_factorial(n - 1);
    }
}

std::string myStringRev(std::string sin) {
    short len = sin.length();
    short last_index = len - 1;
    std::string sout(len, 'x'); // will initialise string with Xs
    int j = 0;
    for (short i = last_index; i >= 0; --i) {
        sout[j++] = sin[i];
    }
    return sout;
}
