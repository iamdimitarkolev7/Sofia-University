/*
    Header file
    Списък със заглавия на операцийте, които класът подържа
    Всичко за класа, което трябва да знаем
*/

#ifndef __STRING_H
#define __STRING_H   

#include <iostream>
#include <cstring>
#include <cassert>

class String
{
    private:
    char *str;
    int length;

    public:
    String();
    String(const char* _str, int _length);
    String(const String& other);
    ~String();
    String& operator=(const String& other);

    const char* getStr() const;
    int getLength() const;
    void setStr(const char* _str);
    void setLength(int _length);

    String operator+=(const String& other); //
    String operator+=(const char* _str); //
    String operator+=(const char x); //
    String operator+(const char* _str); //

    void output();
    void add(const char* _str);
    void removeLast();
    void slice(int start, int end); //
};

#endif
