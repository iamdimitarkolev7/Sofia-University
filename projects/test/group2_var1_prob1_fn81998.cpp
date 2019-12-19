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

bool permutationrec(int a[], int b[], int size)
{
    bool isNumInSeq = false;

    if (size == 0)
    {
        return true;
    }

    for (int i = size - 1; i >= 0; i--)
    {
        if (a[i] == b[size - 1])
        {
            isNumInSeq = true;
        }
    }

    return permutationrec(a, b, size - 1) && isNumInSeq;
}

bool permutation(int a[], int b[], int size)
{
    bool isPermut = true;

    for (int i = 0; i < size; i++)
    {
        if (a[i] != b[i])
        {
            isPermut = false;
        }
    }

    return isPermut;
}

int main()
{
    int a[100], b[100], size;

    do
    {
        cout << "size = ";
        cin >> size;

        if (size < 0)
        {
            cout << "Invalid input! Please try again." << endl;
        }
    } while (size < 0);

    for (int i = 0; i < size; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < size; i++)
    {
        cin >> b[i];
    }

    quickSort(a, 0, size); //sorting both of the arrays
    quickSort(b, 0, size);

    if (permutation(a, b, size))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    if (permutationrec(a, b, size))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}