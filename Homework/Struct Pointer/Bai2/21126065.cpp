#include <iostream>
using namespace std; 

struct Polynomial {
    int n; 
    float *Coefficient;
};

void Input(Polynomial *temp) {
    cout << "Enter n: ";
    cin >> temp -> n; 

    while(temp -> n < 1) {
        cout << "Enter n again: ";
        cin >> temp -> n;
    }

    temp -> Coefficient = new float[temp -> n + 1];
    for(int i = 0; i <= temp -> n; i++) {
        cout << "Enter the " << i << " coefficient: ";
        cin >> temp -> Coefficient[i];
    }
}

Polynomial* Sum(Polynomial *a, Polynomial *b) {
    int max, min;
    if(a -> n > b -> n) max = a -> n;
    else max = b -> n;
    if(a -> n == max) min = b -> n;
    else min = a -> n;
    Polynomial* temp = new Polynomial;
    temp -> n = max;
    temp -> Coefficient = new float[temp -> n + 1];
    for(int i = 0; i <= min; i++) 
        temp -> Coefficient[i] = a -> Coefficient[i] + b -> Coefficient[i];
    if(a -> n > b -> n)
        for(int i = min + 1; i <= max; i++) 
            temp -> Coefficient[i] = a -> Coefficient[i];
    else
        for(int i = min + 1; i <= max; i++) 
            temp -> Coefficient[i] = b -> Coefficient[i];
    return temp;
}

void Output(Polynomial *temp) {
    if(temp -> n == 1) {
		cout << temp -> Coefficient[0] << " + ";
		cout << temp -> Coefficient[1] << " * x";
	}
	else {
		cout << temp -> Coefficient[0] << " + ";
		cout << temp -> Coefficient[1] << " * x + ";
		for(int i = 2; i < temp -> n; i++) {
			cout << temp -> Coefficient[i] << " * x ^ " << i << " + ";
		}
		cout << temp -> Coefficient[temp -> n] << " * x ^ " << temp -> n;
	}
}

void Delete(Polynomial *temp) {
    delete temp -> Coefficient;
    delete temp;
}

int main() {
    Polynomial *a = new Polynomial;
    Polynomial *b = new Polynomial;
    Polynomial *Result = new Polynomial;

    Input(a);

    Input(b);
    
    Result = Sum(a, b);
    cout << "Result: ";
    Output(Result);

    Delete(a);
    Delete(b);
    Delete(Result);
    return 0;
}