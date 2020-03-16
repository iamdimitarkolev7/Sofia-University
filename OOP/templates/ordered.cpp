#include <iostream>

template <typename T>
T *generateArray (size_t n) 
{
    T *arr = new (std::nothrow) T[n];

    if (!arr) 
    {
        return 0;
    }

    return arr;
}

// check whether a sequence of numbers is monotonic
template <typename T>
bool ordered (T *arr, size_t n) 
{
    if (n < 2) 
    {
        return true;
    }

    return arr[n - 2] <= arr [n - 1] && ordered (arr, n - 1);
}

template <typename T>
void input (T *arr, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
}

int main ()
{
    size_t n;

    std::cin >> n;

    double *arr = generateArray<double> (n);

    input<double> (arr, n);

    std::cout << ordered<double> (arr, n) << std::endl;

    delete[] arr;

    return 0;
}