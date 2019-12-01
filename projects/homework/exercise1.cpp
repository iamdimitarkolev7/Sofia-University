#include <iostream>
using namespace std;
int main()
{
    int n, counter = 0, array[100000], index = 0, minimumSum = INT_MAX, m, q, p, currentSum = 0;

    cout << "Insert n: ";
    cin >> n;

    while(!cin || n < 1 || n > 1000000000)
    {
        cout << "Wrong input! Please try again!" << endl;
        cin.clear();
        cin.ignore();
        cout << "Insert n: ";
        cin >> n;
    }

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            counter++;
            array[index] = i;
            index++;
        }
    }

    // if the number is prime or the number is one then the numbers will be 1, 1 and n (and 1 if n == 1)
    // In this way the sum will be minimum 1 + 1 + n

    if (counter <= 2) 
    {
        cout << "m = " << 1 << endl;
        cout << "p = " << 1 << endl;
        cout << "q = " << n << endl;
    }
    else 
    {
        for (int i = 0; i < counter; i++)
        {
            for (int j = i + 1; j < counter; j++)
            {
                for (int k = j + 1; k < counter; k++)
                {
                    if (array[i] * array[j] * array[k] == n)
                    {
                        currentSum = array[i] + array[j] + array[k];

                        if (currentSum < minimumSum)
                        {
                            minimumSum = currentSum;
                            m = array[i];
                            q = array[j];
                            p = array[k];
                        }
                    }
                }
            }
        }

        cout << "m = " << m << endl;
        cout << "p = " << p << endl;
        cout << "q = " << q << endl;
    }

    return 0;
}

        