#include <iostream>
#include <fstream>
using namespace std;

void Scan(int*a, int &i) {
    ifstream f ("SA.txt");
    if(f.is_open()) {
        while(f.good()) {
            f >> a[i];
            i++;
        }
    }
    i--;
    f.close();
}

void Write(int* a, int n) {
    ofstream f;
    f.open("F:\\Code\\C++\\K-thu-t-L-p-T-nh\\File\\txt file\\WA.txt");
    for(int i = 0; i < n; i++) 
        f << a[i] << " ";
    f.close();
}

int main() {
    int n = 0;
    int *a = new int[0];
    Scan(a, n);
    Write(a, n);
    delete[] a;
}