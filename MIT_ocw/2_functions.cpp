#include <iostream>
using namespace std;

int sum(const int a, const int b, const int c=0, const int d=0) { 
    return a+b+c+d; 
}
double sum(const double a, const double b, const double c = 0.0, const double d = 0.0) { 
    return a+b+c+d; 
}

int superSum(int *list, int length) {
    // int answer;
    // for (int i = 0; i < length; i++) {
    //     answer += list[i];
    // } 
    
    if (length > 1) { 
        int answer = list[0] + superSum(list+1, length-1);
        return answer;
    } else {
        return list[0];
    }
}

int main() {
    // This won't know which version of sum() to use
    //cout << sum(1, 10.0);
    
    int list[] = {1,2,3,4}; 
    cout << superSum(list, 4);
}

