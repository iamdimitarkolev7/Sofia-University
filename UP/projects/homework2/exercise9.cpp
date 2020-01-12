#include <iostream>
using namespace std;

void printCoordinates(int matrix[10][10], int rows, int cols)
{
    bool isBiggestInRow = true, isLowestInColumn = true;
    int helperI = 0, helperJ = 0, counter = 0;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            helperJ = j - 1;

            while (helperJ >= 0 && j != 0)
            {
                if (matrix[i][j] <= matrix[i][helperJ])
                {
                    isBiggestInRow = false;
                }

                helperJ--;
            }

            helperJ = j + 1;

            while (helperJ < cols && j != cols - 1)
            {
                if (matrix[i][j] <= matrix[i][helperJ])
                {
                    isBiggestInRow = false;
                }

                helperJ++;
            }

            helperI = i - 1;

            while (helperI >= 0 && i != 0)
            {
                if (matrix[i][j] >= matrix[helperI][j])
                {
                    isLowestInColumn = false;
                }

                helperI--;
            }

            helperI = i + 1;

            while (helperI < rows && i != rows - 1)
            {
                if (matrix[i][j] >= matrix[helperI][j])
                {
                    isLowestInColumn = false;
                }

                helperI++;
            }

            if (isBiggestInRow && isLowestInColumn)
            {
                cout << "(" << i << ", " << j << ")" << endl;
                counter++;
            }
            else
            {
                isLowestInColumn = true;
                isBiggestInRow = true;
            }
        }
    }

    if (counter == 0)
    {
        cout << "No such number! " << endl;
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

    printCoordinates(matrix, n, m);

    return 0;
}