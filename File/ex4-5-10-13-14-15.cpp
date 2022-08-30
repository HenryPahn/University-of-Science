#include <iostream>
#include <fstream>
using namespace std;

struct Fraction {
    int num;
    int den;
};

void Scan(Fraction *a) {
    ifstream f ("SMOF.txt");    
    if(f.is_open()) {
        char t;
        f >> a->num;
        f >> t;
        f >> a->den;
        f.close();
    }
}

void Write(Fraction *a) {
    ofstream f;
    f.open ("F:\\Code\\C++\\K-thu-t-L-p-T-nh\\File\\txt file\\WF.txt");
    f << a->num << "/" << a->den;
    f.close();
}

void ex4a13() {
    Fraction *a = new Fraction;
    Scan(a);
    Write(a);
    delete a;
}

void ScanA(Fraction *a, int &i) {
    ifstream f ("SMOF.txt");
    if(f.is_open()) {
        while(i <= 3) {
            char t;
            f >> a[i].num;
            f >> t;
            f >> a[i].den;
            i++;
        }
        f.close();
    }
    i--;
} 

void WriteA(Fraction *a, int n) {
    ofstream f;
    f.open ("F:\\Code\\C++\\K-thu-t-L-p-T-nh\\File\\txt file\\WAOF.txt");
    for(int i = 0; i < n; i++) 
        f << a[i].num << "/" << a[i].den << " ";
    f.close();
}

void ex5a14() {
    Fraction *a = new Fraction[3]; 
    int n = 0;
    ScanA(a, n);
    WriteA(a, n);
    delete[] a;
}

Fraction** Allocate(int n) {
    Fraction** temp = new Fraction*[n];
    for(int i = 0; i < n; i++)
        temp[i] = new Fraction[n];
    return temp;
}

void ScanM(Fraction **a, int &n) {
    ifstream f ("SMOF.txt");
    if(f.is_open()) {
        while(f.good()) {
            for(int i = 0; i < 3; i++)
                for(int j = 0; j < 3; j++) {
                    char t;
                    f >> a[i][j].num;
                    f >> t;
                    f >> a[i][j].den;
                }
        }
        f.close();
    }
    n = 3;
}

void WriteM(Fraction **a, int n) {
    ofstream f;
    f.open("F:\\Code\\C++\\K-thu-t-L-p-T-nh\\File\\txt file\\WMOF.txt");
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) 
            f << a[i][j].num << "/" << a[i][j].den << " ";
        f << endl;
    }
    f.close();
}

void ex15() {
    Fraction **a = Allocate(3);
    int n = 0;
    ScanM(a, n);
    WriteM(a, n);
}

int main() {
    ex4a13();
    ex5a14();
    ex15();
    return 0;
}