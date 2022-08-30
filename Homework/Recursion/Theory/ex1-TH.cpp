#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct LinkedList {
    int data;
    LinkedList *pNext;
};

typedef struct LinkedList *Node;

Node CreateNode(int value) {
    Node temp = new LinkedList;
    temp->data = value;
    temp->pNext = NULL;
    return temp;
}

Node AddFirst(Node a, int n) {
    Node t = CreateNode(n);
    if(a == NULL) a = t;
    else {
        t->pNext = a;
        a = t;
    }
    return a;
}

Node Input(int n) {
    Node t = NULL;
    srand(time(NULL));
    for(int i = 0; i < n; i++) {
        int n = rand() % 100;
        t = AddFirst(t, n);
    }
    return t;
}

void Output(Node a) {
    if(a != NULL) {
        cout << a->data << " ";
        Output(a->pNext);
    }
} 


int main() {
    int n;
    cout << "Enter n: "; cin >> n; 
    Node list = NULL;

    list = Input(n);
    Output(list);
}