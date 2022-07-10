#include <iostream>
#include <string_view>

/*
* Enums are custom types with a comma separated list of all allowed values the
* type can be - in this case, the colours are red, green, and blue.
* By convention, they're started with a capital letter, and don't even have to
* have a name at all, although that's an awful move to make for readability.
*/

enum Colour {
    // orange = 1 // This sets the starting index to 1 instead of 0
    red, 
    green, 
    blue,
};

// Printing an enum is complicated because they're basically integers
std::string_view printColour(Colour c) {
    switch(c) {
        case red:
            return "Red";
        case green:
            return "Green";
        case blue:
            return "Blue";
        default:
            return "?";
    }
}

int main() {
    // Set a variable to the type defined with the enum
    Colour foo = red;
    std::cout << printColour(foo); 

    // Scoped enum
    // These allow for proper comparisons instead of equating to ints
    enum class Days {
        Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
    };

    Days bar = Days::Tuesday;
    if (bar == Days::Tuesday) {
        std::cout << "Today" << '\n';
    }
    std::cout << static_cast<int>(bar) << '\n'; // Will print the num value
}
