#include <iostream>
using namespace std;

int Sum(int sum, int n) {
    if(n == 0) return sum;
    sum += n % 10;
    return Sum(sum, n /= 10);
}

int main() {
    int n; cout << "Enter n: "; cin >> n;
    int sum = 0;
    sum = Sum(sum, n);
    cout << "Value: " << sum;
    return 0;
}