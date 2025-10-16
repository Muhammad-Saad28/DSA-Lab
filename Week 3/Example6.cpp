#include <iostream>
using namespace std;

// Insertion sort for individual buckets
void insertionSort(float arr[], int n) {
    for (int i = 1; i < n; i++) {
        float key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
// Bucket Sort implementation
void bucketSort(float arr[], int n) {
    // Step 1: Create buckets
    float bucket[10][10];   // 10 buckets, max 10 elements each
    int count[10] = {0};    // element count per bucket
    // Step 2: Put elements into buckets
    for (int i = 0; i < n; i++) {
        int bi = arr[i] * 10;  // bucket index
        bucket[bi][count[bi]++] = arr[i];
    }
    // Step 3: Sort each bucket using insertion sort
    for (int i = 0; i < 10; i++) {
        if (count[i] > 0) {
            insertionSort(bucket[i], count[i]);
        }
    }
    // Step 4: Concatenate buckets back into arr[]
    int k = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < count[i]; j++) {
            arr[k++] = bucket[i][j];
        }
    }
}

int main() {
    float arr[6] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94};
    cout << "Before sorting: ";
    for (int i = 0; i < 6; i++) 
        cout << arr[i] << " ";
    bucketSort(arr, 6);
    cout << "\nAfter Bucket Sort: ";
    for (int i = 0; i < 6; i++) 
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
