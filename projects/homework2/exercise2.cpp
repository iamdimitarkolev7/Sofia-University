#include <iostream>
#include <cstring>

using namespace std;

bool isMatching(const char *strToSearch, const char *strToMatch)
{
    for (int i = 0; *(strToMatch + i); i++)
    {
        if (strToSearch[i] != strToMatch[i])
        {
            return false;
        }
    }
    return true;
}

void shiftLeft(char *strToShift, int shiftPosCount)
{
    int i = 0;
    for (; *(strToShift + i); i++)
    {
        strToShift[i - shiftPosCount] = strToShift[i];
    }

    strToShift[i - shiftPosCount] = strToShift[i];
}

void shiftRight(char *strToShift, int shiftPosCount)
{
    int textLen = strlen(strToShift);
    for (int i = textLen + 1; i >= 0; i--)
    {
        *(strToShift + i + shiftPosCount) = *(strToShift + i);
    }
}

void performStringReplacement(char *destStr, const char *replaceWith)
{
    for (int i = 0; *(replaceWith + i); i++)
    {
        *(destStr + i) = *(replaceWith + i);
    }
}

void replace(char *originalStr, const char *searchFor, const char *replaceWith, int maxSize)
{
    int searchForLen = strlen(searchFor);
    int replaceWithLen = strlen(replaceWith);

    for (int i = 0; *(originalStr + i); i++)
    {
        if (isMatching(originalStr + i, searchFor))
        {

            if (searchForLen > replaceWithLen)
            {
                performStringReplacement(originalStr + i, replaceWith);
                shiftLeft(originalStr + i + searchForLen, searchForLen - replaceWithLen);
            }
            else if (searchForLen < replaceWithLen)
            {
                if (strlen(originalStr) + replaceWithLen - searchForLen <= maxSize)
                {
                    shiftRight(originalStr + i + searchForLen, replaceWithLen - searchForLen);
                    performStringReplacement(originalStr + i, replaceWith);
                }
            }
            else
            {
                performStringReplacement(originalStr + i, replaceWith);
            }
        }
    }
}

int main()
{
    int n;
    char mainWord[100][100], replacedWord[100][100], string[4096];
    cout << "n = ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin.ignore();
        cin.getline(mainWord[i], 4096);

        cin.ignore();
        cin.getline(replacedWord[i], 4096);
    }

    cin.ignore();
    cin.getline(string, 4096);

    return 0;
}