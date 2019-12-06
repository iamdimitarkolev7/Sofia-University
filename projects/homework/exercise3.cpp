#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
    int a, b, n, numbers[10], counterCycle = 0, counterOccurences = 0;
 
    do {
        cout << "a = ";
        cin >> a;
        cout << "b = ";
        cin >> b;

        if (a > b)
        {
            cout << "Invalid input! Please try again!" << endl;
        }
    } while(a > b);
    

    do {
        cout << "n = ";
        cin >> n;
        if (n < 0 || n > 9)
        {
            cout << "Invalid input! Please try again!" << endl;
        }
    } while(n < 0 || n > 9);
    
 
    for (int i = 0; i < n; i++)
    {
        cin >> numbers[i];
    }

    bool isNull = false;
 
    for (int i = a; i <= b; i++)
    {
        int number = abs(i);
 
        while (number > 0)
        {
            int digit = number % 10;
           
            for (int j = 0; j < n; j++)
            {
                counterCycle++;
 
                if (digit == numbers[j])
                {
                    counterOccurences++;
                }
               
            }
 
            number /= 10;
        }
 
        if (counterOccurences == counterCycle / n)
        {
            cout << i << " ";
        }      
 
        counterCycle = 0, counterOccurences = 0;
    }
 
    cout << endl;
    return 0;
}