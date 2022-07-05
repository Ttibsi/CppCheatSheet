#include <iostream>
using namespace std;

int main() {
    char foo;
    cout << "Enter a character: ";
    cin >> foo;
    cout << foo << " has value " << static_cast<int>(foo) << "\n";
}
