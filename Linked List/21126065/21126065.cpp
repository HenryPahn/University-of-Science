#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct LinkedList
{
    int data;
    LinkedList *pNext;
};

typedef struct LinkedList *Node;

Node CreateNode(int n)
{
    Node temp = new LinkedList;
    temp->data = n;
    temp->pNext = NULL;
    return temp;
}

Node AddFirst(Node pHead, int n)
{
    Node value = CreateNode(n);
    if (pHead == NULL)
        pHead = value;
    else
    {
        value->pNext = pHead;
        pHead = value;
    }
    return pHead;
}

Node AddLast(Node pHead, int n)
{
    Node value = CreateNode(n);
    if (pHead == NULL)
        pHead = value;
    else
    {
        Node temp = pHead;
        while (temp->pNext != NULL)
            temp = temp->pNext;
        temp->pNext = value;
    }
    return pHead;
}

Node AddAt(Node pHead, int n, int pos)
{
    Node value = CreateNode(n);
    if (pos == 0 || pHead == NULL || pHead->pNext == NULL)
        pHead = AddFirst(pHead, n);
    else
    {
        int count = 1;
        Node temp = pHead;
        while (temp->pNext != NULL && count != pos)
        {
            temp = temp->pNext;
            count++;
        }
        if (count != pos)
            pHead = AddLast(pHead, n);
        else
        {
            value->pNext = temp->pNext;
            ;
            temp->pNext = value;
        }
    }
    return pHead;
}

Node DelFirst(Node pHead)
{
    if (pHead == NULL)
        pHead = NULL;
    else
        pHead = pHead->pNext;
    return pHead;
}

Node DelLast(Node pHead)
{
    if (pHead == NULL)
        pHead = DelFirst(pHead);
    else
    {
        Node temp = pHead;
        while (temp->pNext->pNext != NULL)
            temp = temp->pNext;
        temp->pNext = temp->pNext->pNext;
    }
    return pHead;
}

Node DelAt(Node pHead, int pos)
{
    if (pos == 0 || pHead == NULL || pHead->pNext == NULL)
        pHead = DelFirst(pHead);
    else
    {
        int count = 1;
        Node temp = pHead;
        while (temp->pNext->pNext != NULL && count != pos)
        {
            temp = temp->pNext;
            count++;
        }
        if (count != pos)
            pHead = DelLast(pHead);
        else
            temp->pNext = temp->pNext->pNext;
    }
    return pHead;
}

Node PickFirst(Node &pHead)
{
    Node temp = pHead;
    if (pHead == NULL)
        temp = NULL;
    else
    {
        pHead = temp->pNext;
        temp->pNext = NULL;
    }
    return temp;
}

Node PickLast(Node &pHead)
{
    Node value = NULL;
    if (pHead == NULL)
        value = PickFirst(pHead);
    else
    {
        Node temp = pHead;
        while (temp->pNext->pNext != NULL)
            temp = temp->pNext;
        value = temp->pNext;
        temp->pNext = temp->pNext->pNext;
    }
    return value;
}

Node PickAt(Node &pHead, int pos)
{
    Node value = NULL;
    if (pos == 0 || pHead == NULL || pHead->pNext == NULL)
        value = PickFirst(pHead);
    else
    {
        int count = 1;
        Node temp = pHead;
        while (temp->pNext->pNext != NULL && count != pos)
        {
            temp = temp->pNext;
            count++;
        }
        if (count != pos)
            value = PickLast(pHead);
        else
        {
            value = temp->pNext;
            temp->pNext = temp->pNext->pNext;
            value->pNext = NULL;
        }
    }
    return value;
}

Node CheckList(Node pHead, int n)
{
    Node t = NULL;
    for (Node temp = pHead; temp != NULL; temp = temp->pNext)
    {
        if (temp->data == n)
        {
            t->data = temp->data;
            t = t->pNext;
        }
    }
    return t;
}

Node ConnectLists(Node a, Node b)
{
    Node t = a;
    while (t->pNext != NULL)
        t = t->pNext;
    for (Node temp = b; temp != NULL; temp = temp->pNext)
    {
        t->pNext = temp;
        t = t->pNext;
    }
    return a;
}

int CountList(Node pHead)
{
    int count = 0;
    for (Node temp = pHead; temp != NULL; temp = temp->pNext)
        count++;
    return count;
}

Node DelList(Node pHead)
{
    for (Node temp = pHead; temp != NULL; temp = temp->pNext)
        pHead = DelFirst(pHead);
    return pHead;
}

void OutPut(Node pHead)
{
    for (Node temp = pHead; temp != NULL; temp = temp->pNext)
        cout << temp->data << " ";
    cout << endl
         << endl;
}

int main()
{
    Node pHead = NULL;
    srand(time(NULL));
    int a[10], random, pos;
    for (int i = 0; i < 10; i++)
        a[i] = rand() % 100;

    cout << "Linked list" << endl;
    for (int i = 0; i < 10; i++)
        pHead = AddFirst(pHead, a[i]);
    OutPut(pHead);

    random = rand() % 100;
    cout << "Add the head: " << random << endl;
    pHead = AddFirst(pHead, random);
    OutPut(pHead);

    random = rand() % 100;
    cout << "Add the tail: " << random << endl;
    pHead = AddLast(pHead, random);
    OutPut(pHead);

    random = rand() % 100;
    pos = rand() % 9;
    cout << "Add to " << pos << ": " << random << endl;
    pHead = AddAt(pHead, random, pos);
    OutPut(pHead);

    cout << "Delete head " << endl;
    pHead = DelFirst(pHead);
    OutPut(pHead);

    cout << "Delete tail " << endl;
    pHead = DelLast(pHead);
    OutPut(pHead);

    pos = rand() % 7;
    cout << "Delete at " << pos << endl;
    pHead = DelAt(pHead, pos);
    OutPut(pHead);

    cout << "Pick head" << endl;
    Node temp = NULL;
    temp = PickFirst(pHead);
    OutPut(temp);
    OutPut(pHead);

    cout << "Pick tail" << endl;
    temp = NULL;
    temp = PickLast(pHead);
    OutPut(temp);
    OutPut(pHead);

    pos = rand() % 5;
    cout << "Pick at " << pos << endl;
    temp = NULL;
    temp = PickAt(pHead, pos);
    OutPut(temp);
    OutPut(pHead);

    Node Check;
    random = rand() % 100;
    Check = CheckList(pHead, random);
    cout << "Find " << random << " in the list " << endl
         << endl;
    if (pHead == NULL)
        OutPut(pHead);
    else
        cout << "Not Found";

    cout << "Connect 2 lists" << endl;
    int b[5];
    Node pHeadB = NULL;
    for (int i = 0; i < 5; i++)
        b[i] = rand() % 100;
    for (int i = 0; i < 5; i++)
        pHeadB = AddFirst(pHeadB, a[i]);
    OutPut(pHeadB);
    pHead = ConnectLists(pHead, pHeadB);
    OutPut(pHead);

    int count = 0;
    cout << "Length of linked list: ";
    count = CountList(pHead);
    cout << count << endl;
    OutPut(pHead);

    cout << "Delete linked list" << endl;
    pHead = DelList(pHead);
    if (pHead == NULL)
        cout << "Success";
    delete pHead;
    delete temp;
    delete pHeadB;
    return 0;
}