#include <iostream>
using namespace std;

struct Patient {
    int id;
    string name;
}; 

struct UNI {
    int d;
    int m;
    int y;
    int n;
    Patient *f = NULL;
};


void Input(UNI &a) {
    cout << "Enter date " << endl;
    cout << "Enter day: "; cin >> a.d;
    cout << "Enter month: "; cin >> a.m;
    cout << "Enter year: "; cin >> a.y;
    cout << "Enter number of F0: "; cin >> a.n;
    a.f = new Patient[a.n];
    for(int i = 0; i < a.n; i++) {
        cout << "Enter info of F0 " << i << ": " << endl;
        cout << "Enter id: "; cin >> a.f[i].id;
        cout << "Enter name: "; cin >> a.f[i].name;
    }
}

void Sort(UNI *a, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i + 1; j < n; j++) {
            if(a[i].n < a[j].n) {
                UNI temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}



void Output(UNI *a, int n) {
    for(int i = 0; i < n; i++) {
        cout << i << ". " << a[i].d << "/" << a[i].m << "/" << a[i].y << ": " << a[i].n << endl;
        for(int j = 0; j < a[i].n; j++) 
            cout << a[i].f[j].id << ": " << a[i].f[j].name << endl;
    }
}

int main() {
    cout << "Enter days: " << endl;
    int day; cin >> day;
    UNI* KHTN = NULL;
    KHTN = new UNI[day];

    for(int i = 0; i < day; i++) 
        Input(KHTN[i]);
    
    Sort(KHTN, day);

    day++;
    KHTN = new UNI[day];
    Input(KHTN[day]);

    Output(KHTN, day);

    
    delete[] KHTN;
}