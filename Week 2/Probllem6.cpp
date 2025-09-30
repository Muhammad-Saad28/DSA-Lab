#include <iostream>
using namespace std;

int main() 
{
    int n;
    cout << "Enter size of square matrix (n x n): ";
    cin >> n;

    int mat[50][50];  
    cout << "Enter elements of the matrix:\n";
    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            cin >> mat[i][j];
        }
    }

    int upperSum = 0, lowerSum = 0;

    for (int i = 0; i < n; i++) 
    {
        for (int j = 0; j < n; j++) 
        {
            if (j >= i)  
                upperSum += mat[i][j];
            if (j <= i) 
                lowerSum += mat[i][j];
        }
    }

    cout << "Sum of upper triangular elements = " << upperSum << endl;
    cout << "Sum of lower triangular elements = " << lowerSum << endl;

    return 0;
}
