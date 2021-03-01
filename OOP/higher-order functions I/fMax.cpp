#include <iostream>

using F = double (*)(double);

double fMax(F f, F g, double x)
{
    double fX = f(x);
    double gX = g(x);

    return fX > gX ? fX : gX;
}

double f(double x)
{
    return x * x - 5 * x + 3;
}

double g(double x)
{
    return x * x + 3 * x - 12;
}

int main()
{
    double x;

    std::cin >> x;

    double result = fMax (f, g, x);

    std::cout << result << std::endl;

    return 0;
}