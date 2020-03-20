#include <iostream>
#include <cstring>
#include <cassert>

class Word
{
public:
    char word[20];

    void output ()
    {
        size_t length = strlen(this->word);

        for (int i = 0; i < length; i++)
        {
            std::cout << this->word[i];
        }

        std::cout << std::endl;
    }

    char operator [] (int i)
    {
        return this->word[i];
    }

    Word operator + (char a)
    {
        size_t length = strlen(this->word);
        assert(length + 1 < 20);
        word[length] = a;
        word[length + 1] = 0;
        return *this;
    }

    Word operator += (char a)
    {
        size_t length = strlen(this->word);
        assert(length + 1 <= 20);
        word[length] = a;
        word[length + 1] = 0;
        return *this;
    }

    bool operator < (Word other)
    {
        return strcmp(this->word, other.word) < 0;
    }

    bool operator > (Word other)
    {
        return strcmp(this->word, other.word) > 0;
    }

    bool operator == (Word other)
    {
        return strcmp(this->word, other.word) == 0;
    }
};

int main()
{
    Word word1, word2;
    std::cin.getline(word1.word, 20);

    word1 = word1 + 'a';
    word1 += 'r';
    word1.output();

    std::cin.getline(word2.word, 20);

    if (word1 < word2)
    {
        std::cout << "Word1 is smaller than word2" << std::endl;
    }

    if (word1 == word2)
    {
        std::cout << "Words are equal" << std::endl;
    }

    return 0;
}