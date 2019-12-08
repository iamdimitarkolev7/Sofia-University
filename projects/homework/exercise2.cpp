#include <iostream>
using namespace std;
int main()
{
    int m, n, Pm[10000], Qn[10000], result[10000];

    cout << "m = ";
    cin >> m;
    for (int i = m; i >= 0; i--)
    {
        do
        {
            cin >> Pm[i];
            if (Pm[i] < -1000 || Pm[i] > 1000)
            {
                cout << "Invalid input! Please try again!" << endl;
                cin >> Pm[i];
            }
        } while (Pm[i] < -1000 || Pm[i] > 1000);
    }

    cout << "n = ";
    cin >> n;

    for (int i = n; i >= 0; i--)
    {
         do
        {
            cin >> Qn[i];
            if (Qn[i] < -1000 || Qn[i] > 1000)
            {
                cout << "Invalid input! Please try again!" << endl;
                cin >> Qn[i];
            }
        } while (Qn[i] < -1000 || Qn[i] > 1000);
    }

    for (int i = m; i >= 0; i--)
    {
        for (int j = n; j >= 0; j--)
        {
            result[i + j] += Pm[i] * Qn[j];
        }
    }

    for (int i = m + n; i >= 0; i--)
    {
        cout << result[i] << "  ";
    }
    
    cout << endl;

    return 0;
}