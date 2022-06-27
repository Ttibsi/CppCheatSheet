#include <iostream>
using namespace std;

class Square;

class Rectangle {
    int width, height;

    public:
        // Constructors
        Rectangle() {}
        Rectangle (int x, int y) : width(x), height(y) {}

        // Method
        int area() {return width * height;}
        void convert(Square a);
};

class Square {
    friend class Rectangle;
    private:
        int side;
    public:
        // Constructor
        Square (int a) : side(a) {}
};

void Rectangle::convert (Square a) {
    // This is only possible because square is a friend of rectangle
    // Otherwise, we couldn't access the private square::side attributes
    width = a.side;
    height = a.side;
};

int main() {
    Rectangle rect;
    Square sqr (4);
    rect.convert(sqr);
    cout << rect.area();
}
