#include <iostream>
using namespace std;

int Count(int temp, int n) {
    if(n == 0) return temp;
    if((n % 10) % 2 != 0) temp++;
    return Count(temp, n /= 10);
}

int main() {
    int n, count = 0; 
    cout << "Enter n: "; cin >> n;
    count = Count(count, n);
    cout << "Number of chars: " << count;
    return 0;
}