#include <iostream>

using F = double (*)(double);
using Comparator = bool (*)(double, double);

F *generateArray(size_t n)
{
    F* array = new F[n];

    if (!array)
    {
        std::cout << "Not enough memory!" << std::endl;
        return nullptr;
    }

    return array;
}

double f1(double x)
{
    return x * x - 4 * x - 12;
}

double f2(double x)
{
    return x * x + 5 * x - 3;
}

double f3(double x)
{
    return x * x - 25 * x  + 15;
}

double opWithArr(F *arr, double x, Comparator g)
{
    double el = __DBL_MIN__;

    for (int i = 0; i < 3; i++)
    {
        if (g(el, arr[i](x)))
        {
            el = arr[i](x);
        }
    }

    return el;
}

bool isBigger(double a, double b)
{
    return a < b;
}

bool isSmaller(double a, double b)
{
    return a > b;
}

int main()
{
    F *arr = generateArray(3);

    arr[0] = f1;
    arr[1] = f2;
    arr[2] = f3;

    double minResult = opWithArr(arr, 2, isSmaller);
    double maxResult = opWithArr(arr, 2, isBigger); //function maxarray;

    std::cout << "Min: " << minResult << std::endl;
    std::cout << "Max: " << maxResult << std::endl;

    delete[] arr;

    return 0;
}