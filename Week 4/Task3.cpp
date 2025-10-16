#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
    Node(int val) 
    {
        data = val;
        next = nullptr;
    }
};

void insertEnd(Node*& head, int val) 
{
    Node* newNode = new Node(val);
    if (head == nullptr) 
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next != nullptr) 
        temp = temp->next;
    temp->next = newNode;
}

Node* reverseList(Node* head) 
{
    Node* prev = nullptr;
    Node* curr = head;
    Node* next = nullptr;

    while (curr != nullptr) 
    {
        next = curr->next;   
        curr->next = prev;   // reversing the link
        prev = curr;         
        curr = next;       
    }

    head = prev; // prev become new head
    return head;
}

void display(Node* head) 
{
    Node* temp = head;
    while (temp != nullptr) 
    {
        cout << temp->data;
        if (temp->next != nullptr)
            cout << " => ";
        temp = temp->next;
    }
    cout << endl;
}

int main() 
{
    Node* head = nullptr;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> val;
        insertEnd(head, val);
    }

    cout << "\nOriginal list:\n";
    display(head);

    head = reverseList(head);

    cout << "\nReversed list:\n";
    display(head);

    return 0;
}
