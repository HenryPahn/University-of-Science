#include <iostream>
#include "OP.h"
using namespace std;

int Sum(int s, int *a, int n) {
    if(n < 0) return s;
    s += *(a + n - 1);
    return Sum(s, a, n - 1);  
}


int main() {
    // int n; cout << "Enter n: "; cin >> n; 
    // int* a = new int[n];
    
    // Input(a, n);
    // Output(a, n);
    // int s = 0;
    // s = Sum(s, a, n);
    // cout << "Value: " << s;
    // delete []a;
    cout << 11 / 4;
    return 0;
}