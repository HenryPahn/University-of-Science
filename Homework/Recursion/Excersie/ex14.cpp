#include <iostream>
#include "OP.h"
using namespace std;

bool Pos(int n) {
    if(n >= 0) return true;
    return false;
}

bool Check(bool c, int *a, int n) {
    if(n == 1) 
        if(Pos(a[0])) return false;
        else return true;
    if(Pos(a[n - 1])) return false;
    return Check(c, a, n -= 1);
}


int main() {
    int n; cout << "Enter n: "; cin >> n; 
    int* a = new int[n];
    
    Input(a, n);
    Output(a, n);

    bool c = true;
    c = Check(c, a, n);
    if(c) cout << "YES";
    else cout << "NO";
    delete []a;
    return 0;
}
