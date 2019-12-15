/*
    Да се напише програма, която приема за вход цяло число n, последвано от елементите 
    на матрица с размерност nxn. Програмата да извежда елементите съответно от главния 
    и вторичния диагонал.
*/

#include <iostream>
using namespace std;

int main()
{
    int matrix[50][50], n;
    cout << "n = ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
            {
                cout << matrix[i][j] << " ";
            }
        }
    }

    cout << endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + j == n - 1)
            {
                cout << matrix[i][j] << " ";
            }
        }
    }

    cout << endl;

    return 0;
}