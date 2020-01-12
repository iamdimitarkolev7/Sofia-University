#include <iostream>
using namespace std;

struct Lesson
{
    int start, end;
};

Lesson *generateStruct(size_t n)
{
    Lesson *lessons = new (nothrow) Lesson[n];

    if (!lessons)
    {
        return 0;
    }

    return lessons;
}

void input(Lesson *lessons, size_t n)
{
    for (int i = 0; i < n; i++)
    {
        cin >> lessons[i].start;
        cin >> lessons[i].end;
    }
}

void bubbleSort(Lesson *lessons, size_t n)
{
    Lesson helper;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (lessons[j].end > lessons[j + 1].end)
            {
                helper = lessons[j];
                lessons[j] = lessons[j + 1];
                lessons[j + 1] = helper;
            }
        }
    }
}

void output(Lesson *lessons, size_t n)
{
    cout << endl;

    for (int i = 0; i < n; i++)
    {
        cout << lessons[i].start << " " << lessons[i].end << endl;
    }
}

void calculateMax(Lesson *lessons, size_t n)
{
    int max = 1;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (lessons[i].end <= lessons[j].start)
            {
                max++;
                i = j;
                continue;
            }
        }
    }

    cout << max;
}

int main()
{
    size_t n, max = 0;

    cin >> n;

    Lesson *lessons = generateStruct(n);

    input(lessons, n);
    bubbleSort(lessons, n);
    //output(lessons, n);
    calculateMax(lessons, n);

    delete[] lessons;

    return 0;
}