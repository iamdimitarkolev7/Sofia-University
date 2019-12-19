#include <iostream>
#include <cstring>
using namespace std;

bool contains(char A[][10], const char *s)
{
    int length = strlen(s), p = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int helpingIndexJ = j; // helping index
            
            while(*(s + p) == A[i][helpingIndexJ])
            {
                p++;
                helpingIndexJ++;
                if (p == length)
                {
                    return true;
                }
            }

            p = 0;
            int helpingindexI = i; // helping index

            while(*(s + p) == A[helpingindexI][j])
            {
                p++;
                helpingindexI++;
                if (p == length)
                {
                    return true;
                }
            }

            p = 0;
        }
    }

    return false;
}

int main()
{
    char A[10][10], s[5];

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> A[i][j];
        }
    }

    cout << endl;

    cin >> s;

    cout << contains(A, s);

    return 0;
}