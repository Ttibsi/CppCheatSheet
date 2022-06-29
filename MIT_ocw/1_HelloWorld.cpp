#include <iostream>
using namespace std;

int main() {
    const char* txt = "Hello world!\n";
    int n;

    cout << "Enter length: " << endl;
    cin >> n;

    // For loop
    for (int i = 0; i <= n; i++) {
        cout << txt;
    }

    // do-while
    int j = 0;
    do {
        cout << txt;
        j++;
    } while (j <= n);

    // while 
    int k = 0;
    while (k <= n) {
        cout << txt;
        k++;
    }
}
