#include <iostream>
using namespace std;

//Node Structure
struct Node 
{
    int data;
    Node* next;
    Node(int value) 
    {
        data = value;
        next = nullptr;
    }
};

// Linked List class    
class LinkList 
{
    private:
        Node* head; // Pointer to the first node
    public:
    
    // Constructor
    LinkList() 
    {
        head = nullptr;
    }
    
    // Destructor - deletes all nodes
    ~LinkList() 
    {
        Node* current = head;
        while (current != nullptr) 
        {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
        head = nullptr;
    } 
    
    // Check if list is empty
    bool isEmpty() 
    {
        return head == nullptr;
    }


    // Insert at head
    Node* insertAtHead(int x) 
    {
        Node* newNode = new Node(x);
        newNode->next = head;
        head = newNode;
        return head;
    }
 
   // Insert at end

   Node* insertAtEnd(int x) 
   {
    Node* newNode = new Node(x);
    if (head == nullptr) {
        head = newNode;
        return head;
    }
    
    Node* temp = head;
    
    while (temp->next != nullptr) 
    {
        temp = temp->next;
    }
    temp->next = newNode;
    return head;
    }
    // Insert at a specific index (Position-based)
    Node* insertNode(int index, int x) 
    { 
        Node* newNode = new Node(x);
        if (index == 0) 
        { // Insert at head
            newNode->next = head;
            head = newNode;
            return head;
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
            cout << "Index out of range!\n";
            delete newNode;
            return nullptr;
        }

        newNode->next = temp->next;
        temp->next = newNode;
        return head;
    }

    // Delete all occurrences of x
    bool deleteNode(int x) 
    {
        if (head == nullptr)
            return false;
        bool deleted = false;
        // Delete from the start if needed
        while (head != nullptr && head->data == x) 
        {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            deleted = true;
        }
        
        // Delete from middle or end
        
        Node* temp = head;
        while (temp != nullptr && temp->next != nullptr) 
        {
            if (temp->next->data == x) 
            {
                Node* toDelete = temp->next;
            temp->next = temp->next->next;
            delete toDelete;
            deleted = true;
            } 
            else 
            {
            temp = temp->next;
            }
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
        delete temp;
        return true;
    }
    // Delete from end
    bool deleteFromEnd() 
    {
        if (head == nullptr)
            return false;
        if (head->next == nullptr) 
        {
            delete head;
            head = nullptr;
            return true;
        }
        Node* temp = head;
        while (temp->next->next != nullptr) 
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = nullptr;
        return true;
    }
    
    // Find a node with value x (Searching)
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

    // Display list
    void displayList() 
    {
        Node* temp = head;
        cout << "List: ";
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
    LinkList list;
    cout << "Inserting at End: \n";
    list.insertAtEnd(1);
    list.insertAtEnd(3);

    list.displayList(); // 1 3
    
    cout << "Inserting at Head: \n";
    list.insertAtHead(5);

    list.displayList(); // 5 1 3
    
    cout << "Inserting at Index 2: \n";
    list.insertNode(2, 2); // Insert at index 2

    list.displayList(); // 5 1 2 3
    
    cout << "Deleting Node with value 1: \n";
    list.deleteNode(1);

    list.displayList(); // 5 2 3
    
    cout << "Deleting from Start: \n";
    list.deleteFromStart();

    list.displayList(); // 2 3
    
    cout << "Deleting from End: \n";
    list.deleteFromEnd();

    list.displayList(); // 2
    
    cout << "Finding Node with value 2: ";
    if(list.findNode(2))
        cout << "Found\n";
    else
        cout << "Not Found\n";

    return 0;
}


