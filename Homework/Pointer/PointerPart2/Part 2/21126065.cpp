#include <iostream>
#include <stdio.h>
using namespace std;


struct Fraction {
    int numerator;
    int denominator;
};

Fraction* AllocateFraction(int n) {
    Fraction* temp = new Fraction[n];
    return temp;
}

void GetFraction(Fraction &f) {
    cout << "Enter numerator and denominator: ";
    cin >> f.numerator >> f.denominator;
}

void MakeSense(Fraction &f) {
    // Neu tu va mau deu am thi phan so duong
    if(f.denominator < 0 && f.numerator < 0) {
        f.denominator = - f.denominator;
        f.numerator = - f.numerator;
    }

    // Neu mau am thi tu duong 
    if(f.denominator < 0) {
        f.denominator = - f.denominator;
        f.numerator = - f.numerator;
    }
}

void DisplayInitialFraction(Fraction f) {
    cout << "Fraction: ";
    cout << f.numerator << "/" << f.denominator << endl;
}

void ReducingFraction(Fraction &f) {
    // Tim uoc so lon nhat cua tu va mau de toi gian phan so
    int GCF;
    for(int i = 1; i <= f.denominator; i++) 
        if(f.denominator % i == 0 && f.numerator % i == 0) 
            GCF = i;
    
    f.denominator /= GCF;
    f.numerator /= GCF;
}

void Sumation(Fraction f1, Fraction f2) {
    Fraction f;
    cout << "Sumation: ";
    f.numerator = f1.numerator * f2.denominator + f2.numerator * f1.denominator;
    f.denominator = f1.denominator * f2.denominator;
    ReducingFraction(f);
    cout << f.numerator << "/" << f.denominator << endl;
}

void Subtraction(Fraction f1, Fraction f2) {
    Fraction f;
    cout << "Subtraction: ";
    f.numerator = f1.numerator * f2.denominator - f2.numerator * f1.denominator;
    f.denominator = f1.denominator * f2.denominator;
    if(f.numerator < 0) f.numerator = - f.numerator;
    ReducingFraction(f);
    cout << f.numerator << "/" << f.denominator << endl;
}

void Multiplication(Fraction f1, Fraction f2) {
    Fraction f; 
    cout << "Multiplication: ";
    f.numerator = f1.numerator * f2.numerator;
    f.denominator = f1.denominator * f2.denominator;
    ReducingFraction(f);
    cout << f.numerator << "/" << f.denominator << endl;
}

void Division(Fraction f1, Fraction f2) {
    Fraction f; 
    cout << "Division: ";
    f.numerator = f1.numerator * f2.denominator;
    f.denominator = f1.denominator * f2.numerator;
    MakeSense(f);
    ReducingFraction(f);
    cout << f.numerator << "/" << f.denominator << endl;
}

void ReducedFraction(Fraction f) {
    ReducingFraction(f);
    cout << "Fraction: ";
    // Neu tu chia het cho mau thi xuat ra so nguyen to, khong thi xuat ra phan so
    if(f.numerator % f.denominator == 0)
        cout << f.numerator / f.denominator << endl;
    else cout << f.numerator << "/" << f.denominator << endl;
}

void CompareAtoB(Fraction f1, Fraction f2) {
    // Lat tu chia cho mau. Dem ket qua di so sanh
    double tf1, tf2;
    tf1 = (double) f1.numerator / f1.denominator;
    tf2 = (double) f2.numerator / f2.denominator;

    if(tf1 > tf2) 
        cout << "1" << endl;
    else if(tf1 == tf2)
        cout << "0" << endl;
    else cout << "-1" << endl;
}

void DeleteFraction(Fraction* temp) {
    delete []temp;
}

int main() {
    Fraction *f = NULL;
    f = AllocateFraction(2);
    // Nhap 2 phan so 
    for(int i = 0; i < 2; i++) 
        GetFraction(f[i]);
    cout << "******************************" << endl;
    // Chuyen doi giau cua tu va mau cua 2 phan so
    for(int i = 0; i < 2; i++) 
        MakeSense(f[i]);
    // In ra 2 phan so chua rut gon
    cout << "Initial fractions: " << endl;
    for(int i = 0; i < 2; i++) 
        DisplayInitialFraction(f[i]);
    cout << "******************************" << endl;
    // Phep tinh cong, hieu, nhan, chia
    Sumation(f[0], f[1]);
    cout << endl;
    Subtraction(f[0], f[1]);
    cout << endl;
    Multiplication(f[0], f[1]);
    cout << endl;
    Division(f[0], f[1]);
    cout << "******************************" << endl;
    // In 2 phan so da rut gon
    cout << "Reduced fractions: " << endl;
    for(int i = 0; i < 2; i++) 
        ReducedFraction(f[i]);
    cout << "******************************" << endl;
    // So sanh 2 phan so
    cout << "Comparision A with B: ";
    CompareAtoB(f[0], f[1]);

    DeleteFraction(f);
    return 0;
}