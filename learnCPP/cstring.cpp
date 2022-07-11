#include <cstring>
#include <iostream>

int main() {
    char src[20] = "Foo bar baz";
    char dest[20];

    // Copy to a new string
    // There are a few different ways to do this that avoid different issues
    std::strcpy(dest, src);


}
