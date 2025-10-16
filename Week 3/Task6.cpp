#include <iostream>
using namespace std;

int partition(int roll[], int marks[], int low, int high) 
{
    int pivotMarks = marks[high];
    int pivotRoll  = roll[high];
    int i = low - 1;

    for (int j = low; j < high; j++) 
    {
        if (marks[j] > pivotMarks || (marks[j] == pivotMarks && roll[j] < pivotRoll)) 
        {
            i++;
            swap(marks[i], marks[j]);
            swap(roll[i], roll[j]);
        }
    }

    swap(marks[i + 1], marks[high]);
    swap(roll[i + 1], roll[high]);
    return i + 1;
}

void quickSort(int roll[], int marks[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(roll, marks, low, high);
        quickSort(roll, marks, low, pi - 1);
        quickSort(roll, marks, pi + 1, high);
    }
}

int main() 
{
    int roll[5]  = {1, 2, 3, 4, 5};
    int marks[5] = {90, 75, 90, 60, 75};

    quickSort(roll, marks, 0, 5 - 1);

    cout << "Sorted Students (RollNo, Marks):\n";
    for (int i = 0; i < 5; i++) 
        cout << "(" << roll[i] << ", " << marks[i] << ") ";
}
