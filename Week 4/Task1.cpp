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

int findMiddle(Node* head) 
{
    if (head == nullptr) 
    {
        cout << "List is empty." << endl;
        return -1;
    }

    Node* slow = head; 
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) 
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->data;
}

int main() 
{
    Node* head = nullptr;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    if (n <= 0) 
    {
        cout << "List is empty." << endl;
        return 0;
    }

    cout << "Enter " << n << " node values:\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> val;
        insertEnd(head, val);
    }

    cout << "Middle node: " << findMiddle(head) << endl;
}
