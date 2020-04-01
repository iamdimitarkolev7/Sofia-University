#include <iostream>
#include <cstring>
#include <cassert>

class Word
{
private:
    char word[20];

public:
    Word()
    {
        strcpy(this->word, "");
    }

    Word(const char *_word)
    {
        strcpy(this->word, _word);
    }

    const char *getWord() const
    {
        return this->word;
    }

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

    Word operator + (Word other)
    {
        size_t length1 = strlen(this->word);
        size_t length2 = strlen(other.word);
        assert(length1 + length2 <= 20);

        for (int i = 0; i < length2; i++)
        {
            this->word[length1 + i] = other.word[i];
            this->word[length1 + i + 1] = 0;
        }

        return *this;
    }

    bool operator < (Word other)
    {
        return strcmp(this->word, other.word) > 0;
    }

    bool operator > (Word other)
    {
        return strcmp(this->word, other.word) < 0;
    }

    bool operator == (Word other)
    {
        return strcmp(this->word, other.word) == 0;
    }
};

int main()
{
    Word word1;

    word1 = word1 + "Dimita";
    word1 += 'r';
    word1.output();

    Word word2("Mitko");
    Word word3("Dimitar");

    if (word1 < word2)
    {
        std::cout << word1.getWord() <<" is smaller than " << word2.getWord() << std::endl;
    }

    if (word1 > word2)
    {
        std::cout << word1.getWord() <<" is greater than " << word2.getWord() << std::endl;
    }

    if (word1 == word3)
    {
        std::cout << "Words are equal" << std::endl;
    }

    return 0;
}