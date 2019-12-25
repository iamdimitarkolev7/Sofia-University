#include <iostream>
using namespace std;

void printMatrix(int matrix[10][10], int rows, int cols)
{
    int helper;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] > matrix[j][i] && j > i)
            {
                helper = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = helper;
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

int main()
{
    int n, m, matrix[10][10];

    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << endl;

    printMatrix(matrix, n, m);

    return 0;
}