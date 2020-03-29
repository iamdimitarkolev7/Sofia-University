#ifndef __STRING_CPP
#define __STRING_CPP

#include <iostream>
#include <cstring>
#include <cassert>
#include "string.h"

String::String()
{
    str = nullptr;
    length = 0;
};

String::String(const char *_str, int _length)
{
    setLength(_length);
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
    length = 0;
}

String &String::operator=(const String &other)
{
    if (this != &other)
    {
        delete[] this;

        this->length = other.length;
        for (int i = 0; i < this->length; i++)
        {
            this->str[i] = other.str[i];
        }
    }

    return *this;
}

int String::getLength() const
{
    return this->length;
}

const char *String::getStr() const
{
    return this->str;
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
        biggerBuffer = nullptr;
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

#endif