#include <iostream>

template <typename T, typename G>
using opFn = G (*)(T); 

template <typename T>
struct S
{
    T a, b, c;
    T sum = 0;
};

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
void map(T *arr, int size, opFn<T&, G> fn)
{
    for (int i = 0; i < size; i++)
    {
        fn(arr[i]); //T = (S<T> -> T)
    }
}

template <typename T, typename G>
G sum(T element)
{
    element.sum = element.a + element.b + element.c;
    return element.sum;
}

template <typename T, typename G>
G addOne(T element)
{
    element.a += 1;
}

template <typename T, typename G>
G mySwap(T element)
{
    std::swap(element.a, element.b);
}

template <typename T, typename G>
G insert(T element)
{
    std::cin >> element.a;
    std::cin >> element.b;
    std::cin >> element.c;
    element.sum = 0;
}

template <typename T, typename G>
G output(T *arr, int size)
{
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i].a << " " << arr[i].b << " " << arr[i].c << " " << arr[i].sum << std::endl;
    }
}

int main()
{
    int size;
    std::cin >> size;

    S<int> *A = generateArray<S<int>>(size);
    
    map<S<int>, void>(A, size, insert);
    output<S<int>, void>(A, size);
    map<S<int>, int>(A, size, sum);
    //output<S<int>, void>(A, size);
    map<S<int>, void>(A, size, mySwap);
    //map<S<int>, void>(A, size, addOne);
    output<S<int>, void>(A, size);

    delete[] A;

    return 0;
}