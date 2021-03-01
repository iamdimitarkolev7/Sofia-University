#include <iostream>

template <typename ResultT, typename ElementT>
using combineFn = ResultT (*)(ResultT, ElementT);

template <typename ResultT, typename ElementT>
ResultT reduce(ElementT arr[], size_t size, combineFn<ResultT, ElementT> fn, ResultT nullValue)
{
    ResultT result = nullValue;

    for (int i = 0; i < size; i++)
    {
        result = fn(result, arr[i]);
    }

    return result;
}

template <typename T>
T sum(T element, T x)
{
    return element + x;
}

template <typename T>
T multiply(T element, T x)
{
    return element * x;
}

template <typename T>
void output(T arr[], size_t size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl;
}

int main()
{
    int arr[5] = {1, 2, 3, 4, 5};

    output<int>(arr, 5);

    std::cout << reduce<int, int>(arr, 5, sum, 0) << std::endl;
    std::cout << reduce<int, int>(arr, 5, multiply, 1) << std::endl;

    return 0;
}