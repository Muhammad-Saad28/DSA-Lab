#include <iostream>
using namespace std;

#define SIZE 5

class Stack 
{
    private:
        int arr[SIZE]; // Array to store stack elements
        int top;       // Index of the top element

    public:
        // Constructor
        Stack() {
            top = -1;
        }

    // Push operation
    void push(int value) 
    {
        if (top == SIZE - 1)
            cout << "Stack Overflow! Cannot push " << value << endl;
        else 
        {
            top++;
            arr[top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    // Pop operation
    void pop() 
    {
        if (top == -1)
            cout << "Stack Underflow! Nothing to pop." << endl;
        else 
        {
            cout << arr[top] << " popped from stack." << endl;
            top--;
        }
    }

    // Peek (top element)
    void peek() 
    {
        if (top == -1)
            cout << "Stack is empty." << endl;
        else
            cout << "Top element is: " << arr[top] << endl;
    }

    // Display stack (top to bottom)
    void display() 
    {
        if (top == -1)
            cout << "Stack is empty." << endl;
        else 
        {
            cout << "Stack elements (top to bottom): ";
            for (int i = top; i >= 0; i--)
                cout << arr[i] << " ";
            cout << endl;
        }
    }

    // Check if stack is empty
    bool isEmpty() {
        return (top == -1);
    }

    // Return stack size
    int size() {
        return top + 1;
    }

    // Display stack (bottom to top)
    void reverseDisplay() 
    {
        if (isEmpty())
            cout << "Stack is empty!" << endl;
        else 
        {
            cout << "Stack elements (bottom to top): ";
            for (int i = 0; i <= top; i++)
                cout << arr[i] << " ";
            cout << endl;
        }
    }

    void getBottom() 
    {
        if (isEmpty())
            cout << "Stack is empty!" << endl;
        else
            cout << "Bottom element is: " << arr[0] << endl;
    }

    void clear() 
    {
        top = -1;
        cout << "Stack cleared!" << endl;
    }
};

// Main function
int main() 
{
    Stack s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);
    s.push(60);

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
