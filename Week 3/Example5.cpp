#include <iostream>
using namespace std;

void merge(int arr[], int l, int m, int r) 
{
    int n1 = m - l + 1, n2 = r - m;
    int L[50], R[50]; 

    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) 
    {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) 
{
    if (l < r) 
    {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int main() {
    int arr[7] = {38, 27, 43, 3, 9, 82, 10};
    cout << "Before sorting: ";
    for (int i = 0; i < 7; i++) 
        cout << arr[i] << " ";
    mergeSort(arr, 0, 7 - 1);
    cout << "\nMerit list: ";
    for (int i = 0; i < 7; i++) 
        cout << arr[i] << " ";

}
