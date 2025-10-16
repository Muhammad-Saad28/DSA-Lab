#include <iostream>
using namespace std;

// Doubly Node structure
struct Node 
{
    int data;
    Node* next;
    Node* prev;

    Node(int value) 
    {
        data = value;
        next = nullptr;
        prev = nullptr;
    }
};

// Doubly Linked List class
class DoublyLinkList 
{
    private:
        Node* head;
        Node* tail;

    public:
        DoublyLinkList() 
    {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyLinkList() 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = tail = nullptr;
    }

    bool isEmpty() 
    {
        return head == nullptr;
    }

    // Insert at head
    void insertAtHead(int x) 
    {
        Node* newNode = new Node(x);
        if (head == nullptr) 
        {
            head = tail = newNode;
        } 
        else 
        {
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }

    // Insert at end
    void insertAtEnd(int x) 
    {
        Node* newNode = new Node(x);
        if (tail == nullptr) 
        {
            head = tail = newNode;
        } 
        else 
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Insert at index
    void insertNode(int index, int x) 
    {
        if (index == 0) 
        {
            insertAtHead(x);
            return;
        }

        Node* temp = head;
        int count = 0;
        while (temp != nullptr && count < index - 1) 
        {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr) 
        {
            cout << "Index out of range!";
            return;
        }

        Node* newNode = new Node(x);
        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr)
            temp->next->prev = newNode;
        else
            tail = newNode; // if inserting at end

        temp->next = newNode;
    }

    // Delete node by value
    bool deleteNode(int x) 
    {
        if (head == nullptr)
            return false;

        Node* temp = head;
        bool deleted = false;

        while (temp != nullptr) 
        {
            if (temp->data == x) 
            {
                if (temp == head)
                    head = temp->next;
                if (temp == tail)
                    tail = temp->prev;

                if (temp->prev)
                    temp->prev->next = temp->next;
                if (temp->next)
                    temp->next->prev = temp->prev;

                delete temp;
                deleted = true;
                break;
            }
            temp = temp->next;
        }
        return deleted;
    }

    // Delete from start
    bool deleteFromStart() 
    {
        if (head == nullptr)
            return false;
        Node* temp = head;
        head = head->next;
        if (head)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete temp;
        return true;
    }

    // Delete from end
    bool deleteFromEnd() 
    {
        if (tail == nullptr)
            return false;
        Node* temp = tail;
        tail = tail->prev;
        if (tail)
            tail->next = nullptr;
        else
            head = nullptr;
        delete temp;
        return true;
    }

    bool findNode(int x) 
    {
        Node* temp = head;
        while (temp != nullptr) 
        {
            if (temp->data == x)
                return true;
            temp = temp->next;
        }
        return false;
    }

    void displayList() 
    {
        Node* temp = head;
        cout << "List (forward): ";
        while (temp != nullptr) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() 
{
    DoublyLinkList dlist;
    
    cout << "Inserting at End: \n";
    dlist.insertAtEnd(10);
    dlist.insertAtEnd(30);

    dlist.displayList(); // 10 30
    
    cout << "Inserting at Head: \n";
    dlist.insertAtHead(5);

    dlist.displayList(); // 5 10 30
    
    cout << "Inserting at Index 2: \n";
    dlist.insertNode(2, 20); // Insert at index 2

    dlist.displayList(); // 5 10 20 30
    
    cout << "Deleting Node with value 10: \n";
    dlist.deleteNode(10);

    dlist.displayList(); // 5 20 30
    
    cout << "Deleting from Start: \n";
    dlist.deleteFromStart();

    dlist.displayList(); // 20 30
    
    cout << "Deleting from End: \n";
    dlist.deleteFromEnd();

    dlist.displayList(); // 20
    
    int n;
    cout << "Enter Number: ";
    cin >> n;
    cout << "Finding Node with value: \n" ;
    if(dlist.findNode(n))
        cout << "Found\n";
    else
        cout << "Not Found\n";
    
    return 0;
}
