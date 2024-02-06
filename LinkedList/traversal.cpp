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

int lengthOfLL(Node *head)
{

    int cnt = 0;
    Node *temp = head;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
int main()
{
    vector<int> arr = {2, 5, 8, 7};
    // Node *y = new Node(arr[0]);
    // cout << y << '\n';       // returns the memory value
    // cout << y->data << '\n'; // returns the data stored at that memory point

    // delete y;
    // y = nullptr;
    Node *head = convert(arr);
    // cout<<head->data;
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << "Length: "<< lengthOfLL(head) << endl;
    return 0;
}