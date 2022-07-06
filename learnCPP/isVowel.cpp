#include <ios>
#include <iostream>

// src: https://www.learncpp.com/cpp-tutorial/switch-fallthrough-and-scoping/
bool isVowel(char c)
{
    switch (c)
    {
        case 'a': // if c is 'a'
        case 'e': // or if c is 'e'
        case 'i': // or if c is 'i'
        case 'o': // or if c is 'o'
        case 'u': // or if c is 'u'
        case 'A': // or if c is 'A'
        case 'E': // or if c is 'E'
        case 'I': // or if c is 'I'
        case 'O': // or if c is 'O'
        case 'U': // or if c is 'U'
            return true;
        default:
            return false;
    }
}

int main() {
    std::cout << std::boolalpha;
    std::cout << isVowel('e') << "\n";
    std::cout << isVowel('f') << "\n";
    std::cout << isVowel('A') << "\n";
    std::cout << isVowel('U') << "\n";
}
