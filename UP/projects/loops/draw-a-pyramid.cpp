#include <iostream>
using namespace std;
int main()
{
    char star = '*', space = ' ';
    int n;

    cout << "n = ";
    cin >> n;

    int spaceCounter = n - 1, starCounter = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= spaceCounter; j++)
        {
            cout << space;
        }

        for (int j = 1; j <= starCounter; j++)
        {
            cout << star;
        }

        for (int j = 1; j <= spaceCounter; j++)
        {
            cout << space;
        }

        starCounter += 2;
        spaceCounter--;

        cout << endl;
    }

    return 0;
}