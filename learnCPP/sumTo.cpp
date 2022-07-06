#include <iostream>

int sumTo(int x) {
    int ret = 0;
    for (int i = 1; i <= x; ++i) { ret += i; }
    return ret;
}

int main() { std::cout << sumTo(5);}
