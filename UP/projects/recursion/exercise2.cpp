/*
    Да се напише програма, която приема на входа си естествено число n и 
    пресмята n! рекурсивно.
*/

#include <iostream>
using namespace std;

int factorial(int n)
{
    if (n < 1)
    {
        return 1;
    }

    return n * factorial(n - 1);
}

int main()
{
    int n;
    cout << "n = ";
    cin >> n;

    cout << factorial(n) << endl;
    
    return 0;
}