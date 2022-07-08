#include <iostream>

/*
* Pointers are variables that hold a reference address. They can be 
dereferenced using an asterisk (deref operator) to access the value. 
*/

int main() {
    int x = 5;
    int& ref = x; //Reference to x - not a pointer
    int* ptr = &x; // Pointer to the address of x
    // int* ptr = ref; // this won't work, different uses of &

    std::cout << x << '\n';
    std::cout << ref << '\n';
    std::cout << ptr << '\n';
    std::cout << *ptr << '\n';
}

