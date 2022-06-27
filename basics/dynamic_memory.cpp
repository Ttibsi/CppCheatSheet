#include <iostream>
#include <new>
using namespace std;

int main()
{
    int i;
    int* p;
    cout << "Enter length";
    cin >> i;

    p = new (nothrow) int[i];
    if (p == nullptr) {
        cout << "Error";
    } else {
        for (int n=0; n<i; n++)
        {
            cout << "Enter number ";
            cin >> p[n];
        }

        cout << "List = ";
        for (int n=0; n<i; n++) cout << p[n] << ", ";
        delete[] p;
    }
}
