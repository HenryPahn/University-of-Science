#include <iostream>
#include "m.h"
using namespace std;

int Total(int t, int n, int x) {
    if(n == 0) return t;
    return pow(x, n) + Total(t, n -= 1, x);
}

int main() {
    int x; cout << "Enter x: "; cin >> x;
    int n; cout << "Enter n: "; cin >> n; 
    int s = 0;
    s = Total(s, n, x);
    cout << "Value: " << s;
    return 0;
}