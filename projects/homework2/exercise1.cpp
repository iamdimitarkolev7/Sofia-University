#include <iostream>
#include <cstring>
using namespace std;

bool is(char str1[], char str2[], char str3[])
{
    int length1 = strlen(str1), length2 = strlen(str2), length3 = strlen(str3);

    if (length1 + length2 != length3)
    {
        return false;
    }

    
}

int main()
{
    char str1[255], str2[255], str3[510];
    cin.getline(str1, 255);
    cin.getline(str2, 255);
    cin.getline(str3, 510);

    cout << is(str1, str2, str3) << endl;
    return 0;
}