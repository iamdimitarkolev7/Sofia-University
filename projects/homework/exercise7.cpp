#include <iostream>
using namespace std;
int main()
{
    int n, numbers[100000], x, counter = 0;

    do
    {
        cout << "n = ";
        cin >> n;
        if (n < 0)
        {
            cout << "Invalid input! Please try again!" << endl;
        }
    } while (n < 0);

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    cout << "x = ";
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (numbers[i] + numbers[j] == x)
            {
                counter++;
            }
        }
    }

    cout << counter / 2 << endl;

    return 0;
}