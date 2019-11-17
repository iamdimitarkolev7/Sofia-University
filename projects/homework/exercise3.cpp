#include <iostream>
using namespace std;
int main()
{
    int n, a, b;
    cout << "a = ";
    cin >> a;
    cout << "b = ";
    cin >> b;

    if (a >= b)
    {
        do
        {
            cout << "Invalid input! Please, try again, b should be greater than a" << endl;
            cout << "a = ";
            cin >> a;
            cout << "b = ";
            cin >> b;
        } while (a >= b);
    }

    cout << "n = ";
    cin >> n;

    if (n < 1 && n > 10)
    {
        do
        {
            cout << "Invalid input! Please, try again, n should be >= 1 and <= 9" << endl;
            cout << "n = ";
            cin >> n;
        } while (n < 1 && n > 10);
    }

    const int length = n;
    int arr[length];

    for (int i = 0; i < length; i++)
    {
        cout << "digit: ";
        cin >> arr[i];

        if (arr[i] < 0 && arr[i] > 10)
        {
            do
            {
                cout << "Invalid input! Please, insert a digit!" << endl;
                cout << "digit: ";
                cin >> arr[i];
            } while (arr[i] < 0 && arr[i] > 10);
        }
    }

    // TODO

    return 0;
}