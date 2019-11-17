#include <iostream>
using namespace std;
int main()
{
    int n;
    cout << "n = ";
    cin >> n;

    if (n < 1 || n > 1000000000)
    {
        do 
        {
            cout << "Invalid input! Please try again!" << endl;
            cout << "n = ";
            cin >> n;
        } while (n < 1 || n > 1000000000);
    }

    int counter = 0;
    
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            counter++;
        }
    }

    const int length = counter;
    int arr[length], index = 0;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            arr[index] = i;
            index++;
        }
    }
    
    if (length <= 2) // if the number is prime or the number is one then the numbers will be 1, 1 and n (and 1 if n == 1)
    {
        cout << "m = " << arr[0] << endl;
        cout << "p = " << 1 << endl;
        cout << "q = " << 1 << endl;
    }
    else
    {
        int minimumSum = INT_MAX, m, q, p, currentSum = 0;

        for (int i = 0; i < length; i++)
        {   
            for (int j = i + 1; j < length; j++)
            {
                for (int k = j + 1; k < length; k++)
                {
                    if (arr[i] * arr[j] * arr[k] == n)
                    {
                        currentSum = arr[i] + arr[j] + arr[k];

                        if (currentSum < minimumSum)
                        {
                            minimumSum = currentSum;
                            m = arr[i];
                            q = arr[j];
                            p = arr[k];
                        }
                    }
                }
            }
        }

        cout << "m = " << m << endl;
        cout << "q = " << q << endl;
        cout << "p = " << p << endl;
    }
    
    return 0;
}