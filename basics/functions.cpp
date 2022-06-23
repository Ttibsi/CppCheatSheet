#include <iostream>
#include <string>
using namespace std;

int add(int a, int b)
{
    return a + b;
}

//This passes the num as a pointer to the argument
void doubleNum(int& num)
{
    num *= 2;
}

int main()
{
    cout << add(2,3) << "\n";
    cout << add(10,10) << "\n";
    cout << add(1,0) << "\n";

    int a = 4;
    doubleNum(a);
    cout << a << "\n";
}

