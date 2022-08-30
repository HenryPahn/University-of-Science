#include <iostream>
using namespace std;

int Total(int t, int n) {
    if(n == 0) return t;
    t *= n;
    return Total(t, n -= 1);
}

int main() {
    int n; cout << "Enter n: "; cin >> n;
    int T = 1;
    T = Total(T, n);
    cout << "Value: " << T;
    return 0;
}