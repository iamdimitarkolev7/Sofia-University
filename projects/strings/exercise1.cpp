/* 
    Дадена е редица от символи. Да се напише програма, която 
    извежда отначало всички символи които са цифри, след това
    всички, които са малки латински букви и накрая всички останали
    символи, запазвайки реда им в редицата.
*/

#include <iostream>
#include <cstring>
using namespace std;

void printDigits(char str[])
{
    int length = strlen(str);

    for (int i = 0; i < length; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            cout << str[i];
        }
    }
}

void printLetters(char str[])
{
    int length = strlen(str);

    for (int i = 0; i < length; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            cout << str[i];
        }
    }
}

void printElements(char str[])
{
    int length = strlen(str);

    for (int i = 0; i < length; i++)
    {
        if ((str[i] < '0' || str[i] > '9') && (str[i] < 'a' || str[i] > 'z'))
        {
            cout << str[i];
        }
    }
}

int main()
{
    char str[255];
    cin.getline(str, 255);

    printDigits(str);
    printLetters(str);
    printElements(str);

    cout << endl;

    return 0;
}