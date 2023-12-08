#ifndef _HELLO2_H_
#define _HELLO2_H_

#include <cstddef>
#include <iostream>

class Vehicle2 {
  private:
    std::string _brand;
    std::string _model;
    short _wheels;
    std::string _sound;
    short *_heap_arr;

  public:
    // delegated constructors from constructor initialization list
    Vehicle2() : Vehicle2{"None", "None", 0, "None"} {}
    Vehicle2(std::string brand) : Vehicle2{brand, "None", 0, "None"} {}
    Vehicle2(std::string brand, std::string model)
        : Vehicle2{brand, model, 0, "None"} {}
    Vehicle2(std::string brand, std::string model, short wheels)
        : Vehicle2{brand, model, wheels, "None"} {}
    Vehicle2(std::string brand, std::string model, int wheels,
             std::string sound)
        : _brand(brand), _model(model), _wheels(wheels), _sound(sound) {
          std::cout << "Vehicle2 constructor called" << std::endl;
        _heap_arr = new short[]{1001, 1002, 1003, 1004, 1005};
    }

    // destructor frees the dynamically allocated array on the heap
    ~Vehicle2() {
      std::cout << "Vehicle2 destructor called" << std::endl;
      if (_heap_arr != nullptr) {
        delete[] _heap_arr;
        _heap_arr = nullptr;
      }
    }

    // copy constructor (deep)
    Vehicle2(const Vehicle2 &);

    // move constructor
    Vehicle2(Vehicle2&&);

    void printInfo();

    // getters and setter
    auto getBrand() { return this->_brand; }
    auto getModel() { return this->_model; }
    auto getWheels() { return this->_wheels; }
    auto getSound() { return this->_sound; }
    auto getHeapArr() {
        for (int i = 0; i < 5; i++) {
            std::cout << _heap_arr[i] <<" ";
        }
        std::cout << std::endl;
    }
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
void change_vehicle_attributes(Vehicle2&);

#endif