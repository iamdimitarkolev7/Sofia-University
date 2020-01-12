#include <iostream>
using namespace std;

void turn_on(int p);
void turn_off(int p);

void turnOn(int n)
{
    if (n == 1)
    {
        cout << "+1" << endl;
        return;
    }
    else if (n == 2)
    {
        cout << "+1" << endl;
        cout << "+2" << endl;
        return;
    }
    else
    {
        turn_on(n - 1);
        cout << "+" << n << endl;
        turnOn(n - 2);
    }
}

int main()
{
    int n;

    cin >> n;

    turnOn(n);

    return 0;
}


void turn_on(int p)
{
    if (p == 1)
    {
        cout << "+1" << endl;
    }
    else
    {
        turn_on(p - 1);
        cout << "+" << p << endl;
        turn_off(p - 1);
    }
}

void turn_off(int p)
{
    if (p == 1)
    {
        cout << "-1" << endl;
    }
    else
    {
        turn_on(p - 1);
        cout << "-" << p << endl;
        turn_off(p - 1);
    }
}