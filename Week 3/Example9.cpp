#include <iostream>
#include <algorithm> // for sort()
using namespace std;

int combineArrays(int arr1[], int n1, int arr2[], int n2, int arr[]) 
{
    for (int i = 0; i < n1; i++)
        arr[i] = arr1[i];
    for (int i = 0; i < n2; i++)
        arr[n1 + i] = arr2[i];
    return n1 + n2; 
}

void findUnion(int arr[], int n) 
{
    sort(arr, arr + n);

    cout << "Union of arrays: ";
    cout << arr[0] << " "; 
    for (int i = 1; i < n; i++) 
    {
        if (arr[i] != arr[i - 1]) 
        {
            cout << arr[i] << " ";
        }
    }
    cout << endl;
}

int main() 
{    
    int n1, n2;

    cout << "Enter size of first array: ";
    cin >> n1;
    
    int arr1[n1];
    cout << "Enter elements of first array: ";
    for (int i = 0; i < n1; i++) 
        cin >> arr1[i];

    cout << "Enter size of second array: ";
    cin >> n2;
    
    int arr2[n2];
    cout << "Enter elements of second array: ";
    for (int i = 0; i < n2; i++) 
        cin >> arr2[i];

    int arr[100]; 
    int n = combineArrays(arr1, n1, arr2, n2, arr);
    findUnion(arr, n);

    return 0;
}
