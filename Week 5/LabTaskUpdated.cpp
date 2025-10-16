#include <iostream>
using namespace std;

class Stack 
{
private:
    int* arr;       
    int top;        
    int capacity;   

public:
    Stack(int initialSize = 5) 
    {
        capacity = initialSize;
        arr = new int[capacity];
        top = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void resize() 
    {
        int newCapacity = capacity * 2;
        int* newArr = new int[newCapacity];

        for (int i = 0; i <= top; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr;
        arr = newArr;
        capacity = newCapacity;

        cout << "Stack resized to capacity " << capacity << endl;
    }

    void push(int value) 
    {
        if (top == capacity - 1) {
            cout << "Stack Overflow! Cannot push" << endl;
        }
        else{
            top++;
            arr[top] = value;
            cout << value << " pushed into stack." << endl;
        }

    }

    void pop() 
    {
        if (top == -1)
            cout << "Stack Underflow! Nothing to pop." << endl;
        else {
            cout << arr[top] << " popped from stack." << endl;
            top--;
        }
    }

    void peek() 
    {
        if (top == -1)
            cout << "Stack is empty." << endl;
        else
            cout << "Top element is: " << arr[top] << endl;
    }

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

    bool isEmpty() {
        return (top == -1);
    }

    int size() {
        return top + 1;
    }

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

    int getCapacity() {
        return capacity;
    }
};

int main() 
{
    int initialSize;
    cout << "Enter the initial size of the stack: ";
    cin >> initialSize;

    Stack s(initialSize);

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
    cout << "Current capacity: " << s.getCapacity() << endl;

    cout << endl;
    s.pop();
    s.display();

    cout << endl;
    s.reverseDisplay();
    cout << endl;

    s.clear();
    s.display();
}
