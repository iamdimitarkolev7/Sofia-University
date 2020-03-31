#include <iostream>
#include <cstring>
using namespace std;

bool isMatching(char *strToSearch, char *strToMatch)
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

void performStringReplacement(char *source, char *newWord)
{
    for (int i = 0; *(newWord + i); i++)
    {
        *(source + i) = *(newWord + i);
    }
}

void replace(char *source, char *oldWord, char *newWord)
{
    int oldWordLen = strlen(oldWord);
    int newWordLen = strlen(newWord);

    for (int i = 0; *(source + i); i++)
    {
        if (isMatching(source + i, oldWord))
        {
            if (oldWordLen > newWordLen)
            {
                performStringReplacement(source + i, newWord);
                shiftLeft(source + i + oldWordLen, oldWordLen - newWordLen);
            }
            else if (oldWordLen < newWordLen)
            {
                shiftRight(source + i + oldWordLen, newWordLen - oldWordLen);
                performStringReplacement(source + i, newWord);
            }
            else
            {
                performStringReplacement(source + i, newWord);
            }
        }
    }
}

void remove(char *source, char *word)
{
    for (int i = 0; *(source + i); i++)
    {
        if (isMatching(source + i, word))
        {
            shiftLeft(source + i + strlen(word), strlen(word));
        }
    }
}

int main()
{
    char str[4096], oldWord[100], newWord[100], word[100];

    cin.getline(str, 4096);
    cin.getline(oldWord, 100);
    cin.getline(newWord, 100);

    replace(str, oldWord, newWord);

    cout << str << endl;

    cin.getline(word, 100);

    remove(str, word);

    cout << str << endl;

    return 0;
}