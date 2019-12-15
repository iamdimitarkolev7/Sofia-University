/*
    Да се изведат елементите на масив, като се използва рекурсия.
*/

#include <iostream>
using namespace std;

void printArrayElementsReversed(int arr[], int n)
{
    if (n < 0)
    {
        return;
    }

    cout << arr[n] << " ";
    printArrayElementsReversed(arr, n - 1);
}

void printArrayElements(int arr[], int n)
{
    if (n < 0)
    {
        return;
    }

    printArrayElements(arr, n - 1);
    cout << arr[n] << " ";
}

int main()
{
    int arr[50], n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    printArrayElements(arr, n - 1);

    cout << endl;

    printArrayElementsReversed(arr, n - 1);

    return 0;
}