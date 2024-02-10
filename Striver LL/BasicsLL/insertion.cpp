#include <bits/stdc++.h>
using namespace std;

class Node
{
public:         // access modifier
    int data;   // the data value
    Node *next; // the pointer to the next value

    // constructor
    Node(int data1, Node *next1)
    {
        data = data1; // Initialize data with the provided value
        next = next1; // Initialize next with the provided
    }

    Node(int data1)
    {
        data = data1;   // Initialize data with the provided value
        next = nullptr; // Initialize next as null since it's the end of the list
    }
};

Node *convert(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node *insertFirst(Node *head, int val)
{
    return new Node(val, head);
}

Node *insertLast(Node *head, int val)
{
    if (head == NULL)
        return new Node(val);
    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val);
    temp->next = newNode;
    return head;
}

Node *insertPos(Node *head, int val, int k)
{
    if (head == NULL)
    {
        if (k == 1)
            return new Node(val);
        else
            return NULL;
    }
    if (k == 1)
    {
        return new Node(val, head);
    }
    int cnt = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        cnt++;
        if (cnt == k - 1)
        {
            Node *newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

Node *insertVal(Node *head, int val, int ele)
{
    if (head == NULL)
    {
        return NULL;
    }
    if (head->data == ele)
    {
        Node *newNode = new Node(val, head->next);
        head->next = newNode;
        return head;
    }
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == ele)
        {
            Node *newNode = new Node(val, temp->next);
            temp->next = newNode;
            break;
        }
        temp = temp->next;
    }
    return head;
}

void printList(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node *head = convert(arr);
    head = insertFirst(head, 100);
    head = insertLast(head, 101);
    head = insertPos(head, 102, 7);
    head = insertVal(head, 103, 7);
    printList(head);
    return 0;
}