#include <iostream>
using namespace std;

bool isTrue(long a, long b, long c)
{
    return a == b + c;
}

unsigned long countSums(long arr1[], long arr2[], long arr3[], int n)
{
    unsigned long counter = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (isTrue(arr1[i], arr2[j], arr3[k]) ||
                    isTrue(arr2[j], arr1[i], arr3[k]) ||
                    isTrue(arr3[k], arr2[j], arr1[i]))
                    counter++;
            }
        }
    }

    return counter;
}

int main()
{
    long arr1[20], arr2[20], arr3[20];
    int n;

    cout << "n = ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr3[i];
    }

    cout << countSums(arr1, arr2, arr3, n) << endl;

    return 0;
}