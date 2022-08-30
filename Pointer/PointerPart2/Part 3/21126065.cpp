#include <iostream>
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
    // Neu tu va mau am thi phan so duong
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

Fraction Sumation(Fraction sum, Fraction f) {
    Fraction tempFraction;
    tempFraction.numerator = sum.numerator * f.denominator + sum.denominator * f.numerator;
    tempFraction.denominator = sum.denominator * f.denominator;
    MakeSense(tempFraction);
    return tempFraction;
}

void ReducedFraction(Fraction f) {
    ReducingFraction(f);
    // Neu tu chia het cho mau thi xuat ra so nguyen to, khong thi xuat ra phan so
    if(f.numerator % f.denominator == 0)
        cout << f.numerator / f.denominator << endl;
    else cout << f.numerator << "/" << f.denominator << endl;
}

void GetResult(double &result, Fraction f) {
    // Tao mang ket qua cua tu chia cho mau cua mang phan so
    result = (double) f.numerator / f.denominator;
}

void SortArrayOfFractions(double r[], Fraction *f, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i; j < n; j++) {
            if(r[i] > r[j]) {
                // So sanh mang ket qua de sap xep tu mau cua tung mang phan so
                double temp = r[i];
                r[i] = r[j];
                r[j] = temp;

                Fraction t = f[i];
                f[i] = f[j];
                f[j] = t;
            }
        }
    }
}

void CheckK(double r[], Fraction k, int n) {
    // Lau tu chia cho mau cua phan so K
    double result = (double) k.numerator / k.denominator;

    // Kiem tra xem ket qua cua K co tren mang ket qua cac phan so 
    bool check = false;
    for(int i = 0; i < n; i++) 
        if(r[i] == result) check = true;

    if(check) 
        cout << "1" << endl;
    else cout << "0" << endl;
}

void DeleteFraction(Fraction* temp) {
    delete []temp;
}

int main() {
    Fraction *f = NULL;

    int N;
    cout << "Enter N: ";
    cin >> N;

    f = AllocateFraction(N);
    // Nhap 2 phan so 
    for(int i = 0; i < N; i++) 
        GetFraction(f[i]);
    cout << "******************************" << endl;
    // Chuyen doi giau cua tu va mau cua 2 phan so
    for(int i = 0; i < N; i++) 
        MakeSense(f[i]);
    // In ra 2 phan so chua rut gon
    cout << "Initial fractions: " << endl;
    for(int i = 0; i < N; i++) 
        DisplayInitialFraction(f[i]);
    cout << "******************************" << endl;
    // Tong cua mang phan so
    Fraction sum;
    sum.numerator = f[0].numerator;
    sum.denominator = f[0].denominator;
    for(int i = 1; i < N; i++) 
        sum = Sumation(sum, f[i]);
    cout << "Sumation: ";
    ReducedFraction(sum);
    cout << "******************************" << endl;
    // Phan so rut gon
    cout << "Reduced fractions: " << endl;
    for(int i = 0; i < N; i++) {
        cout << "Fraction: ";
        ReducedFraction(f[i]);
    }
    cout << "******************************" << endl;
    // Sap xep mang phan so tang dan
    double result[N];
    for(int i = 0; i < N; i++) 
        GetResult(result[i], f[i]);
    SortArrayOfFractions(result, f, N);
    cout << "Increasing array of fractions: " << endl;
    for(int i = 0; i < N; i++) {
        ReducedFraction(f[i]);
    }
    cout << "******************************" << endl;
    // Kiem tra K co trong mang phan so
    Fraction k;
    cout << "Enter K: " << endl;
    GetFraction(k);
    cout << "Does K exist in array?: ";
    CheckK(result, k, N);
    
    DeleteFraction(f);
    return 0;
}