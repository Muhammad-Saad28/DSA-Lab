#include <iostream>
using namespace std;

int main() 
{    
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    if (n < 2) 
    {
        cout << "Need at least two numbers." << endl;
        return 0;
    }

    int arr[100];
    cout << "Enter " << n << " numbers: ";
    for (int i = 0; i < n; i++) 
        cin >> arr[i];

    int max1 = arr[0], max2 = arr[0];

    for (int i = 1; i < n; i++) 
    {
        if (arr[i] > max1) 
        {
            max2 = max1;
            max1 = arr[i];
        } 
        else if (arr[i] > max2 && arr[i] != max1) 
        {
            max2 = arr[i];
        }
    }

    if (max1 == max2)
        cout << "No second-largest element." << endl;
    else
        cout << "Second-largest: " << max2 << endl;

    return 0;
}
