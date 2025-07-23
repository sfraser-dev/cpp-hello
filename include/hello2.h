#ifndef _HELLO2_H_
#define _HELLO2_H_

#include <iostream>
#include <string>

class Mystring {
  private:
    char *str; // pointer to a char[] that holds a C-style string
  public:
    Mystring();                       // No-args contstructor
    Mystring(const char *s);          // Overloaded contstructor
    Mystring(const Mystring &source); // Copy constructor
    ~Mystring();                      // Destructor
    void display() const;
    int get_length() const; // getters
    const char *get_str() const;
    Mystring& operator=(const Mystring&) noexcept; 

};

// structure not a class
struct PersonStruct {
  private:
    std::string _name;
    short _age;

  public:
    void setName(short n) { _name = n; }
    void setAge(short a) { _age = a; }
    std::string getName() { return _name; }
    short getAge() { return _age; }

    PersonStruct() : PersonStruct("None", 0) {}
    PersonStruct(std::string n) : PersonStruct(n, 0) {}
    PersonStruct(short a) : PersonStruct("None", a) {}
    PersonStruct(std::string n, short a) : _name(n), _age(a) {}

    void printInfo() {
        std::cout << "name = " << getName() << ", age = " << _age << std::endl;
    }
};

class Vehicle2 {
  private:
    std::string _brand;
    std::string _model;
    short _wheels;
    std::string _sound;
    short *_heap_arr;
    static short _amount_of_vehicles;

  public:
    // delegating constructors
    Vehicle2() : Vehicle2{"None", "None", 0, "None"} {}
    Vehicle2(std::string brand) : Vehicle2{brand, "None", 0, "None"} {}
    Vehicle2(std::string brand, std::string model)
        : Vehicle2{brand, model, 0, "None"} {}
    Vehicle2(std::string brand, std::string model, short wheels)
        : Vehicle2{brand, model, wheels, "None"} {}
    // constructor that is always called (delegated to)
    Vehicle2(std::string brand, std::string model, int wheels,
             std::string sound)
        : _brand(brand), _model(model), _wheels(wheels), _sound(sound) {
        std::cout << "Vehicle2 constructor called" << std::endl;
        _heap_arr = new short[]{1001, 1002, 1003, 1004, 1005};
        // increment static counter
        ++_amount_of_vehicles;
    }

    // destructor frees the dynamically allocated array on the heap
    ~Vehicle2() {
        std::cout << "Vehicle2 destructor called" << std::endl;
        if (_heap_arr != nullptr) {
            delete[] _heap_arr;
            _heap_arr = nullptr;
        }
        // decrement static counter
        --_amount_of_vehicles;
    }

    // copy constructor (deep)
    Vehicle2(const Vehicle2 &);

    // move constructor
    Vehicle2(Vehicle2 &&);

    void printInfo();

    // getters (const for const correctness)
    auto getBrand() const { return this->_brand; }
    auto getModel() const { return this->_model; }
    auto getWheels() const { return this->_wheels; }
    auto getSound() const { return this->_sound; }
    auto getHeapArr() const {
        for (int i = 0; i < 5; i++) {
            std::cout << _heap_arr[i] << " ";
        }
        std::cout << std::endl;
    }
    static auto getAmountOfVehicles() { return _amount_of_vehicles; }

    // setters
    auto setBrand(std::string brand) { this->_brand = brand; }
    auto setModel(std::string model) { this->_model = model; }
    auto setWheels(short wheels) { this->_wheels = wheels; }
    auto setSound(std::string sound) { this->_sound = sound; }
    auto setHeapArr(short pos, short val) { _heap_arr[pos] = val; }
};

std::string myStringRev(std::string);
unsigned long long my_factorial(int);
int sum_from_0_to_n(int);
int sum_of_digits(int);
double a_penny_doubled_everyday(int);
void ptr_add_one(short *);
void ref_add_one(short &);
short *fun_heap_alloc();
std::string reverse_string1(const std::string &);
std::string reverse_string2(const std::string &);
void change_vehicle_attributes(Vehicle2 &);

#endif