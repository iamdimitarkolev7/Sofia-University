#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int transformNumber(char number[])
{
    int length = strlen(number);
    int createdNumber = 0, power = length - 1;

    //cout << "Current: " << endl;

    for (int i = 0; i < length; i++)
    {
        int digit = (int)number[i] - '0';
        cout << digit << " = " << (int)number[i] << " - " << (int)'0' << endl;

        createdNumber += digit * pow(10, power);
        power--;

        //cout << "digit: " << digit << " | createdNumber: " << createdNumber << endl;
    }

    cout << endl;

    return createdNumber;
}

int main()
{
    char text[1000], number[1000];
    bool isNextElementADigit = false;
    cin.getline(text, 1000);

    int length = strlen(text), numbers[10000], charToNum, j = 0, p = 0; // p and j are indexes 

    for (int i = 0; i < length; i++)
    {
        if (isdigit(text[i]))
        {
            cout << text[i] << "   " << isdigit(text[i]) << endl;
            number[j] = text[i];

            if (isdigit(text[i + 1]))
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