#include <iostream>
using namespace std;

int main() {
    int n, target;

    cout << "Enter number of elements in array: ";
    cin >> n;

    int arr[100]; 
    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) 
    {
        cin >> arr[i];
    }

    cout << "Enter target sum: ";
    cin >> target;

    cout << "Pairs with sum " << target << " are:\n";

    bool found = false;
    for (int i = 0; i < n; i++) 
    {
        for (int j = i + 1; j < n; j++) 
        { 
            if (arr[i] + arr[j] == target) 
            {
                cout << arr[i] << " + " << arr[j] << " = " << target << endl;
                found = true;
            }
        }
    }

    if (!found) {
        cout << "No pairs found." << endl;
    }

    return 0;
}
