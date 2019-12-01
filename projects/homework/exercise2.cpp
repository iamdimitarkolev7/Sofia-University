#include <iostream>
using namespace std;
int main()
{
    int m, n, Pm[10000], Qn[10000], result[10000];

    cout << "m = ";
    cin >> m;
    for (int i = m; i >= 0; i--)
    {
        cin >> Pm[i];
    }

    cout << "n = ";
    cin >> n;

    for (int i = n; i >= 0; i--)
    {
        cin >> Qn[i];
    }

    for (int i = m; i >= 0; i--)
    {
        for (int j = n; j >= 0; j--)
        {
            int total = Pm[i] * Qn[j];
            result[i + j] += total;
        }
    }

    for (int i = m + n; i >= 0; i--)
    {
        cout << result[i] << "  ";
    }
    
    cout << endl;

    return 0;
}