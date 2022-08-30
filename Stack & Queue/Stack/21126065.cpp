#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;

struct LinkedList {
    int data;
    LinkedList *pNext;
};

typedef struct LinkedList *Node;

struct Stack {
    Node pTop;
};

Node CreateNode(int value) {
    Node temp = new LinkedList;
    temp->data = value;
    temp->pNext = NULL;
    return temp;
}

Stack Push(Stack list, int n) {
    Node value = CreateNode(n);
    if(list.pTop == NULL) 
        list.pTop = value;
    else {
        value->pNext = list.pTop;
        list.pTop = value;
    }
    return list;
}

int Pop (Stack &list) {
    Node temp = list.pTop;
    if(list.pTop != NULL) {
        list.pTop = temp->pNext;
        temp->pNext = NULL;
    }

    int n = temp->data;
    delete temp;
    return n;
}

void OutPut(Stack s) {
    for(Node temp = s.pTop; temp != NULL; temp = temp -> pNext) 
        cout << temp -> data << " ";
}

int main() {
    Stack list;
    list.pTop = NULL;
    srand(time(NULL));
    cout << "Linked list" << endl;
    
    for(int i = 0; i < 15; i++) {
        int random = rand() % 100;
        list = Push(list, random);
    }
    int var;
    var = Pop(list);

    OutPut(list);
    return 0;
} 

