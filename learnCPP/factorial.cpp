#include <iostream>

int factorial(int n) {
    if (n > 1) {
        return n * factorial(n - 1);
    } else if (n == 1) { 
        return 1; 
    } else { throw std::invalid_argument("Negative number"); }
}

int main() {
    std::cout << factorial(7) << '\n';
}
