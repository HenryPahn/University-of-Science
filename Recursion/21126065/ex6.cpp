#include <iostream>
#include "OP.h"
#include "m.h"
using namespace std;

int Sum(int temp, int x, int n, int *a, int i) {
    if(n < 0) return temp;
    return (pow(n, 2) * a[i]) + Sum(temp, x, n -= 1, a, i += 1);
}

int main() {
    int x; cout << "Enter x: "; cin >> x;
    int n; cout << "Enter n: "; cin >> n; 
    int* a = new int[n];
    Input(a, n);
    Output(a, n);
    int s = 0, i = 0;
    s = Sum(s, x, n, a, i);
    cout << "Value: " << s;
    delete []a;
    return 0;
}