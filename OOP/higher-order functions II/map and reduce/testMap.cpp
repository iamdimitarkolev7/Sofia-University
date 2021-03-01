#include <iostream>

template <typename T>
using opFn = T (*)(T);

template <typename T>
void map(T arr[], size_t size, opFn<T> func)
{
    for (int i = 0; i < size; i++)
    {
        arr[i] = func(arr[i]);
    }
}

template <typename T>
T addOne(T element)
{
    return element + 1;
}

template <typename T>
T multiplyByTwo(T element)
{
    return element * 2;
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

    output(arr, 5);
    map<int>(arr, 5, addOne);
    output(arr, 5);
    map<int>(arr, 5, multiplyByTwo);
    output(arr, 5);

    return 0;
}