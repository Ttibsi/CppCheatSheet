#include <iostream>
using namespace std; 


double get_height() {
    int height;
    cout <<  "Enter height in meters: "; 
    cin >> height;
    return static_cast<double>(height);
}

double fallingBallHeight(int s, double h, double sh) {
    const double GRAVITY = 9.8;
    double ret = (GRAVITY * (s * s)) / 2.0;
    return sh - ret;
}

double printFalling(int sec, double height, double start_height) {
    cout << "After " << sec << " seconds, the ball has fallen " << height << "m\n";
    return fallingBallHeight(sec, height, start_height);
}

int main(){
    double start_height = get_height();

    double height = printFalling(0, start_height, start_height);
    height = printFalling(1, height, start_height);
    height = printFalling(2, height, start_height);
    height = printFalling(3, height, start_height);
    height = printFalling(4, height, start_height);
}
