#include <iostream>
using namespace std;

void moveZeroes(int arr[], int n) 
{
    int pos = 0;

    for (int i = 0; i < n; i++) 
    {
        if (arr[i] != 0) 
        {
            arr[pos++] = arr[i];
        }
    }

    while (pos < n) 
    {
        arr[pos++] = 0;
    }
}

int main() 
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[100];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    moveZeroes(arr, n);

    cout << "Array after moving zeroes: ";
    for (int i = 0; i < n; i++) 
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
