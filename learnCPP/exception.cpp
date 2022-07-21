#include <cmath> //std::sqrt
#include <iostream>
#include <string>
#include <string_view>

//exception class
class Exception {
    std::string err;

public:
    Exception(std::string_view e) : err(e) {};
    const std::string& getError() const { return err; };
};

double mySqrt(double x) {
    if (x < 0.0) {
        throw "Negative numbers are invalid"; //throw outside a try
        //throw Exception("This failed"); 
    }

    return std::sqrt(x);
}

int main() {
    try {
        throw -1;
    } catch (int x) {
        std::cout << "Error found: " << x << '\n';
    } catch (const std::string& errMsg) {
        std::cout << errMsg << '\n';
    } catch (...) {
        // This is for any other type of exception that was missed during
        // rumtime
        std::cout << "Error found and missed" << '\n';
    }

    // for sqrt()
    try {
        double d = mySqrt(16);
        std::cout << "sqrt of 16 is " << d << '\n';
    } catch (const char* exc) {
        std::cerr << exc << '\n'; // handle the exception from sqrt()
    }
}
