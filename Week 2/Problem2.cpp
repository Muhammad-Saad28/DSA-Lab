#include <iostream>
using namespace std;

int Minimum(int Arr[], int start, int end) {
    int minIndex = start;
    for (int i = start + 1; i <= end; i++) {
        if (Arr[i] < Arr[minIndex]) {
            minIndex = i;
        }
    }
    return minIndex;
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int Arr[100];  
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> Arr[i];
    }

    int start, end;
    cout << "Enter starting index: ";
    cin >> start;
    cout << "Enter ending index: ";
    cin >> end;

    if (start < 0 || end >= n || start > end) {
        cout << "Invalid range!" << endl;
        return 0;
    }

    int minIdx = Minimum(Arr, start, end);

    cout << "Minimum element between index " << start
         << " and " << end << " is " << Arr[minIdx]
         << " at index " << minIdx << endl;

    return 0;
}
