#include <iostream>
#include <cstring>
using namespace std;

void printReversed(char words[][50], int n)
{
    for (int i = n - 1; i >= 0; i--)
    {
        int length = strlen(words[i]);
        bool isTrue = true;

        for (int j = 0; j < length; j++)
        {
            if (words[i][j] < 'a' || words[i][j] > 'z')
            {
                isTrue = false;
            }
        }

        if (isTrue)
        {
            cout << words[i];
        }
    }
}

int main()
{
    char words[20][50];
    int n;
    cout << "n = ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> words[i];
    }

    printReversed(words, n);

    return 0;
}