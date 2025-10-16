#include<iostream>
using namespace std;

void countingSort(int arr[], int n, int maxVal)
{
    int count[50] = {0}; // frequency array (assume max 50 elements)
    int output[50]; // sorted result
    // Step 1: Count frequency of each number
    for (int i = 0; i < n; i++) 
    {
        count[arr[i]]++;
    }
    // Step 2: Convert count[] to cumulative sum
    for (int i = 1; i <= maxVal; i++) 
    {
        count[i] = count[i] + count[i - 1];
    }
    // Step 3: Build output array (go right to left for stability)
    for (int i = n - 1; i >= 0; i--) 
    {
        int val = arr[i];
        output[count[val] - 1] = val;
        count[val]--;
    }
    // Step 4: Copy back to original array
    for (int i = 0; i < n; i++) 
    {
        arr[i] = output[i];
    }
}

int main()
{
    int arr[9] = {1, 3, 2, 2, 5, 1, 4, 3, 2};
    int maxCandidate = 6; // max candidate number

    cout << "Votes before sorting: ";
    for (int i = 0; i < 9; i++) 
        cout << arr[i] << " ";  
    cout << endl;   
    countingSort(arr, 9, maxCandidate);
    cout << "Votes after Counting Sort: ";
    for (int i = 0; i < 9; i++)
        cout << arr[i] << " ";
    cout << endl;
    int freq[7] = {0}; 
    for (int i = 0; i < 9; i++)
    {
        freq[arr[i]]++;
    }
    cout << "\nElection Results (candidate : votes):\n";
    for (int i = 0; i <= maxCandidate; i++)
    {
        cout << "Candidate " << i << " : " << freq[i] << endl;
    }
    
    int winner = 0;
    for (int i = 1; i <= maxCandidate; i++)
    {
        if (freq[i] > freq[winner])
            winner = i;
    }
    cout << "\nWinner is Candidate " << winner << " with " << freq[winner] << " votes.\n";
}