#include <iostream> // instruction to compiler include the standard Steram I/O
#include "common/square.h" // Include my custom class

using namespace std; // makes names from std visible without std::

double square(double x) {
    return x * x;
}

void print_square(double x) {
    cout << "The name of " << x << " is " << square(x) << "\n";
}

int main() {
    //std::cout << "Hello"; // the operator << "put to" writes it seconds argument onto its first
    cout << "Hello \n";
    print_square(3.14);
    
    // Types, variables and Arithmetic
    
    // int  [ ] [ ] [ ] [ ]
    int value1 = 3;
    cout << "Size of integer is: " << sizeof value1 << "\n"; // always 4 byte
    
    // boolean  [ ]
    bool value2 = false; // if set string, the stdout is "1", so boolean is 0 or 1
    cout << "Size of boolean is: " << sizeof value2 << "\n"; // always 1 byte
    
    // char  [ ]
    char value3 = 'a'; // a-Z, 1-9
    cout << "Size of char is: " << sizeof value3 << "\n"; // always 1 byte
    
    // double  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
    double value4 = 3.14; // Double precision floating-point number: 3.14 and 299793.0
    cout << "Size of double is: " << sizeof value4 << "\n"; // always 8 byte

    cout << value1;
    cout << "\n";
    cout << value2;
    cout << "\n";
    cout << value3;
    cout << "\n";
    cout << value4;

    // Reading class
    Square square(3.14);
    cout << "The area of the square is: " << square.getArea() << "\n";

    return 0;
}
