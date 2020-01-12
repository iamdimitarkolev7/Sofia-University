/*
    Да се напише програма, която приема на входа си естествено число n 
    и извежда сумата на числата от 1 до n.
    Допълнение: нека сега приема и число k и пресмята сумата на числата <= n през стъка k.
*/

#include <iostream>
using namespace std;

int recursiveSum(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return n + recursiveSum(n - 1);
}

int recursiveSum2(int n, int k, int current)
{
    if (current > n)
    {
        return 0;
    }

    return current + recursiveSum2(n, k, current + k);
}

int main()
{
    int n, k;
    cout << "n = ";
    cin >> n;

    cout << recursiveSum(n) << endl;

    cout << "k = ";
    cin >> k;

    cout << recursiveSum2(n, k, 0) << endl;

    return 0;
}