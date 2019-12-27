#include <iostream>
#include <cstring>
using namespace std;

bool contains(char matrix[100][100], char *s)
{
    int length = strlen(s), p = 0;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            int helpingIndexJ = j;

            while (*(s + p) == matrix[i][helpingIndexJ])
            {
                p++;
                helpingIndexJ++;
                if (p == length)
                {
                    return true;
                }
            }

            p = 0;
            int helpingindexI = i;

            while (*(s + p) == matrix[helpingindexI][j])
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

void checkWordsInMatrix(char str[], char words[][100], char matrix[100][100])
{
    int p = 0, q = 0, counterOcc = 0;

    for (int i = 0; i < strlen(str); i++)
    {
        fill_n(words[p], 100, 0);

        while (str[i] >= 'A' && str[i] <= 'Z')
        {
            words[p][q] = str[i];
            q++;
            i++;
        }

        if (str[i] < 'A' || str[i] > 'Z')
        {
            q = 0;

            if (contains(matrix, words[p]))
            {
                counterOcc++;
            }

            p++;
        }
    }

    if (counterOcc == p)
    {
        cout << "All words are found." << endl;
    }
    else
    {
        if (p - counterOcc == 1)
        {
            cout << "There is 1 missing word" << endl;
        }
        else
        {
            cout << "There are " << p - counterOcc << " missing words." << endl;
        }
    }
}

int main()
{
    char str[255], words[100][100], matrix[100][100];
    int n, m;
    cin.getline(str, 255);
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }

    checkWordsInMatrix(str, words, matrix);

    return 0;
}