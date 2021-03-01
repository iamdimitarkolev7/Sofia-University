#ifndef __STRING_CPP
#define __STRING_CPP

#include <iostream>
#include <cstring>
#include <cassert>
#include "string.h"

String::String()
{
    setLength(0);
    setStr(nullptr);
};

String::String(const char *_str)
{
    setLength(strlen(_str));
    setStr(_str);
}

String::String(const String &other)
{
    setLength(other.length);
    setStr(other.str);
}

String::~String()
{
    delete[] str;
}

void String::setStr(const char *_str)
{
    this->str = new char[strlen(_str)];
    strcpy(this->str, _str);
}

void String::setLength(int _length)
{
    this->length = _length;
}

String &String::operator=(const String &other)
{
    if (this != &other)
    {
        delete[] this->str;

        this->str = new char[other.length];

        setLength(other.length);
        setStr(other.str);
    }

    return *this;
}

String String::operator+=(const String &other)
{
    int newLength = this->length + other.length, index = 0;
    char *biggerBuffer = new char[newLength];

    for (int i = 0; i < this->length; i++)
    {
        biggerBuffer[i] = this->str[i];
    }

    for (int i = this->length; i < newLength; i++)
    {
        biggerBuffer[i] = other.str[index];
        index++;
    }

    delete[] this->str;

    this->str = biggerBuffer;
    this->length = newLength;

    return *this;
}

String String::operator+=(const char *_str)
{
    int newLength = this->length + strlen(_str), index = 0;
    char *biggerBuffer = new char[newLength];

    for (int i = 0; i < this->length; i++)
    {
        biggerBuffer[i] = this->str[i];
    }

    for (int i = this->length; i < newLength; i++)
    {
        biggerBuffer[i] = _str[index];
        index++;
    }

    delete[] this->str;

    this->str = biggerBuffer;
    this->length = newLength;

    return *this;
}

String String::operator+(const String &other)
{
    String res;

    int resLength = this->length + other.length, index = 0;
    char *resStr = new char[resLength];

    for (int i = 0; i < this->length; i++)
    {
        resStr[i] = this->str[i];
    }

    for (int i = this->length; i < resLength; i++)
    {
        resStr[i] = other.str[index];
        index++;
    }

    res.length = resLength;
    res.str = resStr;

    return res;
}

String String::operator+(const char *other)
{
    int resLength = this->length + strlen(other), index = 0;
    char *resStr = new char[resLength];

    for (int i = 0; i < this->length; i++)
    {
        resStr[i] = this->str[i];
    }

    for (int i = this->length; i < resLength; i++)
    {
        resStr[i] = other[index];
        index++;
    }

    String res(resStr);

    return res;
}

char String::operator[](const int index) const
{
    assert(index >= 0 && index <= this->length);
    return this->str[index];
}

bool String::operator!=(const String &other)
{
    return strcmp(this->str, other.str) != 0;
}

bool String::operator==(const String &other)
{
    return strcmp(this->str, other.str) == 0;
}

bool String::operator<(const String &other)
{
    return strcmp(this->str, other.str) < 0;
}

bool String::operator>(const String &other)
{
    return strcmp(this->str, other.str) > 0;
}

bool String::operator<=(const String &other)
{
    return strcmp(this->str, other.str) <= 0;
}

bool String::operator>=(const String &other)
{
    return strcmp(this->str, other.str) >= 0;
}

int String::getLength() const
{
    return this->length;
}

const char *String::getStr() const
{
    return this->str;
}

void String::output()
{
    for (int i = 0; i < this->length; i++)
    {
        std::cout << this->str[i];
    }

    std::cout << std::endl;
}

void String::add(const char *_str)
{
    int newLength = this->length + strlen(_str), index = 0;
    char *biggerBuffer = new (std::nothrow) char[newLength];

    if (!biggerBuffer)
    {
        std::cout << "Not enough memory!" << std::endl;
        delete[] biggerBuffer;
        return;
    }

    for (int i = 0; i < this->length; i++)
    {
        biggerBuffer[i] = this->str[i];
    }

    for (int i = this->length; i < newLength; i++)
    {
        biggerBuffer[i] = _str[index];
        index++;
    }

    delete[] this->str;

    this->str = biggerBuffer;
    this->length = newLength;
}

void String::removeLast()
{
    assert(this->length - 1 >= 0);

    char *smallerBuffer = new (std::nothrow) char[this->length - 1];

    if (!smallerBuffer)
    {
        std::cout << "Not enough memory!" << std::endl;
        smallerBuffer = nullptr;
        return;
    }

    for (int i = 0; i < this->length - 1; i++)
    {
        smallerBuffer[i] = this->str[i];
    }

    delete[] this->str;

    this->str = smallerBuffer;
    this->length = this->length - 1;
}

String String::slice(int start, int end) const
{
    assert(start >= 0 && end < this->length && start <= end);

    String res;

    int _length = end - start + 1, index = start, resultIndex = 0;
    char *result = new char[_length];

    while (index <= end)
    {
        result[resultIndex] = this->str[index];
        resultIndex++, index++;
    }

    result[_length] = '\0';

    res.length = _length;
    res.str = result;

    return res;
}

bool String::isMatching(char *strToSearch, const char *strToMatch)
{
    for (int i = 0; *(strToMatch + i); i++)
    {
        if (strToSearch[i] != strToMatch[i])
        {
            return false;
        }
    }
    return true;
}

void String::shiftLeft(char *strToShift, int shiftPosCount)
{
    int i = 0;

    for (; *(strToShift + i); i++)
    {
        strToShift[i - shiftPosCount] = strToShift[i];
    }

    strToShift[i - shiftPosCount] = strToShift[i];
}

void String::shiftRight(char *strToShift, int shiftPosCount)
{
    int textLen = strlen(strToShift);
    for (int i = textLen + 1; i >= 0; i--)
    {
        *(strToShift + i + shiftPosCount) = *(strToShift + i);
    }
}

void String::performStringReplacement(char *source, const char *newWord)
{
    for (int i = 0; *(newWord + i); i++)
    {
        *(source + i) = *(newWord + i);
    }
}

void String::replace(const char *oldWord, const char *newWord)
{
    int oldWordLen = strlen(oldWord);
    int newWordLen = strlen(newWord);

    for (int i = 0; *(this->str + i); i++)
    {
        if (isMatching(this->str + i, oldWord))
        {
            if (oldWordLen > newWordLen)
            {
                performStringReplacement(this->str + i, newWord);
                shiftLeft(this->str + i + oldWordLen, oldWordLen - newWordLen);
            }
            else if (oldWordLen < newWordLen)
            {
                shiftRight(this->str + i + oldWordLen, newWordLen - oldWordLen);
                performStringReplacement(this->str + i, newWord);
            }
            else
            {
                performStringReplacement(this->str + i, newWord);
            }
        }
    }
}

void String::toUpperCase()
{
    for (int i = 0; i < length; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
    }
}

void String::toLowerCase()
{
    for (int i = 0; i < length; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }
}

void String::trim()
{
    char *result;
    int counterL = 0, counterR = 0;

    if (str[0] = ' ')
    {
        int index = 1;
        counterL++;

        while (str[index] == ' ')
        {
            counterL++;
            index++;
        }
    }

    if (str[length - 1] = ' ')
    {
        int index = length - 2;
        counterR++;

        while (str[index] == ' ')
        {
            counterR++;
            index--;
        }
    }

    result = new char[length - counterL - counterR];
    int index = 0;

    for (int i = counterL; i < length - counterR; i++)
    {
        result[index] = str[i];
        index++;
    }

    delete[] str;

    str = result;
    length = length - counterL - counterR;
}

/* String *String::split(const char *delimiter)
{
    int delLength = strlen(delimiter);
    String *resultArray;
    int startIndex = 0, helpingIndex = 0, counter = 0;
    char *resultStr;

    for (int i = 0; *(this->str + i); i++)
    {
        if (isMatching(this->str + i, delimiter))
        {
            counter++;
        }
    }

    resultArray = new String[counter + 1];
    int resArrIndex = 0;

    for (int i = 0; *(this->str + i); i++)
    {
        if (isMatching(this->str + i, delimiter))
        {
            resultArray[resArrIndex].str = new char[i - startIndex];
            for (int index = startIndex; index < i; index++)
            {
                resultArray[resArrIndex].str[index] = str[helpingIndex];
                helpingIndex++;
            }

            resultArray[resArrIndex].length = strlen(resultStr);

            std::cout << resultArray[resArrIndex].getStr() << std::endl;
            resArrIndex++;

            startIndex = i + delLength;
            helpingIndex += delLength;
        }
    }

    return resultArray;
} */ 

#endif