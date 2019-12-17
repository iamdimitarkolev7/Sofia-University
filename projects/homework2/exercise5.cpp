//XYZ = 998
#include <iostream>
#include <cmath>
using namespace std;

long functionT(int n)
{
    if (n == 0)
    {
        return 8;
    }

    return 9 * functionT(floor(n / 2)) + 9 * functionT(n - 1);
}

//T(10) == 240828896

int main()
{
    int n;
    cout << "n = ";
    cin >> n;

    cout << functionT(n) << endl;

    return 0;
}