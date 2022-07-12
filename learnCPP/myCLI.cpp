#include <iostream>

int main(int argc, char* argv[]) {
    for (int i = 0; i < argc; ++i) {
        std::cout << argv[i] << '\n';

        // If you enter a int, you need to convert it. This is trickier
        // than it seems because you don't know which args are ints or not.
    }
}
