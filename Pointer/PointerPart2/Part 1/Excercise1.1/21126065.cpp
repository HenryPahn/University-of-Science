#include <iostream>
#include <stdio.h>
using namespace std; 

int EnterN(int MAX) {
    int n;
    cout << "Enter n: ";
    cin >> n;
    while(n < 1 || n > MAX) {
        cout << "Enter n again: ";
        cin >> n;
    }
    return n;
}

int* Allocate(int n) {
    int* temp = new int[n];
    return temp;
}

void InputArray(int* a, int n) {
    cout << "Enter array: ";
    for(int i = 0; i < n; i++) 
        cin >> *(a + i); 
}

void PrintArray(int* a, int n) {
    for(int i = 0; i < n; i++)
        cout << *(a + i) << " ";
}

bool CheckDivisor(int x, int n) {
    // Kiem tra co phai uoc so
    if(x % n == 0) return true;
    return false;
}

void Request1(int* a, int n, int x, int &count) {
    for(int i = 0; i < n; i++) {
        if(CheckDivisor(x, a[i])) {
            printf("Value of divisor %d: %d\n", count, a[i]);
            printf("Address of divisor %d: %p\n", count, &a[i]);
            count++;
        }
    }
}

void MoveDivisor(int* a, int k, int n, int x) {
    // Di chuyen so khong phai la uoc so len dau mang
    for(int i = k - 1; i >= 0; i--) 
        a[i + 1] = a[i];
    a[0] = x;
}

void Request2(int* a, int n, int x, int count) {
    for(int i = 0; i < n; i++) {
        // Di chuyen so khong phai la uoc so len dau mang
        if(!CheckDivisor(x, a[i])) 
            MoveDivisor(a, i, n, a[i]); 
    }
    // Sap xep lai cac so khong phai la uoc so theo thu tu tang dan
    count = n - count + 1;
    for(int i = 0; i < count - 1; i++) {
        for(int j = i; j < count; j++) {
            if(a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
    cout << "After sorting array: ";
    PrintArray(a, n);
    cout << endl;
}



void Delete(int* temp) {
    delete temp;
}

void ex1() {
    int *array = NULL;
    int numberOfElement = EnterN(10000);
    array = Allocate(numberOfElement);

    InputArray(array, numberOfElement);
    cout << "******************************" << endl;
    int x; 
    cout << "Enter X: ";
    cin >> x;
    cout << "******************************" << endl;
    int count = 1;
    Request1(array, numberOfElement, x, count);
    cout << "******************************" << endl;
    Request2(array, numberOfElement, x, count);
    cout << "******************************" << endl;
    Delete(array);
}

void RequestedNumbers(int* a, int n) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(a[i] % 10 == 6 && a[i] % 6 == 0) 
            count++;
    }
    cout << "Number of requested numbers: " << count << endl;
}

bool CheckPrimeNumber(int n) {
    // Kiem tra so nguyen to 
    if (n < 2)
        return false;
    if (n == 2)
        return true;
    if (n > 2) {
        for(int i = 2; i < n; i++) {
            if (n % i == 0) 
                return false;
        }
    }
    return true;
}

void AverageOfPrimeNumbers(int* a, int n) {
    int count = 0, sum = 0;
    for(int i = 0; i < n; i++) {
        // Kiem tra so nguyen to
        if(CheckPrimeNumber(a[i])) {
            count++;
            sum += a[i];
        }
    }
    cout << "Average of prime numbers: " << (double) sum / count << endl;
}

bool CheckPrimeArray(int* a, int n, int x) {
    // Kiem tra so nguyen to da co trong mang so nguyen to chua
    for(int i = 0; i < n; i++) 
        if(x == a[i]) return false;
    return true;
}

void DistinctPrimeNumbers(int* a, int n) {
    int ArrayOfDistinctPrimeNumbers[15], count = 0;
    for(int i = 0; i < n; i++) {
        if(CheckPrimeNumber(a[i]) & CheckPrimeArray(ArrayOfDistinctPrimeNumbers , count, a[i])) {
            ArrayOfDistinctPrimeNumbers[count] = a[i];
            count++;
        } 
    }
    cout << "Number of distinct prime numbers: " << count << endl;
}

void ex2() {
    int* array = NULL;
    int numberOfElement = EnterN(15);
    array = Allocate(numberOfElement);
    
    InputArray(array, numberOfElement);
    cout << "******************************" << endl;
    RequestedNumbers(array, numberOfElement); 
    cout << "******************************" << endl;
    AverageOfPrimeNumbers(array, numberOfElement);
    cout << "******************************" << endl;
    DistinctPrimeNumbers(array, numberOfElement);
    cout << "******************************" << endl;
    Delete(array);
}

void MovePrimeNumbersToB(int* a, int* b, int n, int &m) {
    for(int i = 0; i < n; i++) {
        // Kiem tra neu khong phai so nguyen to thi them vao mang B
        if(!CheckPrimeNumber(a[i])) {
            b[m] = a[i];
            m++;
        }
    }
    cout << "Array B: ";
    PrintArray(b, m);
    cout << endl;
}

void SortArrayB(int* b, int n) {
    for(int i = 0; i < n - 1; i++) {
        for(int j = i; j < n; j++) {
            if(b[i] < b[j]) {
                int temp = b[i];
                b[i] = b[j];
                b[j] = temp;
            }
        }
    }
    cout << "Array B: ";
    PrintArray(b, n);
    cout << endl;
}

void RemovePrimeNumber(int* a, int& n, int k) {
    // Xoa so nguyen to ra khoi mang
    for(int i = k; i < n - 1; i++) {
        a[i] = a[i + 1];
    }
    n--;
}

void DeletePrimeNumbersFromA(int* a, int n) {
    for(int i = 0; i < n; i++) {
        // Kiem tra so nguyen to
        if(CheckPrimeNumber(a[i])) {
            // Xoa so nguyen to ra khoi mang
            RemovePrimeNumber(a, n, i);
            i--;
        }
    }
    cout << "Array A: ";
    PrintArray(a, n);
    cout << endl; 
}

void ex3() {
    int* arrayA = NULL;
    int numberOfElement = EnterN(10);
    arrayA = Allocate(numberOfElement); 

    InputArray(arrayA, numberOfElement);
    cout << "******************************" << endl;
    int *arrayB = NULL, numberOfElementB = 0;
    arrayB = Allocate(numberOfElement);
    MovePrimeNumbersToB(arrayA, arrayB, numberOfElement, numberOfElementB);
    cout << "******************************" << endl;
    SortArrayB(arrayB, numberOfElementB);
    cout << "******************************" << endl;
    DeletePrimeNumbersFromA(arrayA, numberOfElement);
    cout << "******************************" << endl;

    Delete(arrayA);
    Delete(arrayB);
}

bool CheckAInB(int* b, int n, int x) {
    // Kiem tra phan tu trong mang A co xuat hien o mang B hay khong
    for(int i = 0; i < n; i++) 
        if(b[i] == x) return false;
    return true;
}

void Elements(int* a, int* b, int n, int m) {
    cout << "Elements in A do not exist in B: ";
    for(int i = 0; i < n; i++) {
        if(CheckAInB(b, m, a[i])) 
            cout << a[i] << " ";
    }
    cout << endl;
}

void ArrayC(int* a, int* b, int n, int m) {
    // In cac phan tu trong mang A khong xuat hien o mang B
    cout << "Array C: ";
    for(int i = 0; i < n; i++) {
        if(CheckAInB(b, m, a[i])) 
            cout << a[i] << " ";
    }
    // In mang B
    PrintArray(b, m);
    cout << endl;
}

void ex4() {
    int* arrayA = NULL;
    int numberOfElementA = EnterN(25);
    arrayA = Allocate(numberOfElementA);
    InputArray(arrayA, numberOfElementA);
    cout << endl;
    int* arrayB = NULL;
    int numberOfElementB = EnterN(25);
    arrayB = Allocate(numberOfElementB);
    InputArray(arrayB, numberOfElementB);
    cout << "******************************" << endl;
    Elements(arrayA, arrayB, numberOfElementA, numberOfElementB);
    cout << "******************************" << endl;
    ArrayC(arrayA, arrayB, numberOfElementA, numberOfElementB);
    cout << "******************************" << endl;
}

int main() {
    ex1();
    ex2();
    ex3();
    ex4();
}