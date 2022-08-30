#include <iostream>
using namespace std;

int Count(int temp, int n) {
    if(n == 0) return temp;
    return Count(temp += 1, n /= 10);
}

int main() {
    int n, count = 0; 
    cout << "Enter n: "; cin >> n;
    count = Count(count, n);
    cout << "Number of chars: " << count;
    return 0;
}