#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


void Input(int *a, int n) {
    srand(time(NULL));
    for(int i = 0; i < n; i++) 
        *(a + i) = rand() % 100;
}

void Output(int *a, int n) {
    cout << "Array: ";
    for(int i = 0; i < n; i++) 
        cout << *(a + i) << " ";    
    cout << endl << endl;
}