#include <iostream>

template <typename T, typename G>
using opFn = G (*)(T);

template <typename T>
T *generateArray(int size)
{
    T *arr = new (std::nothrow) T[size];

    if (!arr)
    {
        std::cout << "Not enough memory!" << std::endl;
        return nullptr;
    }

    return arr;
}

template <typename T, typename G>
void map(T *arr, int size, opFn<T&, G> func)
{
    for (int i = 0; i < size; i++)
    {
        func(arr[i]);
    }
}

template <typename T, typename G>
G insert(T el)
{
    std::cin >> el;
}

template <typename T, typename G>
G print(T el) //int -> void
{
    std::cout << el << " ";
}

int main()
{
    int size;

    std::cin >> size;

    int *arr = generateArray<int>(size);

    map<int, void>(arr, size, insert);
    map<int, void>(arr, size, print);

    delete[] arr;

    return 0;
}