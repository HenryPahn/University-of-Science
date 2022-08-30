#include <iostream>
using namespace std;

void Permutation(string a, int l, int n) {
    if(l == n) cout << a << endl;
    else {
        for(int i = l; i <= n; i++) {
            swap(a[l], a[i]);
            Permutation(a, l + 1, n);
            swap(a[i], a[l]);
        }
    }
}

int main() {
    string a = "ABC";
    int n = a.size();
    int l = 0;
    Permutation(a, l, n - 1);
    return 0;
}