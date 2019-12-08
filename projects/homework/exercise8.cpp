#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int transformNumber(char number[])
{
    int length = strlen(number);
    int createdNumber = 0, power = length - 1;

    for (int i = 0; i < length; i++)
    {
        int digit = (int)number[i] - '0';
        if (digit >= 0 && digit <= 9)
        {
            createdNumber += digit * pow(10, power);
            power--;
        }
    }

    return createdNumber;
}

int main()
{
    char text[1000], number[1000];
    cin.getline(text, 1000);
    fill_n(number, 1000, 0);

    int length = strlen(text), numbers[10000], charToNum, j = 0, p = 0;

    for (int i = 0; i < length; i++)
    {
        if (text[i] >= '0' && text[i] <= '9')
        {
            number[j] = text[i];

            if (text[i + 1] >= '0' && text[i + 1] <= '9')
            {
                j++;
                continue;
            }
            else
            {
                numbers[p] = transformNumber(number);
                p++;
                fill_n(number, 1000, 0);
                j = 0;
            }
        }
    }

    int max = numbers[0];

    for (int i = 1; i < p; i++)
    {
        if (max < numbers[i])
        {
            max = numbers[i];
        }
    }

    cout << max << endl;

    return 0;
}