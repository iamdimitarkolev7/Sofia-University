#include <iostream>
using namespace std;

int numberOfVectors(int n, int k)
{
    if (n < k)
    {
        return 0;
    }

    int counter = n - k, result = 1;

    for (int i = 1; i <= n; i++)
    {
        result *= i;
    }

    for (int i = 1; i <= k; i++)
    {
        result /= i;
    }

    return result;
}

void printVectors(int n, int k)
{
    if (n < k)
    {
        return;
    }

    int numberOfZeos = n - k;

    cout << "(";

    for (int i = 0; i < n; i++)
    {

    }

    cout << ")" << endl;
}

int main()
{
    int n, k;

    cout << "n = ";
    cin >> n;
    cout << "k = ";
    cin >> k;

    cout << numberOfVectors(n, k) << endl;

    return 0;
}