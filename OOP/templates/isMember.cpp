#include <iostream>

template <typename T>
void clearMatrix(T **matrix, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        delete[] matrix[i];
    }

    delete[] matrix;
}

template <typename T>
T **generateMatrix(size_t n)
{
    T **matrix = new (std::nothrow) T *[n];

    if (!matrix)
    {
        return nullptr;
    }

    for (size_t i = 0; i < n; i++)
    {
        matrix[i] = new (std::nothrow) T[n];

        if (!matrix[i])
        {
            clearMatrix<T>(matrix, n);
            return nullptr;
        }
    }

    return matrix;
}

template <typename T>
void input(T **matrix, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            std::cin >> matrix[i][j];
        }
    }
}

template <typename T>
bool isMember(T **matrix, size_t n, T element)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (matrix[i][j] == element)
            {
                return true;
            }
        }
    }

    return false;
}

int main()
{
    size_t n;

    std::cin >> n;

    double **matrix = generateMatrix<double>(n);

    input<double> (matrix, n);

    std::cout << isMember<double>(matrix, n, 17.5) << std::endl;

    clearMatrix<double>(matrix, n);

    return 0;
}