#include <iostream>

using Func = bool (*)(double, double);

double find(double arr[], size_t size, Func f)
{
    double element = arr[0];

    for (int i = 1; i < size; i++)
    {
        if (f(arr[i], element))
        {
            element = arr[i];
        }
    }

    return element;
}

bool max(double current, double currentMax)
{
    return currentMax < current;
}

bool min(double current, double currentMin)
{
    return currentMin > current;
}

int main()
{
    double arr[5] = {5.7, 13.8, 16.555, 17.3, 0.01};

    std::cout << find(arr, 5, max) << std::endl;
    std::cout << find(arr, 5, min) << std::endl;

    return 0;
}