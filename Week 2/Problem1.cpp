#include <iostream>
using namespace std;

int SearchA(int Arr[], int n, int x, int indices[]) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (Arr[i] == x) {
            indices[count++] = i;
        }
    }
    return count;
}

int main() {
    int X[] = {22, 2, 1, 7, 11, 13, 5, 2, 9};
    int n = sizeof(X) / sizeof(X[0]);

    int x;
    cout << "Enter the number to search: ";
    cin >> x;

    int indices[100];  
    int count = SearchA(X, n, x, indices);

    if (count == 0) {
        cout << x << " not found in the array." << endl;
    } else {
        cout << "Indices of " << x << ": ";
        for (int i = 0; i < count; i++) {
            cout << indices[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
