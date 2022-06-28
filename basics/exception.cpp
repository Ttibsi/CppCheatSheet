#include <iostream>
#include <exception>
using namespace std;

// Custom exception
class myException : public exception
{
    virtual const char* what() const throw()
    {
        return "My Error";
    }
} myex;

int main() 
{
    try {
        int a = 1; 
        //throw a;
        throw myex;
    } catch (int a) {
        cout << "Divide by zero\n";
        cout << a;
    } catch (exception& e) {
        // This will catch any exception of any type derived from the exception class
        // IE, this will catch `myex`

        // This should print "My Error" - see line 10
        cout << e.what() << "\n";
    } catch (...) {
        cout << "Default Error\n";
    }
}
