#include <iostream>
#include <fstream>
using namespace std;

void Scan(int *a) {
    ifstream f ("input.txt");
    int i = 0;
    if(f.is_open()) {
        while(f.good()) {
            f >> a[i];
            i++;
        }
        f.close();
    }
}

bool Check(int n) {
    if(n < 2) return false;
    if(n > 2) 
        for(int i = 3; i < n; i++) 
            if(n % i == 0)
                return false;
    return true;
}

void Write(int *a) {
    ofstream f;
    f.open ("F:\\Code\\C++\\K-thu-t-L-p-T-nh\\File\\txt file\\output.txt");
    for(int i = a[0]; i <= a[1]; i++) 
        if(Check(i))
            f << i << " ";
    f.close();
}

int main() {
    int *a = new int[2];
    Scan(a);
    Write(a);
    delete[] a;
    return 0;
}