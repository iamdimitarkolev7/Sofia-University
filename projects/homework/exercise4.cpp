#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, numbers[1000], currentVolume, maxVolume = INT_MIN, multiplier;

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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (numbers[i] <= numbers[j])
            {
                multiplier = numbers[i];
            }
            else
            {
                multiplier = numbers[j];
            }

            currentVolume = abs(i - j) * multiplier;

            if (currentVolume > maxVolume)
            {
                maxVolume = currentVolume;
            }
        }
    }

    cout << maxVolume * 1000 << endl;

    return 0;
}
