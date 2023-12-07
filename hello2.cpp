#include <algorithm>
#include <iostream>
#include <string>

using std::cout;
using std::endl;

std::string myStringRev(std::string);
unsigned long long my_factorial(int);
int sum_from_0_to_n(int);
int sum_of_digits(int);
double a_penny_doubled_everyday(int);

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
    cout << "a_penny_doubled_everyday(18) = " << a_penny_doubled_everyday(18) << endl;
    cout << endl;

    // pointers!
    short sh {1};
    short *sh_ptr {nullptr};
    sh_ptr = &sh;
    cout << "*sh_ptr = " << ++*sh_ptr << endl;
    sh_ptr = nullptr;


    return 0;
}

double a_penny_doubled_everyday(int n) {
    if (n==1) {
        return 0.01f;
    }
    return 2*a_penny_doubled_everyday(n-1);
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
