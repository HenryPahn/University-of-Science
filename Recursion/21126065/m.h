#include <iostream>
using namespace std;

int pow(int x, int n) {
    int temp = 1;
    for(int i = 0; i < n; i++) 
        temp *= x;
    return temp;
}

int factorial(int n) {
    int temp = 1;
    for(int i = 1; i <= n; i++)
        temp *= i;
    return temp;
}