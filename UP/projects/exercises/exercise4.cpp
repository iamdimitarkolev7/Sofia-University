#include<iostream>
using namespace std;
 
int main()
{
    int n, minLeft, minBottom, maxTop, maxRight;
    cin >> n;
 
    int a, b;
    cin >> a >> b;
 
    minLeft = maxRight = a;
    minBottom = maxTop = b;
 
    for(int i = 1; i < n; i++)
    {  
        cin >> a >> b;
 
        if(a <= minLeft) minLeft = a;
        if(a >= maxRight) maxRight = a;
        if(b <= minBottom) minBottom = b;
        if(b >= maxTop) maxTop = b;
    }
 
 
    cout << minLeft << " " << maxTop << " " << maxRight - minLeft << " " << maxTop - minBottom << endl;

    return 0;
}