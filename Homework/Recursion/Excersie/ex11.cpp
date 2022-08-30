#include <iostream>
#include "OP.h"
using namespace std;

int Sum(int s, int *a, int n) {
    if(n == 1) return s += a[0];
    return a[n - 1] + Sum(s, a, n -= 1);
}


int main() {
    int n; cout << "Enter n: "; cin >> n; 
    int* a = new int[n];
    
    Input(a, n);
    Output(a, n);

    int s = 0;
    s = Sum(s, a, n);
    cout << "Value: " << s;
    delete []a;
    return 0;
}