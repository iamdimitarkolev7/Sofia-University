#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

int toDec(int number, int system)
{
    int helpingNumber = number, counter = 0;

    while (helpingNumber > 0)
    {
        helpingNumber /= 10;
        counter++;
    }

    int numberToDec = 0;

    for (int i = 0; i < counter; i++)
    {
        int digit = number % 10;
        numberToDec += digit * pow(system, i);
        number /= 10;
    }

    return numberToDec;
}

void transformDecimalNumbers(int number, int toSystem)
{
    int arr[1000];
    int index = 0;

    while (number != 0)
    {
        int digit = number % toSystem;
        arr[index] = digit;
        index++;
        number /= toSystem;
    }

    for (int i = index - 1; i >= 0; i--)
    {
        cout << arr[i];
    }

    cout << endl;
}

void transformBinaryNumbers(int number, int toSystem)
{
    int numberToDec = toDec(number, 2);

    if (toSystem == 8)
    {
        transformDecimalNumbers(numberToDec, 8);
    }
    else 
    {
        cout << numberToDec << endl;
    }
}

void transformOctalNumbers(int number, int toSystem)
{
    int numberToDec = toDec(number, 8);

    if (toSystem == 10)
    {
        cout << numberToDec << endl;
    }

    if (toSystem == 2)
    {
        transformDecimalNumbers(numberToDec, toSystem);
    }
}

int main()
{
    int firstSystem, transformSystem;
    int number;
    cin >> number;
    cin >> firstSystem;
    cin >> transformSystem;

    if (firstSystem == 10)
    {
        transformDecimalNumbers(number, transformSystem);
    }

    if (firstSystem == 2)
    {
        transformBinaryNumbers(number, transformSystem);
    }

    if (firstSystem == 8)
    {
        transformOctalNumbers(number, transformSystem);
    }

    return 0;
}