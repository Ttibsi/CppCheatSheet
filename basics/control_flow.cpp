#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n = 10;
    while (n > 0) {
        cout << n << "\n";
        --n;
    }

    string colour;
    cout << "What is your favourite colour?\n";
    getline(cin, colour);

    if (colour == "red") {
        cout << "The colour of roses\n";
    } else if (colour == "blue") {
        cout << "The colour of the sky\n";
    } else {
        cout << "Good choice\n";
    }

    return 0;
}
