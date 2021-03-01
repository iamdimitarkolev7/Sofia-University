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

    bool isMatching(char *strToSearch, const char *strToMatch);
    void shiftLeft(char *strToShift, int shiftPosCount);
    void shiftRight(char *strToShift, int shiftPosCount);
    void performStringReplacement(char *source, const char *newWord);
    void setStr(const char *_str);
    void setLength(int _length);

public:
    String();
    String(const char *_str);
    String(const String &other);
    ~String();
    String &operator=(const String &other);

    const char *getStr() const;
    int getLength() const;

    String operator+=(const String &other);
    String operator+=(const char *_str);
    String operator+(const String &other);
    String operator+(const char *_str);
    char operator[](const int index) const;
    //char& operator[](const int index);
    bool operator!=(const String &other);
    bool operator==(const String &other);
    bool operator<(const String &other);
    bool operator>(const String &other);
    bool operator<=(const String &other);
    bool operator>=(const String &other);

    void output(); 
    void add(const char *_str);
    void removeLast();
    String slice(int start, int end) const;
    void replace(const char *oldWord,const char *newWord);
    void toUpperCase();
    void toLowerCase();
    void trim();
    //String* split(const char* delimiter); TODO... 
};

#endif
