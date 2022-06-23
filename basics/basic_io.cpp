#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
    string name;
    string ageInput;
    int age;

    cout << "What is your name?\n";
    cin >> name;
    cout << "How old are you?\n";
    cin >> ageInput;
    stringstream(ageInput) >> age; //conert to int

    cout << "Hello " << name << "\n";
    cout << "You will be " << age + 1 << " years old next year\n"; // inline maths

    return 0;
}
