#include <iostream>
using namespace std;

int main() {
    while (true) {
        int val;
        cout << "Enter a number? ";
        cin >> val;

        //cout << (val > 5 ? val/5 : -1) << endl;

        if (val == -1) {
            cout << "Goodbye";
            break;
        } else if (val > 5) {
            cout << val/5 << endl;
        } else { continue; }
    }
}

