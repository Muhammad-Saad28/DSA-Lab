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

bool detectLoop(Node* head) 
{
    Node* slow = head;
    Node* fast = head;

    while (fast != nullptr && fast->next != nullptr) 
    {
        slow = slow->next;           
        fast = fast->next->next;     

        if (slow == fast)           
            return true;
    }
    return false;  
}

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

    // Creating a loop for testing

    // if (head != nullptr && head->next != nullptr) 
    // {
    //     Node* temp = head;
    //     while (temp->next != nullptr) {
    //         temp = temp->next;
    //     }
    //     // temp->next = head->next;  
    // }

    if (detectLoop(head))
        cout << "Loop detected in the linked list!" << endl;
    else
        cout << "No loop in the linked list." << endl;

    return 0;
}
