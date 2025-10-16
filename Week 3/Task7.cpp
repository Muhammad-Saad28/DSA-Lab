#include <iostream>
using namespace std;

void bubbleSort(int arr[], int n) 
{
    for (int i = 0; i < n - 1; i++) 
    {
        for (int j = 0; j < n - i - 1; j++) 
        {
            if (arr[j] > arr[j + 1]) 
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printTime(int time) 
{
    int hh = time / 100;
    int mm = time % 100;
    if (hh < 10) cout << "0"; 
    cout << hh << ":";
    if (mm < 10) cout << "0"; 
    cout << mm;
}

int main() 
{
    int flights[6] = {930, 745, 1230, 1100, 1545, 600};
    
    bubbleSort(flights, 6);

    cout << "Sorted flight times: ";
    for (int i = 0; i < 6; i++) 
    {
        printTime(flights[i]);
        cout << " ";
    }
    cout << endl;

    cout << "Earliest flight: ";
    printTime(flights[0]);
    cout << endl;

    cout << "Latest flight: ";
    printTime(flights[6 - 1]);
}
