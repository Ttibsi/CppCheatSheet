#include <iostream>
using namespace std;

// Cartesian Vectors
class CVector {
    public:
        int x, y;
        CVector() {}; // empty constructor
        CVector (int a, int b) : x(a), y(b) {}; // inline constructor
        CVector operator + (const CVector&); // Overload operator
};

// Overload the + operator
// param is a pointer to the given object
// You can also use this with an lhs and rhs as two separate params
CVector CVector::operator+ (const CVector& param)
{
    CVector temp;
    temp.x = x + param.x;
    temp.y = y + param.y;
    return temp;
}

int main()
{
    CVector foo (3,1);
    CVector bar (1,2);
    CVector result;

    result = foo + bar;
    cout << result.x << "," << result.y << "\n";
}
