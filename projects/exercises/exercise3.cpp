#include <iostream>
using namespace std;
int main()
{
    const int max_value = 100000;
    int n;
    cout << "n = ";
    cin >> n;
    int arr[max_value], maxElement, maxElementIndex;
    bool isTrue;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    maxElement = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (maxElement < arr[i])
        {
            maxElement = arr[i];
            maxElementIndex = i;
        }
    }

    for (int i = 0; i < maxElementIndex; i++)
    {
        if (arr[i] > arr[i + 1])
        {
            isTrue = false;
            break;
        }
        else 
        {
            isTrue = true;
        }
    }

    for (int i = maxElementIndex; i < n; i++)
    {
        if (arr[i] < arr[i + 1])
        {
            isTrue = false;
            break;
        }
        else
        {
            isTrue = true;
        }
    }

    if (arr[0] == maxElement || arr[n - 1] == maxElement)
    {
        isTrue = false;
    }

    if (isTrue)
    {
        cout << "Yes: " << maxElementIndex << endl;
    }
    else
    {
        cout << "No." << endl;
    }
    

    return 0;

}