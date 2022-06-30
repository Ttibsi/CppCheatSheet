#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>
using namespace std;

bool get_dist (double x, double y) {
    int radius = 1;
    double distance_squared = (x * x) + (y * y);
    return (sqrt(distance_squared) < radius) ? true : false;
}

double calculate_pi(int darts_thrown) {
    int in_circle = 0;
    for (int i = 0; i < darts_thrown; i++) {
        double x = (rand() / double(RAND_MAX)); 
        double y = (rand() / double(RAND_MAX)); 

        if (get_dist(x, y)) {
            in_circle++;
        }
    }
    return in_circle / static_cast<double>(darts_thrown) * 4;
}

int main()
{
    // Set rng seed to current time
    srand(time(0));
    int throws = 10000000;
    cout << calculate_pi(throws) << endl;
}
