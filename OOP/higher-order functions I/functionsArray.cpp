#include <iostream>

using F = double (*) (double);

double pow2 (double x)
{
    return x * x;
}

double pow3 (double x)
{
    return x * x * x;
}

double pow4 (double x)
{
    return x * x * x * x;
}

double pow5 (double x)
{
    return x  * x * x * x * x;
}

double zero (double x)
{
    return 0 * x;
}

int main()
{
    double (*functions[]) (double) = {pow2, pow3, pow4, pow5, zero};

    double arr[] = {5, 4, 3, 2, 1};

    for (int i = 0; i < 5; i++)
    {
        std::cout << functions[i](arr[i]) << std::endl;
    }

    return 0;
}