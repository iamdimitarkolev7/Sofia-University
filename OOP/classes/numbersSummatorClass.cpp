#include <iostream>

template <class T>
class NumbersSummator
{
private:
    T number;
    size_t counter;
public:
    NumbersSummator()
    {
        this->number = 0;
        this->counter = 1;
    }

    NumbersSummator(T num)
    {
        this->number = num;
        this->counter = 1;
    }

    void add(T num)
    {
        this->number += num;
        this->counter++;
    }

    void sub(T num)
    {
        this->number -= num;
    }

    T sum()
    {   
        return this->number;
    }

    double average()
    {
        return this->number / this->counter;
    }
};

int main()
{
    NumbersSummator<int> seq1 (10);
    
    seq1.add(10);

    std::cout << seq1.sum() << std::endl;

    seq1.sub(5);

    std::cout << seq1.sum() << std::endl;

    seq1.add(5);
    seq1.add(15);

    std::cout << "Sum: " << seq1.sum() << std::endl;
    std::cout << "Average: " << seq1.average() << std::endl;

    NumbersSummator<double> seq2 (18.5);
    
    seq2.add(14.43);

    std::cout << seq2.sum() << std::endl;

    seq2.sub(8.93);

    std::cout << seq2.sum() << std::endl;

    seq2.add(1.1);
    seq2.add(2.22);

    std::cout << "Sum: " << seq2.sum() << std::endl;
    std::cout << "Average: " << seq2.average() << std::endl;

    return 0;
}