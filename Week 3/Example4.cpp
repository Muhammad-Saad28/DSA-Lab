#include <iostream>
using namespace std;

int partition(int arr[], int low, int high) 
{
    int pivot = arr[high]; 
    int i = low - 1;

    for (int j = low; j < high; j++) 
    {
        if (arr[j] <= pivot) 
        {  
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);  
    return i + 1;
}

void quickSort(int arr[], int low, int high) 
{
    if (low < high) 
    {
        int pi = partition(arr, low, high);  

        quickSort(arr, low, pi - 1);  // left
        quickSort(arr, pi + 1, high); // right
    }
}

int main() {
    int arr[6] = {250, 1000, 450, 700, 300, 900};
    cout << "Before sorting: ";
    for (int i = 0; i < 6; i++) 
        cout << arr[i] << " ";
    quickSort(arr, 0, 6 - 1);
    cout << "\nAfter Quick Sort: ";
    for (int i = 0; i < 6; i++) 
        cout << arr[i] << " ";
}
