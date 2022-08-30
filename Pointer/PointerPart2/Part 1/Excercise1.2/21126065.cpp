#include <iostream>
#include <stdio.h>
using namespace std;

void EnterColumAndRow(int &c, int &r) { 
    cout << "Enter column and row: ";
    cin >> c >> r;
}

int** Allocate(int n, int m) {
    int** a = new int*[n];
    for(int i = 0; i < n; i++) 
        a[i] = new int[m];
    return a;
}

void EnterArray(int **a, int n, int m) {
    cout << "Enter array: " << endl; 
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];
}

void PrintArray(int **a, int n, int m) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void TotalOfPositiveNumbers(int** a, int n, int m) {
    int total = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] > 0) 
                total += a[i][j];
    cout << "Total of positive numbers: " << total << endl;
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

void NumberOfPrimeNumbers(int **a, int n, int m) {
    int count = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            if(CheckPrimeNumber(a[i][j])) 
                count++;
    cout << "Number of prime numbers: " << count << endl;
}

void MaxNumber(int **a, int n, int m) {
    int max = a[0][0];
    for(int i = 0; i < m - 1; i++) 
        if(max < a[0][i])
            max = a[0][i];

    for(int i = 0; i < n - 1; i++)
        if(max < a[i][m - 1])
            max = a[i][m - 1];
    
    for(int i = 1; i <= m - 1; i++) 
        if(max < a[n - 1][i])
            max = a[n - 1][i];
        
    for(int i = 1; i <= n - 1; i++)
        if(max < a[i][0])
            max = a[i][0];
    
    cout << "Maximun element: " << max << endl;
}

void MinimunNegativeNumber(int **a, int n, int m) {
    int min;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            if(a[i][j] > 0 && min > a[i][j])
                min = a[i][j];
    cout << "Minimun negative number: " << min << endl;    
}

void ColumnsContainingNegativeNumbers(int **a, int n, int m) {
    cout << "Columns containing negative numbers: " << endl;
    for(int i = 0; i < n; i++) {
        bool check = false;
        for(int j = 0; j < m; j++) {
            if (a[i][j] < 0) {
                check = true;
                break;
            }   
        }
        if(check) {
            cout << "Column " << i << ": ";
            for(int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void ColumnsContainingFullEvenNumbers(int **a, int n, int m) {
    cout << "Columns containing full even numbers: " << endl;
    for(int i = 0; i < n; i++) {
        bool check = true;
        for(int j = 0; j < m; j++) {
            if(a[i][j] % 2 != 0) {
                check = false;
                break;
            }
        }
        if(check) {
            cout << "Columns " << i << ": ";
            for(int j = 0; j < m; j++) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}

void Horse(int **a, int n, int m) {
    int count = 0;
    for(int i = 0; i < n; i++) {
        int horse = a[i][0], pos = 0;
        for(int j = 0; j < m; j++) {
            if(horse < a[i][j]) {
                horse = a[i][j];
                pos = j;
            }
        }
        bool check = true;
        for(int k = 0; k < n; k++) 
            if(horse > a[k][pos]) check = false;
        if(check) count++;
    }
    cout << "Number of horse numbers: " << count << endl;
}

bool CheckQueen(int** a, int n, int m, int k, int l, int x) {
    for(int i = 0; i < m; i++)
        if(x < a[k][i]) return false;
    for(int i = 0; i < n; i++) 
        if(x < a[i][l]) return false;
    
    int col = k - 1, row = l - 1;
    while(col >= 0 && row >= 0) {
        if(x < a[col][row]) return false;
        col--;
        row--;
    }
    col = k + 1, row = l + 1;
    while(col < n && row < m) {
        if(x < a[col][row]) return false;
        col++;
        row++;
    }
    col = k + 1, row = l + 1;
    while(col < n && row >= 0) {
        if(x < a[col][row]) return false;
        col++;
        row--;
    }
    col = k - 1, row = l + 1;
    while(col >= 0 && row < m) {
        if(x < a[col][row]) return false;
        col--;
        row++;
    }
    return true;
}

void Queen(int **a, int n, int m) {
    int count = 0;
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) 
            if(CheckQueen(a, n, m, i, j, a[i][j]))
                count++;
    cout << "Number of queen numbers: " << count << endl;    
}

bool CheckExtremalNumbers(int **a, int n, int m, int k, int l) {
    // Gioi han cot va dong xung quanh vi tri phan tu can xet
    int minI = k - 1, maxI = k + 1; 
    int minJ = l - 1, maxJ = l + 1; 
    if(minI < 0) minI = 0;
    if(minJ < 0) minJ = 0;
    if(maxI > n - 1) maxI = n - 1;
    if(maxJ > m - 1) maxJ = m - 1;

    // Xet vung xung quanh phan tu 
    int min = a[minI][minJ];
    int max = a[minI][minJ];

    // Xet lon nhat
    for(int i = minI; i <= maxI; i++) 
        for(int j = minJ; j <= maxJ; j++) 
            if(max < a[i][j]) 
                max = a[i][j];

    // Xet be nhat
    for(int i = minI; i <= maxI; i++) 
        for(int j = minJ; j <= maxJ; j++) 
            if(min > a[i][j]) 
                min = a[i][j];
    
    if(max == a[k][l])
        return true;
    if(min == a[k][l])
        return true;
    return false;
}

void ExtremalNumbers(int **a, int n, int m) {
    int count = 0;
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            if(CheckExtremalNumbers(a, n, m, i, j))
                count++;
    cout << "Number of extremal number: " << count << endl;
}

void DivideNumber(int a[], int n) {
    while(n > 0) {
        a[n % 10]++;
        n /= 10;
    }
}

void MostFrequentNumbers(int **a, int n, int m) {
    int count = 0;
    int number[10] = {0};
    for(int i = 0; i < n; i++) 
        for(int j = 0; j < m; j++) 
            DivideNumber(number, a[i][j]);
    int maxNumber = number[0];
    for(int i = 0; i < 10; i++) 
        if(maxNumber < number[i]) maxNumber = number[i];
    cout << "Numbers existing mostly in array: ";
    for(int i = 0; i < 10; i++) 
        if(maxNumber == number[i])
            cout << i << " ";
    cout << endl;
}

void GetArray(int **a, int n, int m, int arr[], int &c) {
    for(int i = 0; i < m - 1; i++) {
        arr[c] = a[0][i];
        c++; 
    }
    for(int i = 0; i < n - 1; i++) {
        arr[c] = a[i][m - 1];
        c++; 
    }
    for(int i = 1; i < m; i++) {
        arr[c] = a[n - 1][i];
        c++; 
    }
    for(int i = 1; i < n; i++) {
        arr[c] = a[i][0];
        c++; 
    }
}

void SortingArray(int **a, int n, int m) {
    int array[n * m], pos = 0, count = 0;
    GetArray(a, n, m, array, count);

    for(int i = 0; i < count - 1; i++) {
        for(int j = i; j < count; j++) {
            if(array[i] > array[j]) {
                int temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
            }
        }
    }

    for(int i = 0; i < m - 1; i++) {
        a[0][i] = array[pos];
        pos++;
    }
    for(int i = 0; i < n - 1; i++) {
        a[i][m - 1] = array[pos];
        pos++;
    }
    for(int i = m - 1; i >= 1; i--) {
        a[n - 1][i] = array[pos];
        pos++;
    }
    for(int i = n - 1; i >= 1; i--) {
        a[i][0] = array[pos];
        pos++;
    }
    cout << "Array after sorting: " << endl;
    PrintArray(a, n, m);
}

void Delete(int** a, int sodong) {
    for(int i = 0; i < sodong; i++)
        delete []a[i]; 
    delete []a;
}

int main() {
    int** a = NULL;
    int column, row;
    EnterColumAndRow(column, row);
    a = Allocate(column, row);
    
    EnterArray(a, column, row);
    cout << "******************************" << endl;
    cout << "Array: " << endl;
    PrintArray(a, column, row);
    cout << "******************************" << endl;
    TotalOfPositiveNumbers(a, column, row);
    cout << "******************************" << endl;
    NumberOfPrimeNumbers(a, column, row);
    cout << "******************************" << endl;
    MaxNumber(a, column, row);
    cout << "******************************" << endl;
    MinimunNegativeNumber(a, column, row);
    cout << "******************************" << endl;
    ColumnsContainingNegativeNumbers(a, column, row);
    cout << "******************************" << endl;
    ColumnsContainingFullEvenNumbers(a, column, row);
    cout << "******************************" << endl;
    Horse(a, column, row);
    cout << "******************************" << endl;
    Queen(a, column, row);
    cout << "******************************" << endl;
    ExtremalNumbers(a, column, row);
    cout << "******************************" << endl;
    MostFrequentNumbers(a, column, row);
    cout << "******************************" << endl;
    SortingArray(a, column, row);
    cout << "******************************" << endl;

    Delete(a, column);
    return 0;
}