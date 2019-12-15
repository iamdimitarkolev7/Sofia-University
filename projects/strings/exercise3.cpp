/*
    Да се напише булева функция, която по дадени два низа s1 и s2
    проверява дали s2 е подниз на s1. Функцията да не използва вложени цикли.
*/

#include <iostream>
#include <cstring>
using namespace std;

bool isPrefix(char s1[], char s2[])
{
    int length1 = strlen(s1), length2 = strlen(s2), j = 0, counter = 0;

    if (length1 < length2)
    {
        return false;
    }

    for (int i = 0; i < length1; i++)
    {
        if (s1[i] == s2[j])
        {
            j++;
            counter++;

            if (counter == length2)
            {
                return true;
            }
        }
        else
        {
            j = 0;
            counter = 0;
        }
    }

    return false;
}

int main()
{
    char s1[255], s2[255];
    cin.getline(s1, 255);
    cin.getline(s2, 255);

    cout << isPrefix(s1, s2) << endl;
    return 0;
}