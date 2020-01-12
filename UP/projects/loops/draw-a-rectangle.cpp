#include <iostream> 
using namespace std;
int main()
{
    char star = '*', space = ' ';
    int n;

    cout << "n = ";
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cout << star;
    }

    cout << endl;

    for (int i = 1; i <= n; i++)
    {
        cout << star;

        for (int j = 1; j <= n - 2; j++)
        {
            cout << space;
        }

        cout << star << endl;
    }

    for (int i = 1; i <= n; i++)
    {
        cout << star;
    }

    cout << endl;
}