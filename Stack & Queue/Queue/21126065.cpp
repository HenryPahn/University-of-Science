#include <iostream>
#include <cstdlib> 
#include <ctime> 
using namespace std;

struct LinkedList {
    int data;
    LinkedList *pNext;
};
typedef struct LinkedList *Node;

struct Queue {
    Node pHead, pTail;
};

Node CreateNode(int value) {
    Node temp = new LinkedList;
    temp->data = value;
    temp->pNext = NULL;
    return temp;
}

Queue Enqueue(Queue q, int n) {
    Node value = CreateNode(n);
    if(q.pHead == NULL) 
        q.pHead = q.pTail = value;
    else {
        q.pTail->pNext = value;
        q.pTail = value;
    }
    return q;
}

int Dequeue(Queue &q) {
    Node temp = q.pHead;
    
    if(q.pHead == q.pTail)
        q.pHead = q.pTail = NULL;
    else if(q.pHead != NULL) {
        q.pHead = temp->pNext;
        temp->pNext = NULL;
    }
    int data = temp->data;
    delete temp;
    return data;
}

void OutPut(Queue q) {
    for(Node temp = q.pHead; temp != NULL; temp = temp -> pNext) 
        cout << temp -> data << " ";
}

int main() {
    srand(time(NULL));
    Queue q;
    q.pHead = NULL;
    q.pTail = NULL;
    for(int i = 0; i < 10; i++) {
        int num = rand() % 100;
        q = Enqueue(q, num);
    }

    int var;
    var = Dequeue(q);
    OutPut(q);
    return 0;
}