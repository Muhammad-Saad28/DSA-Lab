#include <iostream>
using namespace std;

// Function to get the maximum value in array
int getMax(int arr[], int n) {
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

// Counting sort for one digit (exp = 1, 10, 100, ...)
void countSort(int arr[], int n, int exp) {
    int output[50]; // output array (max size = 50 for demo)
    int count[10] = {0};

    // Count digit occurrences
    for (int i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;

    // Convert count[] to cumulative
    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build output (stable: go from right to left)
    for (int i = n - 1; i >= 0; i--) {
        int digit = (arr[i] / exp) % 10;
        output[count[digit] - 1] = arr[i];
        count[digit]--;
    }

    // Copy back to arr[]
    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}

// Radix Sort main
void radixSort(int arr[], int n) {
    int m = getMax(arr, n);

    // Do counting sort for each digit place
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}

int main() 
{
    int arr[8] = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Before sorting: ";
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";
    cout << endl;

    radixSort(arr, 8);

    cout << "After Radix Sort: ";
    for (int i = 0; i < 8; i++)
        cout << arr[i] << " ";
}
