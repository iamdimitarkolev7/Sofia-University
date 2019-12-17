/*
    Напишете програма, която пресмята и изкарва, при подадена матрица NxМ, най-голямата 
    сума на 3x3 "платформа" и самата нея.
*/

#include <iostream>
using namespace std;

int findSum(int matrix[][100], int row, int col)
{
    int rowLimit = row + 3;
    int colLimit = col + 3;
    int sum = 0;

    for (int i = row; i < rowLimit; i++)
    {
        for (int j = col; j < colLimit; j++)
        {
            sum += matrix[i][j];
        }
    }    

    return sum;
}

void printElements(int matrix[][100], int row, int col)
{
    int rowLimit = row + 3;
    int colLimit = col + 3;

    for (int i = row; i < rowLimit; i++)
    {
        for (int j = col; j < colLimit; j++)
        {
            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }    
}

void print3x3Platform(int matrix[][100], int n, int m)
{
    int currentRow = 0, currentCol = 0;
    int currentMaxSum = findSum(matrix, 0, 0);

    for (int i = 0; i <= n - 3; i++)
    {
        for (int j = 0; j <= m - 3; j++)
        {
            int currentSum = findSum(matrix, i, j);

            if (currentSum > currentMaxSum)
            {
                currentMaxSum = currentSum;
                currentRow = i;
                currentCol = j;
            }
        }
    }

    cout << currentMaxSum << endl;
    printElements(matrix, currentRow, currentCol);
}

int main()
{
    int n, m, matrix[100][100];
    cout << "n = ";
    cin >> n;
    cout << "m = ";
    cin >> m;

    if (n > 100 || m > 100 || n < 3 || m < 3)
    {
        cout << "Invalid dimensions" << endl;
        return 0;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    print3x3Platform(matrix, n, m);

    return 0;
}