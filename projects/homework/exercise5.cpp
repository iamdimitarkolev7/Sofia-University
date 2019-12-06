#include <iostream>
using namespace std;
int main()
{
    int n, numbers[1000], currentVolume, totalVolume = 0, multiplier;
    cout << "n = ";
    cin >> n;

    while(!cin || n < 0 || n > 1000)
    {
        cout << "Wrong input! Please try again!" << endl;
        cin.clear();
        cin.ignore();
        cout << "n = ";
        cin >> n;
    }

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    int max = numbers[0];

    for (int i = 1; i < n; i++)
    {
        if (max < numbers[i])
        {
            max = numbers[i];
        }
    }

    int volume  = max * (n - 1);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            
        }
    }

    cout << totalVolume << endl;

    return 0;
}