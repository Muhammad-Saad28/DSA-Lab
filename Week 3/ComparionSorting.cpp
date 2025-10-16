#include<iostream>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void BubbleSort(int arr[], int n)
{
    for(int i = 0; i < n-1; i++)
    {
        for(int j = 0; j < n- i -1; j++) // n-i-1 because last i elements are already sorted
        {
            if(arr[j] > arr[j+1])
            {
                swap(arr[j], arr[j+1]);
            }
        }
    }
}

void insertionSort(int arr[], int n)
{
    for(int i =1; i <n; i++)
    {
        int curr = arr[i];
        int previous = i -1;
        while(previous >=0 && arr[previous] > curr)
        {
            arr[previous + 1] = arr[previous];
            previous--;
        }
    arr[previous + 1] = curr;
    }
}

void selectionSort(int arr[], int n)
{
    for(int i = 0; i <n-1; i++)
    {
        int min = i;
        for(int j = i+1; j < n; j++)
        {
            if( arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[min], arr[i]);
    }
}

int partition(int arr[], int st, int end)
{
    int index = st -1;
    int pivot = arr[end];

    for(int j =st; j <end; j++)
    {
        if(arr[j] <= pivot)
        {
            index++;
            swap(arr[index], arr[j]);
        }
    }
    index++;
    swap(arr[index], arr[end]);

    return index;
}

void QuickSort(int arr[], int st, int end)
{
    if(st < end)
    {
        int pivot = partition(arr, st, end);
        QuickSort(arr, st, pivot-1);
        QuickSort(arr, pivot+1, end);
    }
}

void Merge(int arr[], int st, int mid, int end)
{
    int temp[end +1];
    int i =st;
    int j = end;
    while(i <= mid && j <=end)
    {
        if(temp[i] <= temp[j])
        {
            temp[i] = arr[i];
            i++;
        }
        else
        {
            temp[j] = arr[j];
            j++;
        }
    }

    while(i <= mid)
    {
        temp[i] = arr[i];
        i++;
    }
    while(j <= end)
    {
        temp[j] = arr[j];
        j++;
    }
    for(int k = st; k <= end; k++)
    {
        arr[k] = temp[k];
    }
}

void MergeSort(int arr[], int st, int end)
{
    if(st >= end)
    {
        int mid = st = (st-end)/2;
        MergeSort(arr, st, mid);
        MergeSort(arr, mid+1, end);
        Merge(arr, st, mid, end);
    }
}

int main()
{
    int arr[5] = {1, 4, 5, 3, 2};
    cout << "Bubble Sort: ";
    BubbleSort(arr, 5);
    for(int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout << "Insertion Sort: ";
    insertionSort(arr, 5);
    for(int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout << "Selection Sort: ";
    selectionSort(arr, 5);
    for(int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout << "Quick Sort: ";
    QuickSort(arr, 0, 5-1);
    for(int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout << "Merge Sort: ";
    MergeSort(arr, 0, 5-1);
    for(int i = 0; i < 5; i++)
    {
        cout<<arr[i]<<" ";
    }
}