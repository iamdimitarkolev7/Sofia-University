#include <iostream>
using namespace std;

int numberOfOccurences(int matrix[][20], int n)
{
    int counter = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] + 1 == matrix[i][j + 1] && matrix[i][j + 1] + 1 == matrix[i][j + 2])
            {
                counter++;
            }
        }
    }

    return counter;
}

int main()
{
    int n, matrix[20][20];
    
    cout << "n = ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Number of occurences is: " << numberOfOccurences(matrix, n);

    return 0;
}