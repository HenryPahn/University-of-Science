#include <iostream>
using namespace std;

int Partition(int a[], int l, int r) {
    int pivot = a[r];
    int i = l - 1;
    for(int j = l; j <= r; j++) {
        if(a[j] < pivot) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return (i + 1);
}

void QuickSort(int a[], int l, int r) {
    if(l < r) {
        int pi = Partition(a, l, r);
        QuickSort(a, l, pi - 1);
        QuickSort(a, pi + 1, r);
    }
}

void Output(int a[], int n) {
    for(int i = 0; i < n; i++) 
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = {9,4,19,2,7,9,5,15,23,3};
    int num = sizeof(arr) / sizeof(arr[0]);
    Output(arr, num);
    QuickSort(arr, 0, num - 1);
    Output(arr, num);
    return 0;
}