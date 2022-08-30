#include <iostream>
#include <math.h>
using namespace std;

#define pi 3.14

struct Point {
    double x; 
    double y;
};

struct Circle {
    Point center;
    double radius;
};

Circle* Allocate(int n) {
    Circle* temp = new Circle[n];
    return temp;
}

void EnterXAndY(Point &c) {
    cout << "Enter x and y: ";
    cin >> c.x >> c.y;
}

void EnterCircle(Circle &c) {
    EnterXAndY(c.center);
    cout << "Enter radius: ";
    cin >> c.radius;
}

void PrintCircle(Circle c) {
    cout << "X: " << c.center.x << endl;
    cout << "y: " << c.center.y << endl;
    cout << "Radius: " <<  c.radius << endl;
}

double Area(int r) {
    return pi * r * r;
}

void AreaOfCircle(Circle c) {
    cout << "Perimeter: " << (double) 2 * c.radius * pi << endl;
    cout << "Area: " << Area(c.radius) << endl;
}

void EnterPoint(Point &p) {
    cout << "Enter x and y: ";
    cin >> p.x >> p.y;
}

double Margin(Circle c, Point p) {
    return sqrt((double) pow(c.center.x - p.x, 2) + pow(c.center.y - p.y, 2));
}

void CheckPoint(Circle c, Point p) {
    if(Margin(c, p) == c.radius)
        cout << "Point is on circle!!!" << endl;
    else if(Margin(c, p) < c.radius)
        cout << "Point is inside circle!!!" << endl;
    else cout << "Point is outside circle!!!" << endl;
}

void SortArray(Circle *c, int n) {
    double result[n];
    for(int i = 0; i < n; i++)
        result[i] = Area(c[i].radius);
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n; j++) {
            if(result[i] > result[j]) {
                double temp = result[i];
                result[i] = result[j];
                result[j] = temp;

                Circle t = c[i];
                c[i] = c[j];
                c[j] = t;
            }
        }
    }
}

int main() {
    Circle *c = NULL;
    c = Allocate(1);

    EnterCircle(c[0]);
    cout << "******************************" << endl;
    PrintCircle(c[0]);
    cout << "******************************" << endl;
    AreaOfCircle(c[0]);
    cout << "******************************" << endl;
    Point *p = new Point[1];
    EnterPoint(p[0]);
    CheckPoint(c[0], p[0]);
    cout << "******************************" << endl;
    Circle *arrayOfCircle = NULL;
    int n; 
    cout << "Enter n: ";
    cin >> n;
    arrayOfCircle = Allocate(n);
    for(int i = 0; i < n; i++) {
        EnterCircle(arrayOfCircle[i]);
        cout << endl;
    }
    for(int i = 0; i < n; i++) {
        PrintCircle(arrayOfCircle[i]);
        cout << endl;
    }
    cout << "******************************" << endl;
    SortArray(arrayOfCircle, n);
    cout << "******************************" << endl;

    delete[]c;
    delete[]p;
    delete[]arrayOfCircle;
    return 0;
}