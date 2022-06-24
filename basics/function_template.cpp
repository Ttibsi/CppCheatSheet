#include <iostream>
using namespace std;

// My function template
template <typename SomeType>
SomeType sum (SomeType a, SomeType b)
{
    return a+b;
}

int main()
{
    cout << sum(1,2) << "\n";
    cout << sum(1.1,2.2) << "\n";
    cout << sum<double>(1,2.2) << "\n";
}
