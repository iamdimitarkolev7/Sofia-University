#include <iostream>
#include <cstring>
using namespace std;

void printSubstrings(char str[], int k, int startingIndex)
{
    int p = 0, length = 0;
    char formedWord[1000];

    for (int i = startingIndex; i < strlen(str); i++)
    {
        formedWord[p] = str[i];
        p++, length++;

        if (length % k == 0)
        {
            for (int j = 0; j < p; j++)
            {
                cout << formedWord[j];
            }

            cout << endl;
        }
    }

    startingIndex++;

    if (startingIndex <= strlen(str) - 1)
    {
        printSubstrings(str, k, startingIndex);
    }
}

int main()
{
    char str[1000];
    int k;

    cin.getline(str, 1000);
    cin >> k;

    printSubstrings(str, k, 0);

    return 0;
}