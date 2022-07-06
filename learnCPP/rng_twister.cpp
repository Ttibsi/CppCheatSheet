#include <iostream>
#include <random>
#include <chrono>

// THis is an exception of the "No non-consts in global space" rule
namespace RNG {
    // Create 32bit random num generator object
    // Seed it with the current time cast as an integer
    std::mt19937 gen{ static_cast<unsigned int>(
            std::chrono::steady_clock::now().time_since_epoch().count()
    )};

    // This one is seeded by asking the OS for a random number
    std::mt19937 mt { std::random_device{}()};
}

void rollDice() {
    std::uniform_int_distribution dice{1,6};
    std::cout << dice(RNG::mt) << "\n";
}

int main() {
    std::cout << RNG::gen() << "\n";

    rollDice();
}
