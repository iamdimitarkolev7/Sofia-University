#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

struct Data
{
    int x, y;
    char hours[5];
};

void bubbleSort(Data data[], int n)
{
    Data helper;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - j; j++)
        {   

            if (strcmp(data[j].hours, data[j + 1].hours) == 1)
            {
                helper = data[j];
                data[j] = data[j + 1];
                data[j + 1] = helper;
            }
        }
    }
}

double getTravelledDistance(Data data[], int n)
{
    double travelledDistance = 0;
    double currentDistance = 0;

    for (int i = 0; i < n - 1; i++)
    {
        currentDistance = sqrt(pow(data[i].x - data[i + 1].x, 2) +  pow(data[i].y - data[i + 1].y, 2));
        travelledDistance += currentDistance;
    }

    return travelledDistance;
}

void parkedOnTheSamePlace(Data data[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (data[i].x == data[j].x && data[i].y == data[j].y)
                {
                    cout << "Parked on the same place: Yes" << endl;
                    return;
                }
            }
        }
    }

    cout << "Parked on the same place: No" << endl;
}

int main()
{
    int n;
    Data dataRecord[100];

    do
    {
        cout << "n = ";
        cin >> n;

        if (n < 0 || n > 100)
        {
            cout << "Invalid input! Please try again!" << endl;
        }
    } while (n < 0 || n > 100);
    
    for (int i = 0; i < n; i++)
    {
        cin >> dataRecord[i].x >> dataRecord[i].y;
        cin.ignore();
        cin.getline(dataRecord[i].hours, 6);
    }

    cout << endl;

    bubbleSort(dataRecord, n);
    
    cout << "Distance: " << getTravelledDistance(dataRecord, n) << endl;
    parkedOnTheSamePlace(dataRecord, n);
    
    return 0;
}