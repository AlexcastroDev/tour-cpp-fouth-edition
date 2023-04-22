#include <iostream> // instruction to compiler include the standard Steram I/O

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
    int value1 = 1;
    // int  [ ]
    bool value2 = false; // if set string, the stdout is "1", so boolean is 0 or 1
    // int  [ ]
    char value3 = 3; // a-Z, 1-9
    // int  [ ] [ ] [ ] [ ] [ ] [ ] [ ] [ ]
    double value4 = 'a'; // Double precision floating-point number: 3.14 and 299793.0
    
    cout << value1;
    cout << "\n";
    cout << value2;
    cout << "\n";
    cout << value3;
    cout << "\n";
    cout << value4;

    return 0;
}
