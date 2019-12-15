/*
    Да се напише програма, която приема от стандартния вход естествени числа m и n, 
    последвани от елементите на матрица с размерност mxn и съставя и извежда нейната 
    транспонирана матрица.
*/

#include <iostream>
using namespace std;
int main()
{
    int m, n, matrix[50][50], matrixT[50][50];
    cout << "m = ";
    cin >> m;
    cout << "n = ";
    cin >> n;
 
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
 
    cout << endl;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[j][i] << "  ";
        }

        cout << endl;
    }
 
    return 0;
}