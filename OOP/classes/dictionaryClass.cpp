#include <iostream>
#include <cstring>
#include <cassert>

struct Word
{
    char word[100];
    char translation[500];
};

class Dictionary
{
private:
    Word *data;
    size_t length;
public:
    Dictionary() : data(nullptr), length(0) {}

    void input()
    {
        std::cout << "Insert length of dictionary: ";
        std::cin >> this->length;

        for (size_t i = 0; i < this->length; i++)
        {
            std::cin.getline(this->data[i].word, 100);
            std::cin.getline(this->data[i].translation, 500);
        }
    }

    void output()
    {
        std::cout << std::endl
                  << "This is the dictionary: " << std::endl;

        for (size_t i = 0; i < this->length; i++)
        {
            std::cout << (i + 1) << ". " << this->data[i].word << " means " << this->data[i].translation << std::endl;
        }

        std::cout << std::endl;
    }

    void addWord(const char *_word, const char *_translation)
    {
        assert(this->length + 1 <= 500);

        Word *bigger_buffer = new (std::nothrow) Word[this->length + 1];

        for (size_t i = 0; i < this->length; i++)
        {
            strcpy(bigger_buffer[i].word, this->data[i].word);
            strcpy(bigger_buffer[i].translation, this->data[i].translation);
        }

        strcpy(bigger_buffer[this->length].word, _word);
        strcpy(bigger_buffer[this->length].translation, _translation);

        this->length += 1;

        delete[] data;

        data = bigger_buffer;
    }

    void removeWord(const char *_word)
    {
        assert(this->length - 1 >= 0);

        Word *smaller_buffer = new (std::nothrow) Word[this->length - 1];

        size_t j = 0;

        for (size_t i = 0; i < this->length; i++)
        {
            if (strcmp(this->data[i].word, _word))
            {
                strcpy(smaller_buffer[j].word, this->data[i].word);
                strcpy(smaller_buffer[j].translation, this->data[i].translation);
                j++;
            }
        }

        delete[] data;

        data = smaller_buffer;
        this->length = j;
    }

    Dictionary operator+(const Dictionary &otherDictionary)
    {
        assert(this->length + otherDictionary.length <= 500);

        Dictionary result;

        for (size_t i = 0; i < this->length; i++)
        {
            result.addWord(this->data[i].word, this->data[i].translation);
        }

        for (size_t i = 0; i < otherDictionary.length; i++)
        {
            char *translationToAdd;

            for (size_t j = 0; j < this->length; j++)
            {
                strcpy(translationToAdd, otherDictionary.data[i].translation);

                if (!strcmp(this->data[j].word, otherDictionary.data[i].word))
                {
                    result.removeWord(this->data[j].word);
                    strcat(translationToAdd, "/");
                    strcat(translationToAdd, this->data[j].translation);
                    break;
                }
            }

            result.addWord(otherDictionary.data[i].word, translationToAdd);
        }

        return result;
    }
};

int main()
{
    Dictionary dict1;

    dict1.output();

    dict1.addWord("Monkey", "maimuna");
    dict1.addWord("Season", "sezon");
    dict1.addWord("Dance", "tanc");
    dict1.addWord("GOAT", "KOZA");
    dict1.output();
    //dict1.removeWord("Season");
    dict1.output();

    Dictionary dict2, dict3;

    dict2.addWord("GOAT", "Greatest of all time");
    dict2.addWord("BTW", "By the way");
    dict2.addWord("AMG", "mega burzoto neshto");
    dict2.output();

    dict3 = dict2 + dict1;

    dict3.output();

    return 0;
}