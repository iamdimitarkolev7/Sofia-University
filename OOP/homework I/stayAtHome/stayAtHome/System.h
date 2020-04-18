#pragma once
#ifndef _SYSTEM_H
#define _SYSTEM_H 
#include "User.h"

class System
{
public:
    static System& i();

    System(const System&) = delete;
    ~System();

    void registration(const User& user);
    //challenge
    //finish
    void profile_info(const char* name);
    //list_by
    //load
    void help();
    void run();

private:
    System();

    bool isNumber(char* s);
};

#endif