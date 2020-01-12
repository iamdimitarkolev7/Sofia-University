/*
    Да се напише програма, която приема естествено число n и извежда естествените 
    числа до n , използвайки рекурсия. 
    Допълнение: да се изведат наобратно
*/

#include <iostream>
using namespace std;

void printReversed_n(int n)
{
    if (n < 0)
    {
        return;
    }

    cout << n << " ";
    printReversed_n(n - 1);
}

void print_n(int n)
{
    if (n < 0)
    {
        return;
    }

    print_n(n - 1);
    cout << n << " ";
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;

    print_n(n);
    cout << endl;
    printReversed_n(n);
}