#include <iostream>
using namespace std;

int main()
{
    int x;
    int y = 2 * (x = 3); // Funky stuff with assignment operator
    cout << y << endl; // 6

    // Arithmetic operators
    int foo = 2;
    int bar = 5;
    int baz = 10;

    cout << foo + bar << endl; // 7
    cout << baz - bar << endl; // 5 
    cout << foo * bar << endl; // 10
    cout << baz / foo << endl; // 5 
    cout << baz % foo << endl; // 0
    
    // Compound operators
    bar += foo;
    cout << bar << endl; // 7
    
    // Increment and decrement
    bar++;
    cout << bar << endl; // 8
    bar--;
    cout << bar << endl; // 7

    // Relational and comparison operators
    cout << (baz == foo) << endl; // false 
    cout << (baz != foo) << endl; // true 
    cout << (baz < foo) << endl; // false 
    cout << (baz <= foo) << endl; // false 
    cout << (baz > foo) << endl; // true 
    cout << (baz >= foo) << endl; // true 

    return 0;
}
