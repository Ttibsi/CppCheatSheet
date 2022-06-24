#include <iostream>
using namespace std;

int add(int a, int b){ return (a+b);}
int subtract(int a, int b){ return (a-b);}

int op(int a, int b, int(*func)(int, int))
{
    int g = (*func)(a,b);
    return g;
}

int main()
{
    int m, n;
    int (*plus)(int, int) = add; // This is a pointer to the "add" func

    m = op(5, 7, plus);
    cout << m;

}
