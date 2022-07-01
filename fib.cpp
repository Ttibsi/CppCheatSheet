#include <iostream>
using namespace std;

int main() {
    bool toggle = false;
    int num1 = 1;
    int num2 = 1;
    cout << num1 << endl;
    cout << num2 << endl;

    for (int i = 0; i < 10; i++) {
        if (toggle) {
            num1 = num1 + num2;
            cout << num1 << endl;
            toggle = false;
        } else {
            num2 = num1 + num2;
            cout << num2 << endl;
            toggle = true;
        }
    }
}
