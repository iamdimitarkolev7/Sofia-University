#include <iostream>
using namespace std;
int main()
{
    int m, n;
    cout << "m = "; cin >> m;
    cout << "n = "; cin >> n;

    int leftBorder, rightBorder;
    bool isTrue = false;

    if (m <= n)
    {
        leftBorder = m;
        rightBorder = n;
    }
    else 
    {
        leftBorder = n;
        rightBorder = m;
    }

    for (int i = leftBorder; i <= rightBorder; i++)
    {
        if (i % 10 == 0)
        {
            isTrue = true;
        }
    }

    cout << isTrue << endl;

    return 0;
}