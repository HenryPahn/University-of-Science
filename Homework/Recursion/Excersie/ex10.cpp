#include <iostream>
using namespace std;

int Check(int n) {
    if(n == 0) return true;
    if((n % 10) % 2 != 0) return false;
    return Check(n /= 10);
}

int main() {
    int n;
    bool check; 
    cout << "Enter n: "; cin >> n;
    check = Check(n);
    if(check) cout << "YES";
    else cout << "NO";
    return 0;
}