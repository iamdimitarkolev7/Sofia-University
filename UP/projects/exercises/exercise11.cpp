#include <iostream>
#include <cstring>
using namespace std;

char toUpperCase(char a)
{
    return a - 32;
}

char toLowerCase(char a)
{
    return a + 32;
}

void printReversed(char words[][50], int n)
{
    char wordHelper[50];

    for (int i = n - 1; i >= 0; i--)
    {
        int length = strlen(words[i]);

        for (int j = 0; j < length; j++)
        {
            if (words[i][j] >= 'a' && words[i][j] <= 'z')
            {
                wordHelper[j] = toUpperCase(words[i][j]);
            }

            if (words[i][j] >= 'A' && words[i][j] <= 'Z')
            {
                wordHelper[j] = toLowerCase(words[i][j]);
            }

            cout << wordHelper[j];
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
        cin.ignore();
        cin.getline(words[i], 50);
    }

    printReversed(words, n);

    return 0;
}