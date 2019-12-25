#include <iostream>
#include <cmath>
using namespace std;

bool isMatrixDominant(int matrix[30][30], int n)
{
    int helperJ = 0, currentSum = 0;
    bool isTrue = true;
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            currentSum = 0;

            if (i == j)
            {   
                helperJ = j - 1;

                while (helperJ >= 0 && i != 0)
                {
                    currentSum += matrix[i][helperJ];
                    helperJ--;
                }

                helperJ = j + 1;

                while (helperJ < n && i != n - 1)
                {
                    currentSum += matrix[i][helperJ];
                    helperJ++;
                }

                if (currentSum > abs(matrix[i][j]))
                {
                    isTrue = false;
                }
            }
        }
    }

    return isTrue;
}

int main()
{
    int n, matrix[30][30];
    
    do
    {
        cout << "n = ";
        cin >> n;

        if (n < 3 || n > 23)
        {
            cout << "Invalid input! Please try again! " << endl;
        }
    } while (n < 3 || n > 23);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    if (isMatrixDominant(matrix, n))
    {
        cout << "true";
    }
    else
    {
        cout << "false";
    }
    
    return 0;
}