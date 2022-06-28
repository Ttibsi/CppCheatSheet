#include <iostream>
using namespace std;

// Default on MacOS is apparently C++97
// Change this with the -std=c++XX flag
int main() { cout << __cplusplus; }
