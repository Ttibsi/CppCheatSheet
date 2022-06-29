#include <algorithm>
#include <iostream>
using namespace std;

int highest_val(int list[]);
int get_mean(int list[]);

int length;

int main()
{
    cout << "Enter length ";
    cin >> length;

    int list [length];

    for (int i = 0; i < length; i++) {
        int entry;
        cout << "Enter number ";
        cin >> entry;
        list[i] = entry;
    }

    // print maximum value
    cout << "highest value: " << highest_val(list) << endl;

    // print mean
    cout << "Mean: " << get_mean(list) << endl;
}

int highest_val(int list[length]) {
    int high = 0;

    for (int i = 0; i < length; i++) {
        if (list[i] > high) { high = list[i];}
    }

    return high;
}

int get_mean(int list[length]) {
    int ret;

    for (int i = 0; i < length; i++) {
        ret = ret + list[i];
    }

    return ret/length;
}
