#include <iostream>

int main() {
    // Dynamic array that can change size during rumtime
    int* array = new int[0];

    array[0] = 5;
    array[3] = 7;

    // Destroy array for reallocation
    delete[] array;
}
