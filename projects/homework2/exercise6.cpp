#include <iostream>
using namespace std;

int maxZeroSequence(int element)
{

}

int zeroArea(int matrix[10][10], int n)
{
    int maxZeroRow = 0, maxZeroColumn = 0, currentZeroRow = 0, currentZeroColumn = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            
        }
    }
}

int main()
{
    int n, matrix[10][10];

    cout << "n = ";
    cin >> n;

    while (n < 0 || n > 10)
    {
        cout << "Invalid input! Please try again!" << endl;
        cout << "n = ";
        cin >> n;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> matrix[i][j];
        }
    }
}