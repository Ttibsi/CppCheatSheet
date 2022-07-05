#include <ios>
#include <iostream>
using namespace std;

int main() {
    bool a = true;
    bool b = false;
    bool c;

    cout << a << "\n";
    cout << b << "\n";
    //cin >> c; // this will only accept 0 or 1
    
    cout << boolalpha; // Print bools as text, not as nums

    cout << a << "\n";
    cout << b << "\n";
    //cin >> c; // boolalpha lets this accept true or false

    cout << noboolalpha; // disable boolalpha 
}
