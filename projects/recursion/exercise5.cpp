/*
    Да се напише програма, която приема число n и:
        1. извежда цифрите на числото използвайки рекурсия
        2. намира сумата на цифрите на числото
*/

#include <iostream>
using namespace std;

void printDigitsOfNum(int n)
{
    if (n <= 0)
    {
        return;
    }

    printDigitsOfNum(n / 10);
    
    cout << n % 10 << " ";
}

int sumDigitsOfNum(int n)
{
    if (n == 0)
    {
        return 0;
    }

    return (n % 10) + sumDigitsOfNum(n / 10);
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;

    printDigitsOfNum(n);
    cout << endl;
    cout << sumDigitsOfNum(n);

    return 0;
}