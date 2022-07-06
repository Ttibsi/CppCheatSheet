#include <iostream>
using namespace std;

int main() {
    int x;
    cout << "Enter a number ";
    cin >> x;

    if (x % 2 == 0) {
        cout << "It's even";
    } else { cout << "It's odd"; }
}
