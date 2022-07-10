#include <iostream>

/*
* Pointers are variables that hold a reference address. They can be 
dereferenced using an asterisk (deref operator) to access the value. 
*/

void passByRef(int &x) {
    std::cout << x << "\n";
}

void passByAddress(int *x) { // This param holds the address of x
    // Check if pointer is null
    if (!x) { return; }
    //assert(*x)

    *x += 1;
}

int main() {
    int x = 5;
    int& ref = x; //Reference to x - not a pointer
    int* ptr = &x; // Pointer to the address of x
    // int* ptr = ref; // this won't work, different uses of &

    std::cout << x << '\n';
    std::cout << ref << '\n';
    std::cout << ptr << '\n';
    std::cout << *ptr << '\n';

    // null pointer
    int* nlptr = nullptr;
    std::cout << nlptr << '\n';

    // Pointers and consts
    const int y = 3;
    const int* ptr2 = &y; //pointer to a const int, not a const pointer
    
    const int z = 4;
    ptr2 = &z; //This is legal despite the const on line 38 
    ptr2 = &x; // Treating x as a const even though it's not defined as one
    
    int* const ptr3 = &x; // This is a const pointer and can't be changed
    *ptr3 = 6; //x itself isn't a const so this is ok
    std::cout << x << '\n';

    passByRef(x);
    passByAddress(&x); //Pass the address of x
    passByAddress(ptr); // Pass the ptr that points to x

}

