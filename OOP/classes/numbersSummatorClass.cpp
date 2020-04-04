#include <iostream>

template <typename T>
class NumbersSummator
{
    private:
    T currentSum;
    T *unique;
    int length;
    int counter;

    public:
    NumbersSummator() 
    {
        currentSum = 0;
        unique = new T[1];
        unique[0] = 0;
        length = 1;
        counter = 0;
    }

    NumbersSummator(T number)
    {
        currentSum = number;
        unique = new T[1];
        unique[0] = number;
        length = 1;
        counter = 0;
    }

    ~NumbersSummator()
    {
        delete[] unique;
    }

    T sum()
    {
        return currentSum;
    }

    void add(T _number)
    {
        bool isUnique = true;
        currentSum += _number;
        counter++;

        for (int i = 0; i < length; i++)
        {
           if (unique[i] == _number) 
           {
               isUnique = false;
           }
        }
        
        if (isUnique)
        {

            T *newUnique = new T[length + 1];

            for (int i = 0; i < length; i++)
            {
                newUnique[i] = unique[i];
            }

            newUnique[length] = _number;

            delete[] unique;

            unique = newUnique;
            length = length + 1;
        }
    }

    void sub(T _number)
    {
        add(_number);
        counter++;
    }

    int num()
    {
        return counter;
    }

    T average()
    {
        T sum = 0;

        for (int i = 0; i < length; i++)
        {
            sum += unique[i];
        }

        return sum / length;
    }
};

int main()
{
    NumbersSummator<int> seq1(10);

    seq1.add(10);
    seq1.add(5);
    seq1.sub(-15);

    std::cout << seq1.sum() << std::endl;
    std::cout << seq1.average() << std::endl;

    NumbersSummator<double> seq2;

    seq2.add(2.2);
    seq2.add(3.3);
    seq2.add(4.4);
    seq2.sub(-7.7);
    seq2.add(2.2);

    std::cout << seq2.sum() << std::endl;
    std::cout << seq2.average() << std::endl;
    std::cout << seq2.num() << std::endl;

    return 0;
}