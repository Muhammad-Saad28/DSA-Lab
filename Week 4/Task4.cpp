#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node(int val) {
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

Node* rotateList(Node* head, int k) 
{
    if (head == nullptr || k == 0)
        return head;

    Node* temp = head;
    int length = 1;
    while (temp->next != nullptr) 
    {
        temp = temp->next;
        length++;
    }

    temp->next = head;

    if (k == 0) 
    {
        temp->next = nullptr;
        return head;
    }

    int stepsToNewHead = k;
    Node* prev = nullptr;
    Node* curr = head;

    for (int i = 0; i < stepsToNewHead; i++) 
    {
        prev = curr;
        curr = curr->next;
    }

    Node* newHead = curr;
    prev->next = nullptr;

    return newHead;
}

int main() 
{
    Node* head = nullptr;
    int n, val, k;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> val;
        insertEnd(head, val);
    }

    cout << "Enter number of nodes to rotate: ";
    cin >> k;

    cout << "\nOriginal list:\n";
    display(head);

    head = rotateList(head, k);
    cout << "\nRotated list:\n";
    display(head);
}