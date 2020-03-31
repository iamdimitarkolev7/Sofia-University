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

TEST_CASE("Operator+, operator+= and operator= test")
{
    String str1("Dimitar");
    String str2;
    String str3(" 7");
    String str4, str5("Mercedes"), str6("Benz");

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

    str4 = str5 + str6;

    CHECK(str4.getLength() == 12);
    CHECK(strcmp(str4.getStr(), "MercedesBenz") == 0);

    CHECK(str4[5] == 'd');
} 

TEST_CASE("Bool operators test")
{
    String name1("Angel"), name2("Boyan"), name3("Angel"), name4("Anton");

    CHECK((name1 == name3) == true);
    CHECK((name1 != name2) == true);
    CHECK((name1 == name2) == false);
    CHECK((name1 < name2) == true);
    CHECK((name1 > name2) == false);
    CHECK(((name1 <= name3) && (name1 <= name4)) == true);
    CHECK((name1 >= name3) == true);
    CHECK(((name1 >= name2) && (name1 >= name4)) == false);
}

TEST_CASE("Methods test")
{
    String str1;
    
    str1.add("xaxaxax");

    CHECK(str1.getLength() == 7);
    CHECK(strcmp(str1.getStr(), "xaxaxax") == 0);

    str1.removeLast();

    CHECK(str1.getLength() == 6);
    CHECK(strcmp(str1.getStr(), "xaxaxa") == 0);

    str1.replace("xa", "pa");

    CHECK(str1.getLength() == 6);
    CHECK(strcmp(str1.getStr(), "papapa") == 0);

    String str2("Dimitar Kolev"), str3("Kolev");

    CHECK((str2.slice(8, 12)).getLength() == 5);
    CHECK(strcmp((str2.slice(8, 12)).getStr(), "Kolev") == 0);
}

int main()
{
    doctest::Context().run();
}