#include <iostream>
#include "OP.h"
using namespace std;

bool PosOrNeg(int n) {
    if(n >= 0) return false;
    return true;
}

int Sum(int s, int *a, int n) {
    if(n == 1)
        if(PosOrNeg(a[0])) 
            return s *= a[0];
        else return s;
    if(PosOrNeg(a[n - 1])) s *= a[n - 1];
    return Sum(s, a, n -= 1);
}


int main() {
    int n; cout << "Enter n: "; cin >> n; 
    int* a = new int[n];
    
    Input(a, n);
    Output(a, n);

    int s = 1;
    s = Sum(s, a, n);
    cout << "Value: " << s;
    delete []a;
    return 0;
}
