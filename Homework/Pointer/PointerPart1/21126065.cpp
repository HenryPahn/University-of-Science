#include <iostream>
using namespace std;

void bai1() {
    int a = 1, b = 3;
    cout << "Bai tap 1!!!" << endl;
    for(int i = 1; i <= 5; i++) {
        cout << "Lan chay " << i << ":" << endl;
        cout << "Gia tri cua a: " << a << endl;
        cout << "Dia chi cua a: " << &a << endl;
        cout << "Gia tri cua b: " << b << endl;
        cout << "Dia chi cua b: " << &b << endl;
    }
    cout << "************************" << endl;
}

void bai2() {
    int a = 1; 
    int *pointer; 
    float b = 0.00;
    cout << "Bai tap 2!!!" << endl;
    cout << "2.1" << endl;
    cout << "Gia tri cua a: " << a << endl;
    cout << "Dia chi cua a: " << &a << endl;
    pointer = &a; 
    cout << "Gia tri cua p: " << *pointer << endl;
    cout << "Dia chi cua p: " << &pointer << endl;
    cout << "2.2" << endl;
    *pointer = 10000;
    cout << "Gia tri cua p: " << *pointer << endl;
    cout << "Dia chi cua p: " << &pointer << endl;
    cout << "2.3" << endl;
    int c = (int) b;
    pointer = &c;
    cout << "Gia tri cua p: " << *pointer << endl;
    cout << "Dia chi cua p: " << &pointer << endl;
    cout << "************************" << endl;
}

void bai3() {
    char a = 'A', *pa;
    float x = 2.5F, *px;
    int i = 1, *m;
    pa = &a;
    px = &x;
    m = &i;
    cout << "Bai tap 3!!!" << endl;
    cout << "Gia tri cua a: " << a << endl;
    printf("Dia chi cua gia tri a: %p\n", &a);
    printf("Gia tri cua p: %p\n", pa);
    cout << "Dia chi cua pa: " << &pa << endl;
    cout << "Gia tri cua px: " << px << endl;
    cout << "Dia chi cua px: " << &px << endl;
    cout << "Gia tri cua m: " << m << endl;
    cout << "Dia chi cua m: " << &m << endl;
    cout << "Gia tri cua x: " << x << endl;
    cout << "Dia chi cua x: " << &x << endl;
    cout << "Gia tri cua i: " << i << endl;
    cout << "Dia chi cua i: " << &i << endl;
    cout << "************************" << endl;
}

void bai4() {
    cout << "Bai tap 4!!!" << endl;
    char a = 'A', b = 'B', *pa, *pb; // line 1
    pa = &a; // line 2
    pb = &b;
    printf("pa = %p\n", pa);
    printf("pb = %p\n", pb);
    pb = pa; // line 3
    printf("pa = %p, pb = %p\n", pa, pb); // line 4
    pa = &b; // Line 5
    printf("pa = %p, pb = %p\n", pa, pb); //line 6
}

int main() {
    bai1();
    bai2();
    bai3();
    bai4();
}