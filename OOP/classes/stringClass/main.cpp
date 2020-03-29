#define DOCTEST_CONFIG_IMPLEMENT
//#include "doctest.h"
#include <iostream>
#include "string.cpp"

int main()
{
    String str1("Dimitar", 7);
    String str2(str1);

    std::cout << str1.getLength() << std::endl;

    str1.add(" Kolev");
    str1.output(); //Dimitar Kolev
    str2.output(); //Dimitar

    std::cout << str1.getLength() << std::endl; //13

    str2.removeLast(); //Dimita
    str2.removeLast(); //Dimit
    str2.removeLast(); //Dimi
    str2.removeLast(); //Dim

    str2.output(); //Dim
    std::cout << str2.getLength() << std::endl; //3

    return 0;
}