#include <iostream>
#include "OP.h"
using namespace std;

int Find(int max, int *a, int n) {
    if(n == 1) 
        if(max < a[0]) return a[0];
        else return max;
    if(max < a[n - 1]) max = a[n - 1];
    return Find(max, a, n -= 1);
}


int main() {
    int n; cout << "Enter n: "; cin >> n; 
    int* a = new int[n];
    
    Input(a, n);
    Output(a, n);

    int max = a[0];
    max = Find(max, a, n);
    cout << "Value: " << max;
    delete []a;
    return 0;
}
