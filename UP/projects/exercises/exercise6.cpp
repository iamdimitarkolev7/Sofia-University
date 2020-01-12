#include <iostream>
using namespace std;

int timesOccured(char matrix[20][20], int n)
{
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        { 
            if (matrix[i][j] == 'd' && matrix[i][j + 1] == 'o' && matrix[i][j + 2] == 'g')
            {
                counter++;
            }
        }
    }

    return counter;
}

int main()
{
    char matrix[20][20];
    int n;

    cout << "n = ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << timesOccured(matrix, n) << endl;

    return 0;
}