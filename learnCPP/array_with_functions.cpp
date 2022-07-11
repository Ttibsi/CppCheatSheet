#include <iostream>

void myfunc(int* arr_ptr) {
    // Treat it as a pointer here - this prints the address of the first item
    std::cout << arr_ptr;
}

int main() {
    int arr[5] = {0,1,2,3,4};
    myfunc(arr);

    // for each item in array, do...
    // Using the & means that each item doesn't have to be copied, which
    // is expensive
    for (const auto& i : arr) {
        std::cout << i << '\n';
    }
}
