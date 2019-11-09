#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "n = ";
    cin >> n;
    int number = 1, length = n, p = 0;
    int matrix[n][n];

    while (number <= n * n)
    {
        for (int i = p; i < length; i++)       //first row
        {
            matrix[p][i] = number++;
        }
        for (int i = p + 1; i < length; i++)   //last column
        {
            matrix[i][length - 1] = number++;
        }
        for (int i = length - 2; i >= p; i--)  //last row
        {
            matrix[length - 1][i] = number++;
        }

        for (int i = length - 2; i > p; i--)   //first column
        {
            matrix[i][p] = number++;
        }

        p++, length--;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << matrix[i][j] << "\t";
        }

        cout << endl;
    }

    return 0;
}