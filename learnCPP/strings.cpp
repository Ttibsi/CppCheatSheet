// c++17 or newer
#include <iostream>
#include <string>
#include <sstream>
#include <string_view>

// string_view is basically a read-only copy of the string literal entered in 
// the assignment line in main() - and while it's not faster in compile time,
// it's more efficient space-wise.
void printString(std::string_view s) {
    std::cout << s;
}

template <typename T>
inline std::string toString(T x) {
    std::ostringstream oStream;
    oStream << x;
    return oStream.str();
}

int main() {
    std::string_view s = "hello hello";
    printString(s);


    // String view needs static casting to string
    std::string_view s2_sv = "foo";
    std::string s2 = static_cast<std::string>(s2_sv);

    // However strings can automatically become string views
    std::string_view s2_2 = s2;

    using namespace std::literals;
    std::cout << "I am a string_view literal"sv;

    std::string str3 = toString(4);
    std::cout << str3;
}
