#include <iostream>
#include <string>


struct Company {
    struct Employee {
        int id {};
        int age {};
        std::string name;
    };

    int numOfEmployees {};
    Employee CEO;
};

// Templated struct
template <typename T, typename U>
struct Pair 
{
    T first {};
    U second {};
};

// Template deduction
template <typename T, typename U>
Pair(T, U) -> Pair<T, U>; 

// Function calling templated struct
template <typename T, typename U>
constexpr T max(Pair<T, U> p) {
    return (p.first > p.second ? p.first : p.second);
}

int main() {
    // Employee bob {1, 32, "Bobby Singer"};

    // Nested initialisation of Employee type there.
    Company myComp {7, {1, 32, "Bobby Singer"} }; 

    // To access attrs using a pointer, you need to dereference
    Company* ptr = &myComp;
    std::cout << ptr->numOfEmployees << '\n';

    // YOu can also use a combination of -> and . at the same time
    // Brackets aren't needed here, just for readability. 
    std::cout << (ptr->CEO).age << '\n';

    Pair<int, int> foo {2,4};
    Pair<double, double> bar {1.1, 4.2};
    // This will implicitly know to call/return a double
    std::cout << max(bar) << '\n';
    
    // Pair baz(1,2); // This will error without a template deduction 
}
