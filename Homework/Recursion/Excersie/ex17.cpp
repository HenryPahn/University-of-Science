#include <iostream>
#include "OP.h"
using namespace std;

bool Pos(int n) {
    if(n >= 0) return true;
    return false;
}

int Count(int c, int *a, int n) {
    if(n == 0) return c;
    if(Pos(a[n - 1])) c += 1;
    return Count(c, a, n -= 1);
}


int main() {
    int n; cout << "Enter n: "; cin >> n; 
    int* a = new int[n];
    
    Input(a, n);
    Output(a, n);
    a[2] = -4;
    int c = 0;
    c = Count(c, a, n);
    cout << "value: " << c; 
    delete []a;
    return 0;
}
