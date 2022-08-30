#include <iostream>
#include <fstream>
using namespace std;

struct Fraction {
    int num; 
    int den;
};

struct LinkedList {
    Fraction data; 
    LinkedList *pNext;
};

typedef struct LinkedList *Node;

Node CreateNode (Fraction value) {
    Node temp = new LinkedList;
    temp->data = value;
    temp->pNext = NULL;
    return temp;
}

bool CheckPrime(int n) {
    if(n < 2) return false; 
    else if(n == 2) return true;
    else 
        for(int i = 2; i < n; i++)
            if(n % i == 0) 
                return false;
    return true;
}

int PrimeN(int &i) {
    while(!CheckPrime(i))
        i++;
    i++;
    return i - 1;
}

Node AddLast(Node p, Fraction n) {
    Node v = CreateNode(n);
    if(p == NULL) p = v;
    else {
        Node temp = p;
        while(temp->pNext != NULL) 
            temp = temp->pNext;
        temp->pNext = v;
    }
    return p;
}

Node Request1(int n) {
    Node temp = NULL;
    int NT = 1;
    for(int i = 0; i < n; i++) {
        Fraction add;
        add.num = i;
        add.den = PrimeN(NT);
        temp = AddLast(temp, add);
    }
    return temp;
}

void Write(Node p) {
    ofstream f;
    f.open("LIST01.txt");
    Node temp = p;
    while(temp != NULL) {
        f << temp->data.num << "/" << temp->data.den << " ; ";
        temp = temp->pNext;
    }
    f.close();
}

Node Request2(Node p) {
    Node temp = NULL;
    Node i = p;
    while(i != NULL) {
        if(i->data.num % 2 != 0) 
            temp = AddLast(temp, i->data);
        i = i->pNext;
    }
    return temp;
} 

void Write2(Node p) {
    ofstream f; 
    f.open("LIST02.txt");
    Node i = p;
    while(i != NULL) {
        f << i->data.num << "/" << i->data.den << " ; "; 
        i = i->pNext;
    }
    f.close();
}

bool Check3(int n) {
    while(n > 0) {
        int temp = n % 10;
        if((temp % 10) == 1) return true;
        n /= 10;
    }
    return false;
}

bool CheckQ3(Fraction data) {
    if(Check3(data.num)) return true;
    if(Check3(data.den)) return true;
    return false;
}

Node Request3(Node p) {
    Node temp = NULL;
    Fraction add; 
    add.num = 2021;
    add.den = 2022;
    Node i = p;
    while(i != NULL) {
        temp = AddLast(temp, i->data);
        if(CheckQ3(i->data)) 
            temp = AddLast(temp, add);
        i = i->pNext;
    }
    return temp;
} 

void Write3(Node p) {
    ofstream f; 
    f.open("LIST03.txt");
    Node i = p;
    while(i != NULL) {
        f << i->data.num << "/" << i->data.den << " ; "; 
        i = i->pNext;
    }
    f.close();
}

int main() {
    Node pHead = NULL;
    cout << "Enter n: ";
    int n; cin >> n; 

    pHead = Request1(n);
    Write(pHead);

    pHead = Request2(pHead);
    Write2(pHead);

    pHead = Request3(pHead);
    Write3(pHead);

    delete pHead;
    return 0;
}