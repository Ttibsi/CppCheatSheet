#include <iostream>
#include "3_geo.h"
using namespace std;

// Constructors
Point::Point() { x = 0; y = 0;};
Point::Point(int x, int y) : x(x), y(y) {};

int Point::getX() const { return x;}
int Point::getY() const { return y;}

void Point::setX(const int new_x) {x = new_x;}
void Point::setY(const int new_y) {y = new_y;}

//PointArray
PointArray::PointArray() {
    size = 0;
    points = new Point[0];
}

PointArray::PointArray(Point points[], int size) {
    size = size;
    points = new Point[size];
}

// Copy Constructor 
// Takes in the address of a PointArray (&) 
PointArray::PointArray(const PointArray& pv) {
    size = pv.size; // set fundamental vals to the same value
    points = new Point[size]; // Create a new Point array 
    
    // move each value to the new copied points 
    for (int i = 0; i < size; i++) {
        points[i] = pv.points[i];
    }

}

//destructor
PointArray::~PointArray() {
    delete[] points; //Need to remember to destoy our array too
}
