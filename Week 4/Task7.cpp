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

// Check if value exists in list
bool exists(Node* head, int val) 
{
    Node* temp = head;
    while (temp) 
    {
        if (temp->data == val)
            return true;
        temp = temp->next;
    }
    return false;
}

Node* getUnion(Node* head1, Node* head2) 
{
    Node* unionHead = nullptr;

    for (Node* temp = head1; temp; temp = temp->next) // List1
        if (!exists(unionHead, temp->data))
            insertEnd(unionHead, temp->data);

    for (Node* temp = head2; temp; temp = temp->next) //List2
        if (!exists(unionHead, temp->data))
            insertEnd(unionHead, temp->data);

    return unionHead;
}

Node* getIntersection(Node* head1, Node* head2) 
{
    Node* intersectionHead = nullptr;
    for (Node* temp = head1; temp; temp = temp->next)
        if (exists(head2, temp->data) && !exists(intersectionHead, temp->data))
            insertEnd(intersectionHead, temp->data);
    return intersectionHead;
}

int main() 
{
    Node *head1 = nullptr, *head2 = nullptr;
    int n1, n2, val;

    cout << "Enter number of nodes in List1: ";
    cin >> n1;
    cout << "Enter " << n1 << " node values:\n";
    for (int i = 0; i < n1; i++) 
    { 
        cin >> val; 
        insertEnd(head1, val); 
    }

    cout << "Enter number of nodes in List2: ";
    cin >> n2;
    cout << "Enter " << n2 << " node values:\n";
    for (int i = 0; i < n2; i++) 
    { 
        cin >> val; 
        insertEnd(head2, val); 
    }

    cout << "\nList1: "; display(head1);
    cout << "List2: "; display(head2);

    Node* unionList = getUnion(head1, head2);
    Node* intersectionList = getIntersection(head1, head2);

    cout << "\nUnion: "; display(unionList);
    cout << "Intersection: "; display(intersectionList);
}
