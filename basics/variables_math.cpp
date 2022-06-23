#include <iostream>
using namespace std;

int main() 
{
    //declare variables
    int firstNum, secondNum;
    int result;

    // Set values
    firstNum = 10;
    secondNum = 5;
    //firstNum = firstNum + 1;
    firstNum += 1;

    result = firstNum - secondNum;
    cout << result;

    return 0;
}

