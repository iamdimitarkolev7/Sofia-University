#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cout << "n = "; 
    cin >> n;

    double a, b, minLeft, minBottom, maxTop, maxRight;
    cin >> a >> b;

    minLeft = maxRight = a;
    minBottom = maxTop = b;

    for (int i = 1; i < n; i++)
    {
        cin >> a >> b;

        if (a <= minLeft) minLeft = a;
        if (a >= maxRight) maxRight = a;
        if (b <= minBottom) minBottom = b;
        if (b <= maxTop) maxTop = b; 
    }

    double firstSide = abs(minLeft) + abs(maxRight);
    double secondSide = abs(minBottom) + abs(maxTop);

    if (firstSide < secondSide)
    {
        cout << secondSide * secondSide << endl;
    }
    else 
    {
        cout << firstSide * firstSide << endl;
    }

    return 0;
}