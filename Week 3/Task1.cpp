#include <iostream>
using namespace std;

int main() 
{
    int n, low, high;
    cout << "Enter size of array: ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    cout << "Enter low and high of range: ";
    cin >> low >> high;

    int missing[100], m = 0; 

    for (int num = low; num <= high; num++) 
    {
        bool found = false;

        for (int i = 0; i < n; i++) 
        {
            if (arr[i] == num) 
            {
                found = true;
                break;
            }
        }

        if (found == false) 
        {    
            missing[m] = num;
            m++;
        }
    }

    cout << "Missing elements in range [" << low << ", " << high << "]: ";
    for (int i = 0; i < m; i++) 
    {
        cout << missing[i] << " ";
    }
}
