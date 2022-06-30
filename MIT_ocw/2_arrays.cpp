#include <iostream>
using namespace std;

int LENGTH = 5;
int WIDTH = 7;

void transpose(const int input[][LENGTH], int output[][WIDTH]) {
    int transpose[] = {};
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < WIDTH; j++) {
            output[i][j] = input[j][i];
        }
    }
}

void reverse(int *arr, const int length) {
    for (int i = 0; i < length/2; i++) {
        int tmp = arr[i];
        int idx = length - i - 1;
        arr[i] = arr[idx];
        arr[idx] = tmp;
    }
}

void printArray(const int *arr, const int length) {

    for (int i = 0; i < length-1; i++) {
        cout << arr[i] << ", ";
    }

    cout << arr[length-1];
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8,9,0};
    int length = sizeof(arr)/sizeof(arr[0]);
    printArray(arr, length);
    reverse(arr, length);
}
