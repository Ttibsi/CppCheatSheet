#define foo(a,b) a ## b
#include <iostream>
using namespace std;

// This combines `c` and `out` to create `cout`
int main() {foo(c,out) << "hi";}
