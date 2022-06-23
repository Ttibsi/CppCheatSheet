#include <iostream>
#include <string>
using namespace std;

int main()
{
    // for loop
    for (int n = 10; n>0; n--) {
        cout << n << "\n";
    }

    string msg = "hello";
    for (char c: msg)
    {
        cout << c << "\n";
    }
}
