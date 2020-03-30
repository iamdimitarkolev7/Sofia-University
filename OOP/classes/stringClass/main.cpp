#define DOCTEST_CONFIG_IMPLEMENT
#include <iostream>
#include "doctest.h"
#include "string.cpp"

TEST_CASE("Constructors test")
{
    String str1;
    String str2("Dimitar");
    String str3(str2);

    CHECK(str1.getLength() == 0);
    CHECK(str1.getStr() == nullptr);
    CHECK(str2.getLength() == 7);
    CHECK(strcmp(str2.getStr(), "Dimitar") == 0);
    CHECK(str3.getLength() == 7);
    CHECK(strcmp(str3.getStr(), "Dimitar") == 0);
}

TEST_CASE("Operators test")
{
    String str1("Dimitar");
    String str2;
    String str3(" 7");
    String str4;

    str2 = str1;

    CHECK(str2.getLength() == 7);
    CHECK(strcmp(str2.getStr(), "Dimitar") == 0);

    str2 += " Kolev";

    CHECK(str2.getLength() == 13);
    CHECK(strcmp(str2.getStr(), "Dimitar Kolev") == 0);

    str2 += str3;

    CHECK(str2.getLength() == 15);
    CHECK(strcmp(str2.getStr(), "Dimitar Kolev 7") == 0);

    str4 = str1 + " Nikolaev Kolev";

    CHECK(str4.getLength() == 22);
    CHECK(strcmp(str4.getStr(), "Dimitar Nikolaev Kolev") == 0);
} 

int main()
{
    doctest::Context().run();
}