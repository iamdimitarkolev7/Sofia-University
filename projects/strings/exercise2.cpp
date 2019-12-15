/*
    Да се напише програма, която по два низа намира дължината 
    на най-дългия им общ префикс.
*/

#include <iostream>
#include <cstring>
using namespace std;

int maxPrefix(char str1[], char str2[])
{
    int length1 = strlen(str1), length2 = strlen(str2), maxLength = 0, currentLength = 0;

    for (int i = 0; i < length1; i++)
    {
        for (int j = 0; j < length2; j++)
        {
            while (str1[i] == str2[j] && str1[i] != '\0' && str2[j] != '\0')
            {
                currentLength++;
                i++;
                j++;
            }

            if (currentLength >= maxLength)
            {
                maxLength = currentLength;
            }

            currentLength = 0;
        }
    }

    return maxLength;
}

int main()
{
    char str1[255];
    char str2[255];
    cin.getline(str1, 255);
    cin.getline(str2, 255);

    cout << maxPrefix(str1, str2) << endl;

    return 0;
}