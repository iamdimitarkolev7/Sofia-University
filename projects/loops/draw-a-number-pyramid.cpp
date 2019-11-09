#include <iostream>
using namespace std;
int main()
{
    int n, number = 0, spaceCounter = 0;
    char space = ' ';
    cout << "n = ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= spaceCounter; j++)
        {
            cout << space;
        }

        for (int j = i; j <= n - number + 2; j++)
        {
            cout << j;
        }

        for (int j = 1; j <= spaceCounter; j++)
        {
            cout << space;
        }

        number++;
        spaceCounter += 1;
        cout << endl;
    }

    return 0;
}