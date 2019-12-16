#include <iostream>
using namespace std;

bool canFormTriangle(double a, double b, double c)
{
    return a * a == b * b + c * c;
}

bool hasTriangles(double arr1[], double arr2[], double arr3[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                if (canFormTriangle(arr1[i], arr2[j], arr3[k]) || 
                    canFormTriangle(arr2[j], arr1[i], arr3[k]) ||
                    canFormTriangle(arr3[k], arr2[j], arr1[i]))
                        return true;
            }
        }
    }

    return false;
}

int main()
{
    double arr1[20], arr2[20], arr3[20];
    int n;

    cout << "n = ";
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr2[i];
    }

    for (int i = 0; i < n; i++)
    {
        cin >> arr3[i];
    }

    cout << hasTriangles(arr1, arr2, arr3, n) << endl;

    return 0;
}