#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int main()
{
    char text[1000], number[1000];
    bool isNextElementADigit = false;
    cin.getline(text, 1000);

    int length = strlen(text), numbers[10000], charToNum, j = 0;

    for (int i = 0; i < length; i++)
    {
        if (text[i] >= '0' && text[i] <= '9')
        {
            number[j] = text[i];
        }
    }

    cout << number << endl;

    return 0;
}