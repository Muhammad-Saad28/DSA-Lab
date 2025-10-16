#include <iostream>
using namespace std;

void insertionSort(int arr[], int n) 
{
    for (int i = 1; i < n; i++) 
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() 
{
    int arr[5] = {101, 125, 140, 160, 130};  
    cout << "Before insertion sort: ";
    for (int i = 0; i < 5; i++)  
        cout << arr[i] << " ";
    insertionSort(arr, 5);
    cout << "\nAfter insertion sort: ";
    for (int i = 0; i < 5; i++) 
        cout << arr[i] << " ";
}
