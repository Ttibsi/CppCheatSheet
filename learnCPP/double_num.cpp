#include <iostream>
using namespace std;

int doubleNum(int x) {
    return x * 2;
}

int main(){
    int input;
    cout << "Enter a number: ";
    cin >> input;
    cout << doubleNum(input) << "\n";
}
