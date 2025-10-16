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

Node* segregateEvenOdd(Node* head) 
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node* evenHead = nullptr;
    Node* evenTail = nullptr;
    Node* oddHead = nullptr;
    Node* oddTail = nullptr;

    Node* curr = head;

    while (curr != nullptr) 
    {
        if (curr->data % 2 == 0) 
        { // even node
            if (evenHead == nullptr) 
                evenHead = evenTail = curr;
            else 
            {
                evenTail->next = curr;
                evenTail = evenTail->next;
            }
        } 
        else 
        { // odd node
            if (oddHead == nullptr) 
                oddHead = oddTail = curr;
            else 
            {
                oddTail->next = curr;
                oddTail = oddTail->next;
            }
        }
        curr = curr->next;
    }

    if (evenHead == nullptr)
        return oddHead;
    if (oddHead == nullptr)
        return evenHead;

    evenTail->next = oddHead;
    oddTail->next = nullptr;
    return evenHead;
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

    head = segregateEvenOdd(head);

    cout << "\nSegregated list:\n";
    display(head);
}
