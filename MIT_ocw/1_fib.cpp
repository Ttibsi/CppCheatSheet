#include <iostream>
using namespace std;

int main() {
    short num;

    // If this is an int, you can't go over entering 16 
    long accumulator = 1;

    cout << "Enter a number ";
    cin >> num;

    if (num < 0) {
        cout << "Factorial of your number: Undefined";
    } else if (num < 11) {
        switch(num) {
            case 1:
                cout << "Factorial of your number: 1";
                break;
            case 2:
                cout << "Factorial of your number: 2";
                break;
            case 3:
                cout << "Factorial of your number: 6";
                break;
            case 4:
                cout << "Factorial of your number: 24";
                break;
            case 5:
                cout << "Factorial of your number: 120";
                break;
            case 6:
                cout << "Factorial of your number: 720";
                break;
            case 7:
                cout << "Factorial of your number: 5040";
                break;
            case 8:
                cout << "Factorial of your number: 40320";
                break;
            case 9:
                cout << "Factorial of your number: 362880";
                break;
            case 10:
                cout << "Factorial of your number: 3628800";
                break;
        }
    } else {
        cout << "Factorial of your number: ";

        for (; num > 0; accumulator *= num--);
        cout << accumulator << "\n";
    }
} 
