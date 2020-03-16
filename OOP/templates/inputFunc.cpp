#include <iostream>

template <typename T>
T *generateArray(size_t n)
{
    T *arr = new (std::nothrow) T[n];

    if (!arr)
    {
        return 0;
    }

    return arr;
}

template <typename T>
void input (T *arr, size_t n) 
{
    for (size_t i = 0; i < n; i++)
    {
        std::cin >> arr[i];
    }
}

template <typename T>
void output (T *arr, size_t n) 
{
    for (size_t i = 0; i < n; i++)
    {
        std::cout << "arr[" << i << "]" << " = " << arr[i] << std::endl;
    }
    
}

int main()
{
    size_t n;

    std::cin >> n;

    double *arr = generateArray<double> (n);

    input<double> (arr, n);
    output<double> (arr, n);

    delete[] arr;

    return 0;
}