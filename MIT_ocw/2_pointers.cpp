#include <iostream>
using namespace std;

int get_char_length(const char *word) {
    int length = 0;
    while (*(word + length) != '\0') {
        length++;
    }
    return length;
}

void refSwap(int &x, int &y) {
    int tmp = x;
    x = y;
    y = tmp;
}

void swap(int *x, int *y) {
    int tmp = *x; 
    *x = *y;
    *y = tmp;
}

void ptrSwap(int **x, int **y) {
    int *tmp = *x;
    *x = *y;
    *y = tmp;
    
}

int main() {
    char word[] = "hello world";
    cout << get_char_length(word) << endl;

    int a = 3;
    int b = 4;
    refSwap(a, b);
    cout << a << " " << b << endl;
    swap(a, b);
    cout << a << " " << b << endl;

    int *ptr1 = &a;
    int *ptr2 = &b;
    ptrSwap(&ptr1, &ptr2);
    cout << a << " " << b << endl;

    const char *oddOrEven = "Never odd or even";
    const char *nthCharPtr = &oddOrEven[5] - 2;
    cout << *nthCharPtr << endl;

    const char *pointerptr = nthCharPtr;
    cout << pointerptr << endl;
    cout << *pointerptr << endl;
    nthCharPtr++;
    cout << nthCharPtr - oddOrEven << endl;
}
