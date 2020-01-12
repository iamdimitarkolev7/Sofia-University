#include <iostream>
using namespace std;
int main()
{
    int n; 
    char star = '*';

    cout << "n = "; 
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        for (int i = 1; i <= n; i++)
        {
            cout << star;
        }

        cout << endl;
    }

    return 0;
}