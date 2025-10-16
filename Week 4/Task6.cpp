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
    if (!head) 
    {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next) temp = temp->next;
    temp->next = newNode;
}

void display(Node* head) 
{
    Node* temp = head;
    while (temp) 
    {
        cout << temp->data;
        if (temp->next) cout << " => ";
        temp = temp->next;
    }
    cout << endl;
}

void removeDuplicates(Node* head) 
{
    Node* curr = head;

    while (curr != nullptr) 
    {
        Node* runner = curr;

        while (runner->next != nullptr) 
        {
            if (runner->next->data == curr->data) 
            {
                Node* dup = runner->next;
                runner->next = runner->next->next;
                delete dup;
            } 
            else 
                runner = runner->next;
        }
        curr = curr->next;
    }
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

    removeDuplicates(head);

    cout << "\nList after removing duplicates:\n";
    display(head);
}
