#include <iostream>
#include "io.h"
using namespace std;

int getNum() {
    int ret;
    cout << "Enter num: ";
    cin >> ret;
    return ret;
}

void writeAns(int x, int y) {
    cout << x+y << "\n";
}
