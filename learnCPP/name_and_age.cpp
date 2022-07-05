#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;
    int age;

    cout << "What is your name? ";
    getline(cin >> ws, name);

    cout << "How old are you ";
    cin >> age;

    cout << static_cast<int>(name.length()) + age;
}
