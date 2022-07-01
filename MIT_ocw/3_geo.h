#pragma once

class Point {
    int x;
    int y;

    public:
        Point();
        Point(int, int);
        
        int getX() const;
        int getY() const;

        void setX(const int new_x);
        void setY(const int new_y);
};

class PointArray {
    Point* points;
    int size;

    public:
        PointArray();
        PointArray(Point points[], int size);
        PointArray(const PointArray& pv);
        ~PointArray();
};
