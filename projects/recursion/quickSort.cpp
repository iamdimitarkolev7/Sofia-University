#include <iostream>
using namespace std;

int partition(int arr[], int start, int end)
{
    int pivot = arr[end],  i = start;

    for(int j = start; j <= end; j++)
    {
        if(arr[j] < pivot)
        {
            swap(arr[i], arr[j]); 
            i++;                  
        }
    }
    swap(arr[i], arr[end]);
    return i;
}

void quickSort(int arr[], int start, int end)
{
    if(start < end)
    {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1); 
        quickSort(arr, p + 1, end);  
    }
}

int main() 
{
    int arr[50], n;
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, n-1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}