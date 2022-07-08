#include <iostream>

template <typename T>
T max(T x, T y) {
    return (x > y)? x : y;
}

int main() {
    std::cout << max(3,5) << '\n';
    std::cout << max(3.2,5.2) << '\n';
    std::cout << max('a', 'e') << '\n';
}
