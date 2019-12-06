#include <iostream>
using namespace std;
int main()
{
    int n, numbers[100000], x, counter = 0;
    cout << "n = ";
    cin >> n;

    if (n < 0)
    {
        do 
        {   
            cout << "Invalid input! Please try again!" << endl;
            cout << "n = ";
            cin >> n;
        } while(n < 0);
    }

    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    cout << "x = ";
    cin >> x;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (numbers[i] + numbers[j] == x)
            {
                counter++;
            }

        }
    }

    cout << counter / 2 << endl; // I devide the counter by 2, because for example (1, 3) and (3, 1) is the same
    
    return 0;
}