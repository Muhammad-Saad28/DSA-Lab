#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};

class Stack 
{
private:
    Node* top;  // Pointer to the top node

public:
    Stack() 
    {
        top = nullptr;
    }

    ~Stack() 
    {
        clear();
    }

    void push(int value) 
    {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = top;  
        top = newNode;        
        cout << value << " pushed into stack." << endl;
    }

    void pop() 
    {
        if (isEmpty()) 
        {
            cout << "Stack Underflow! Nothing to pop." << endl;
            return;
        }
        cout << top->data << " popped from stack." << endl;
        Node* temp = top;
        top = top->next;
        delete temp;
    }

    void peek() 
    {
        if (isEmpty())
            cout << "Stack is empty." << endl;
        else
            cout << "Top element is: " << top->data << endl;
    }

    void display() 
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements (top to bottom): ";
        Node* current = top;
        while (current != nullptr) 
        {
            cout << current->data << " ";
            current = current->next;
        }
        cout << endl;
    }

    void reverseDisplay() 
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack elements (bottom to top): ";
        displayReverse(top);
        cout << endl;
    }

    void displayReverse(Node* node) 
    {
        if (node == nullptr)
            return;
        displayReverse(node->next);
        cout << node->data << " ";
    }

    void getBottom() 
    {
        if (isEmpty()) 
        {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* current = top;
        while (current->next != nullptr)
            current = current->next;
        cout << "Bottom element is: " << current->data << endl;
    }

    void clear() 
    {
        while (top != nullptr) 
        {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        cout << "Stack cleared!" << endl;
    }

    bool isEmpty() {
        return (top == nullptr);
    }

    int size() 
    {
        int count = 0;
        Node* current = top;
        while (current != nullptr) 
        {
            count++;
            current = current->next;
        }
        return count;
    }
};

// Main function
int main() 
{
    Stack s;

    int n;
    cout << "How many elements do you want to push? ";
    cin >> n;

    for (int i = 0; i < n; i++) 
    {
        int value;
        cout << "Enter element " << i + 1 << ": ";
        cin >> value;
        s.push(value);
    }

    cout << endl;
    s.display();
    s.peek();
    s.getBottom();
    cout << "Current size: " << s.size() << endl;

    cout << endl;
    s.pop();
    s.display();

    cout << endl;
    s.reverseDisplay();
    cout << endl;

    s.clear();
    s.display();
}
