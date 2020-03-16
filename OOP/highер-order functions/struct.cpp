#include <iostream>

template <typename T>
using Func = bool (*)(T, T);

struct S
{
    int a;
    int b;
    int c;
};

template <typename T>
void sort(S *structs, int n, Func<T> function)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (function(structs[i], structs[i + 1]))
            {
                std::swap(structs[i], structs[i + 1]);
            }
        }
    }
}

template <typename T>
bool isMonotonousA(T s1, T s2)
{
    return s1.a > s2.a;
}

template <typename T>
bool isMonotonousB(T s1, T s2)
{
    return s1.b > s2.b;
}

S *generateArray(size_t n)
{
    S *array = new S[n];

    if (!array)
    {
        std::cout << "Not enough memory!" << std::endl;
        return nullptr;
    }

    return array;
}

void input(S *structs, size_t n)
{
    for (int i = 0; i < n; ++i)
    {
        std::cin >> structs[i].a;
        std::cin >> structs[i].b;
        std::cin >> structs[i].c;
    }
}

void output(S *structs, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << structs[i].a << " " << structs[i].b << " " << structs[i].c << std::endl;
    }
}

int main()
{
    size_t n;

    std::cin >> n;

    S *structs = generateArray(n);

    input(structs, n);
    std::cout << std::endl;
    sort(structs, n, isMonotonousA<S>);
    output(structs, n);
    std::cout << std::endl;
    sort(structs, n, isMonotonousB<S>);
    output(structs, n);

    delete[] structs;

    return 0;
}