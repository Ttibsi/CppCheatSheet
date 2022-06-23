#include <iostream>
#include <string>
using namespace std;

int main()
{
    // do-while loop
    string str;
    do {
        cout << "Enter text: ";
        getline(cin, str);
        cout << str << "\n";
    } while (str != "off");

}
