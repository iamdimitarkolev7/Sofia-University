#include <iostream>
using namespace std;
int main()
{
    int n, numbers[1000], totalVolume = 0, current, next, currentVolume = 0;
    do
    {
        cout << "n = ";
        cin >> n;
        if (n < 0 || n > 1000)
        {
            cout << "Invalid input! Please try again!" << endl;
        }

    } while (n < 0 || n > 1000);

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        current = numbers[i];
        next = numbers[i + 1];

        if (current <= next)
        {
            currentVolume = current;
        }
        else
        {
            int firstIndex, secondIndex;
            for (int j = i; j < n - 1; j++)
            {

            }
        }

        totalVolume += currentVolume;
    }

    cout << totalVolume << endl;

    return 0;
}