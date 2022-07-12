#include <array>
#include <cstddef> // std::size_t
#include <iostream>
#include <vector>

// Always pass as ref or const ref (&)
// This template lets you pass any sized array here 
template <typename T, std::size_t size>
int arrayLength(const std::array<T, size>& a) {
    return a.size();
}

int main() {
    std::array<int, 3> myArr = {0,1,2}; // Int array of length 3
    std::array myArr2 = {0,1,2}; // You can omit length and type together
    
    std::cout << myArr2[1]; //access like normal
    myArr2[1] = 5; // set values like normal

    std::cout << "length = " << myArr.size() << '\n';

    // Pass to a function
    int a = arrayLength(myArr2);

    // Easily get the start and end of the array.
    // You can also use <iterator>'s std::begin() and std::end()
    auto begin = myArr.begin();
    auto end = myArr.end();

    // Create a vector
    // This will automatically be destroyed when you go out of scope
    std::vector<int> myVec;
    std::vector<int> myVec2 = {1,2,3};
    myVec.resize(10); // resize vector super easy
    std::cout << myVec.capacity() << '\n';
}
