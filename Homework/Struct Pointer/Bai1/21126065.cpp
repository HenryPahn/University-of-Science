
#include <iostream>
#include <numeric>
using namespace std;

struct Fraction {
  int *num;
  int *denom;   
};

void Input(Fraction *&temp) {
  temp = new Fraction;
  temp -> num = new int;
  temp -> denom = new int;
  cin >> temp -> num[0];
  cin >> temp -> denom[0];
}

Fraction * Sum ( Fraction * X, Fraction * Y) {
  Fraction *temp = new Fraction;
  temp -> num = new int; 
  temp -> denom = new int;
  *(temp -> num) = (*(X -> num)) * (*(Y -> denom)) + (*(Y -> num)) * (*(X -> denom));
  *(temp -> denom) = (*(X -> denom)) * (*(Y -> denom));
  return temp;
} 

void MakeSense(Fraction *&temp) {
  if(*(temp -> denom) < 0 && *(temp -> num) < 0) {
        *(temp -> denom) = - *(temp -> denom);
        *(temp -> num) = - *(temp -> num);
    }

    // Neu mau am thi tu duong
    if(*(temp -> denom) < 0) {
        *(temp -> denom) = - *(temp -> denom);
        *(temp -> num) = - *(temp -> num);
    }
}

void Reduce(Fraction *&temp) {
  int GCF;
    for(int i = 1; i <= *(temp -> denom); i++) 
        if(*(temp -> denom) % i == 0 && *(temp -> num) % i == 0) 
            GCF = i;
    
    *(temp -> denom) /= GCF;
    *(temp -> num) /= GCF;
}

void Output(Fraction *temp) {
  MakeSense(temp);
  Reduce(temp);
  cout << *(temp -> num) << "/" << *(temp -> denom) << endl;
}

void Free(Fraction *temp){
	delete temp;
}

int main() {
   Fraction *A, *B, *C;

   cout<< "Nhap phan so thu I: ";
   Input(A);

   cout<< "Nhap phan so thu II: ";
   Input(B);

   C = Sum(A, B);

   cout<< "Tong 2 phan so: ";
   Output(C);

   Free(A); Free(B); Free(C);
  return 0;
}