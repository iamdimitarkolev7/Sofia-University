/*
   Да се напише програма, която приема 2 естествени числа и намира 
   техния най-голям общ делител, използвайки алгоритъма на Евклид.
*/

#include <iostream>
using namespace std;

int greatestCommonDivisor(int a, int b)
{
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 

    if (a == b) 
        return a; 
    
    if (a > b) 
        return greatestCommonDivisor(a - b, b); 
    return greatestCommonDivisor(a, b - a);
}

int main()
{
    int a, b;
    cin >> a;
    cin >> b;

    cout << greatestCommonDivisor(a, b) << endl;
    return 0;
}