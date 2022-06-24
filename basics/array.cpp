#include <iostream>
#include <string>
using namespace std;

int main()
{
    int fib [5] = {1,1,2,3,5};
    int foo[] = {10,20,30}; // initialised at len 3
    fib[1] = 7;

    //multidimensional arrays
    int tictactoe[5][3];

    // g++ -std=c++11
    for (int elem: foo) cout << elem << "\n";

}
