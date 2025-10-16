#include <iostream>
using namespace std;

int intersection(int a[], int n, int b[], int m, int result[]) 
{
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) 
    {
        if (a[i] == b[j]) 
        {
            if (k == 0 || result[k-1] != a[i]) 
                result[k++] = a[i];
            i++;
            j++;
        }
        else if (a[i] < b[j]) 
            i++;
        else 
            j++;
    }
    return k;
}

int main() 
{
    int n, m;

    cout << "Enter size of first array: ";
    cin >> n;
    int a[n];
    cout << "Enter elements of first array (sorted): ";
    for (int i = 0; i < n; i++) 
        cin >> a[i];

    cout << "Enter size of second array: ";
    cin >> m;
    int b[m];
    cout << "Enter elements of second array (sorted): ";
    for (int i = 0; i < m; i++) 
        cin >> b[i];

    int result[100];
    int size = intersection(a, n, b, m, result);

    cout << "Intersection: ";
    if (size == 0) 
        cout << "No common elements";
    else 
    {
        for (int i = 0; i < size; i++) 
            cout << result[i] << " ";
    }
}
