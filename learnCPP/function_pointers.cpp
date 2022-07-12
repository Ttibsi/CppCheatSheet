#include <iostream>

int foo() {
    return 5;
}

int main() {
    int (*foo_ptr)(); // function pointer
    foo_ptr = &foo; // point it to foo()
    
    // Call function using pointer
    (*foo_ptr)();
    foo_ptr();
}
