#include <iostream>
#include <cstring>
using namespace std;

int partition(char arr[], int start, int end)
{
    int pivot = arr[end],  i = start;

    for(int j = start; j <= end; j++)
    {
        if(arr[j] < pivot)
        {
            swap(arr[i], arr[j]); 
            i++;                  
        }
    }
    swap(arr[i], arr[end]);
    return i;
}

void quickSort(char arr[], int start, int end)
{
    if(start < end)
    {
        int p = partition(arr, start, end);
        quickSort(arr, start, p - 1);                                                                       
        quickSort(arr, p + 1, end);  
    }
}

bool canFormString(char str1[], char str2[], char str3[])
{
    int length1 = strlen(str1), length2 = strlen(str2), length3 = strlen(str3);
    bool isTrue = true;

    if (length1 + length2 != length3)
    {
        return false;
    }

    quickSort(str3, 0, length1 - 1);
    quickSort(str3, length1, length3 - 1);

    for (int i = 0; i < length1; i++)
    {
        if (str1[i] != str3[i])
        {
            isTrue = false;
        }
    }

    int p = length1;

    for (int i = 0; i < length2; i++)
    {
        if (str2[i] != str3[p])
        {
            isTrue = false;
        }

        p++;
    }

    return isTrue;
}

int main()
{
    char str1[255], str2[255], str3[510];
    cin.getline(str1, 255);
    cin.getline(str2, 255);
    cin.getline(str3, 510);

    quickSort(str1, 0, strlen(str1) - 1);
    quickSort(str2, 0, strlen(str2) - 1);

    if (canFormString(str1, str2, str3) || canFormString(str2, str1, str3))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    } 

    return 0;
}