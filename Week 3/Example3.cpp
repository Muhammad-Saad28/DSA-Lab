#include <iostream>
using namespace std;

void selectionSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        int maxIndex = i;
        for (int j = i + 1; j < n; j++) 
        {
            if (arr[j] > arr[maxIndex]) 
                maxIndex = j;    
        }
        int temp = arr[i];
        arr[i] = arr[maxIndex];
        arr[maxIndex] = temp;
    }
}

int main() 
{
    int arr[5] = {500, 320, 720, 610, 450};
    cout << "Before sorting: "<< endl;
    for (int i = 0; i < 5; i++) 
        cout << arr[i] << " ";
    selectionSort(arr, 5);
    cout << "After sorting: ";
    for (int i = 0; i < 5; i++) 
        cout << arr[i] << " ";
    cout << endl;
    cout << "Top performer sales: " << arr[0] << endl;
}
