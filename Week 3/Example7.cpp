#include <iostream>
using namespace std;

void countingSort(int arr[], int n, int maxVal) {
    int count[50] = {0}; // frequency array
    int output[50];      // sorted result

    // Step 1: Count frequency of each number
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    // Step 2: Convert count[] to cumulative sum
    for (int i = 1; i <= maxVal; i++) {
        count[i] = count[i] + count[i - 1];
    }

    // Step 3: Build output array (stable sort)
    for (int i = n - 1; i >= 0; i--) {
        int val = arr[i];
        output[count[val] - 1] = val;
        count[val]--;
    }

    // Step 4: Copy back to original array
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

int main() 
{
    int votes[9] = {1, 4, 2, 1, 3, 2, 4, 1};
    int maxCandidate = 5; 

    cout << "Votes before sorting: ";
    for (int i = 0; i < 8; i++) 
        cout << votes[i] << " ";
    cout << endl;

    countingSort(votes, 8, maxCandidate);

    cout << "Votes after Counting Sort: ";
    for (int i = 0; i < 8; i++) 
        cout << votes[i] << " ";
    cout << endl;

    int freq[6] = {0};
    for (int i = 0; i < 8; i++) 
    {
        freq[votes[i]]++;
    }

    cout << "\nElection Results (candidate : votes):\n";
    for (int i = 0; i <= maxCandidate; i++) 
    {
        cout << "Candidate " << i << " : " << freq[i] << endl;
    }
}
