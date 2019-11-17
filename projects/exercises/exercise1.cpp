#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n, counter1 = 0, counter2 = 0;
    cout << "n = ";
    cin >> n;
    int i = n;

    while (i % 20 != 0)
    {
        i++;
        counter1++;
    }

    i = n;

    while (i % 20 != 0)
    {
        i--;
        counter2++;
    }
    
    if (counter1 <= counter2)
    {
        cout << counter1 << endl;
    }
    else 
    {
        cout << counter2 << endl;
    }

    return 0;
}