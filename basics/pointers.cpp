#include <iostream>
using namespace std;

int main()
{
    int foo = 12;
    int* bar = &foo; // bar is a pointer pointing to an integer named foo
    cout << &foo << endl; // This should give mem address
    cout << *bar; // Should print 12

    // arrays and pointers
    int myArr[20];
    int* mypointer = myArr;
}
