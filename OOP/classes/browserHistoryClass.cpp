#include <iostream>
#include <cstring>
#include <cassert>

struct HistoryEntry
{
    size_t month;
    char url[255];
};

class BrowserHistory
{
private:
    HistoryEntry *data;
    size_t max;
    size_t length;
public:
    BrowserHistory() : data(nullptr), length(0), max(0) {}

    BrowserHistory(size_t n) : data(nullptr), max(n), length(0) {}

    BrowserHistory(const BrowserHistory &other)
    {
        this->data = new HistoryEntry[other.length];

        for (size_t i = 0; i < other.length; i++)
        {
            this->data[i].month = other.data[i].month;
            strcpy(this->data[i].url, other.data[i].url);
        }

        this->max = other.max;
        this->length = other.length;
    }

    ~BrowserHistory()
    {
        //std::cout << "Destructor invoked" << std::endl;
        delete[] this->data;
    }

    BrowserHistory operator=(const BrowserHistory &other)
    {
        if (this != &other)
        {
            delete[] this->data;
            this->data = new (std::nothrow) HistoryEntry[other.length];

            if (!this->data)
            {
                std::cout << "Not enough memory!" << std::endl;
                this->data = nullptr;
                this->length = 0;
                return 0;
            }

            for (int i = 0; i < other.length; i++)
            {
                this->data[i].month = other.data[i].month;
                strcpy(this->data[i].url, other.data[i].url);
            }

            this->length = other.length;
            this->max = other.max;
        }

        return *this;
    }

    BrowserHistory operator+=(HistoryEntry siteData)
    {
        assert(this->length + 1 <= this->max);

        HistoryEntry *newData = new HistoryEntry[this->length + 1];

        for (size_t i = 0; i < this->length; i++)
        {
            newData[i].month = this->data[i].month;
            strcpy(newData[i].url, this->data[i].url);
        }

        newData[this->length].month = siteData.month;
        strcpy(newData[this->length].url, siteData.url);

        delete[] this->data;

        this->data = newData;
        this->length++;

        return *this;
    }

    BrowserHistory operator+(const BrowserHistory &other)
    {
        BrowserHistory res(this->max + other.max);

        for (size_t i = 0; i < this->length; i++)
        {
            res.add(this->data[i]);
        }

        for (size_t i = 0; i < other.length; i++)
        {
            res.add(other.data[i]);
        }

        return res;
    }

    size_t getLength()
    {
        return this->length;
    }

    void add(HistoryEntry siteData)
    {
        assert(this->length + 1 <= this->max);
        HistoryEntry *newData = new HistoryEntry[this->length + 1];

        for (size_t i = 0; i < this->length; i++)
        {
            newData[i].month = this->data[i].month;
            strcpy(newData[i].url, this->data[i].url);
        }

        newData[this->length].month = siteData.month;
        strcpy(newData[this->length].url, siteData.url);

        delete[] this->data;

        this->length++;
        data = newData;
    }

    BrowserHistory deleteLatest()
    {
        assert(this->length - 1 >= 0);

        HistoryEntry *newBuffer = new HistoryEntry[this->length - 1];

        for (size_t i = 0; i < this->length - 1; i++)
        {
            newBuffer[i].month = this->data[i].month;
            strcpy(newBuffer[i].url, this->data[i].url);
        }

        delete[] this->data;

        this->data = newBuffer;
        this->length--;

        return *this;
    }

    void findData(size_t _month)
    {
        int counter = 0;

        for (size_t i = 0; i < this->length; i++)
        {
            if (this->data[i].month == _month)
            {
                std::cout << "Site: " << this->data[i].url << std::endl;
                counter++;
            }
        }

        if (counter == 0)
        {
            std::cout << "No browser history in this month!" << std::endl;
        }
    }

    void printMonth()
    {
        int arrCounter[12] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

        for (size_t i = 0; i < this->length; i++)
        {
            arrCounter[i + this->data[i].month]++;
        }

        int month;

        for (size_t i = 0; i < 12; i++)
        {
            for (size_t j = 0; j < 12 - i; j++)
            {
                if (arrCounter[j + 1] > arrCounter[j])
                {
                    month = j + 1;
                }
            }
        }

        std::cout << "The month in which you visited the most sites is: " << month << std::endl;
    }

    void output()
    {
        for (size_t i = 0; i < this->length; i++)
        {
            std::cout << "Month: " << this->data[i].month << std::endl;
            std::cout << "Site: " << this->data[i].url << std::endl;
        }
    }
};

int main()
{
    BrowserHistory history1(10);
    HistoryEntry entry1 = {7, "www.kolev7.com"};
    HistoryEntry entry2 = {12, "www.facebook.com"};
    HistoryEntry entry3 = {7, "www.7777.bg"};
    HistoryEntry entry4 = {6, "www.8888.net"};

    history1.add(entry1);
    history1 += entry2;
    history1.add(entry3);
    history1 += entry4;
    history1.output();

    std::cout << std::endl;
    history1.findData(5);
    history1.findData(6);

    std::cout << std::endl;
    history1.printMonth();

    BrowserHistory history2(12);

    history1.deleteLatest();
    history2 = history1;
    history2.output();
    history1.output();

    std::cout << std::endl;

    BrowserHistory history3(15);
    history3 = history2 + history1;

    history3.output();

    std::cout << std::endl
              << "Copy constructor test: " << std::endl;

    BrowserHistory history4(history1);
    history4.output();

    std::cout << std::endl
              << "Operator= test: " << std::endl;
    BrowserHistory history5;
    history5 = history4;
    history5.output();

    return 0;
}