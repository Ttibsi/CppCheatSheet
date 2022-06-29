#include <iostream>
using namespace std;

int main()
{
    int N;
    cout << "Enter number: ";
    cin >> N;
    cout << "Prime numbers: ";

    for (int i = 1; i < N; i++) {
        if (N % i == 0) { cout << i << " "; }
    }
    cout << endl;
}
