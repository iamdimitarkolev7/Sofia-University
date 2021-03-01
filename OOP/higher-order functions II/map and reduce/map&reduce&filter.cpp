#include <iostream>
#include <vector>
#include <functional>

template <typename T, typename G>
using opFn = G (*)(T);

template <typename T, typename G>
std::vector<G> map(const std::vector<T> &target, const opFn<T &, G> mapFunction)
{
    std::vector<G> result;

    for (T element : target)
    {
        result.push_back(mapFunction(element));
    }

    return result;
}

template <typename T>
std::vector<T> filter(const std::vector<T> &target, const std::function<bool(T)> &predicate)
{
    std::vector<T> result;

    for (T elem : target)
    {
        if (predicate(elem))
        {
            result.push_back(elem);
        }
    }
    return result;
}

template <typename T, typename G>
G reduce(const std::vector<T> &target, const std::function<G(T, G)> reducer, const G &initialValue)
{
    G result = initialValue;

    for (T elem : target)
    {
        result = reducer(elem, result);
    }

    return result;
}