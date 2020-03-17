#include <iostream>
#include <cassert>

class Time
{
public:
    int hours;
    int minutes;

    void init()
    {
        std::cout << "The time is " << this->hours << ":" << this->minutes << std::endl;
    }

    void change(int new_hours, int new_minutes)
    {
        while (new_hours < 0 || new_hours > 24)
        {
            std::cout << "Wrong input! Please try again! Insert correct data for hours: ";
            std::cin >> new_hours;
        }

        while (new_minutes < 0 || new_minutes >= 60)
        {
            std::cout << "Wrong input! Please try again! Insert correct data for minutes: ";
            std::cin >> new_minutes;
        }

        this->hours = new_hours;
        this->minutes = new_minutes;
    }

    Time operator+(int m) //adding minutes to current time
    {
        this->minutes += m;

        while (this->minutes > 60)
        {
            this->hours += 1;
            this->minutes -= 60;
        }

        while (this->hours > 24)
        {
            this->hours -= 24;
        }

        Time result;
        result.hours = this->hours;
        result.minutes = this->minutes;

        return result;
    }

    Time operator-(int m) // minutes to current time
    {
        this->minutes -= m;

        while (this->minutes < 0)
        {
            this->hours -= 1;
            this->minutes += 60;
        }

        while (this->hours < 0)
        {
            this->hours += 24;
        }

        Time result;
        result.hours = this->hours;
        result.minutes = this->minutes;

        return result;
    }

    bool operator==(Time &otherTime)
    {
        return this->hours == otherTime.hours && this->minutes==otherTime.minutes;
    }

    bool operator<(Time &otherTime)
    {
        if (this->hours < otherTime.hours)
        {
            return true;
        }

        if (this->hours > otherTime.hours)
        {
            return false;
        }

        return this->minutes < otherTime.minutes;
    }

    Time operator*(int num)
    {
        assert(this->minutes * num != 0);

        std::cout << this->minutes << std::endl;
        this->minutes *= num;

        while (this->minutes > 60)
        {
            this->hours += 1;
            this->minutes -= 60;
        }

        while (this->hours > 24)
        {
            this->hours -= 24;
        }

        while (this->minutes < 0)
        {
            this->hours -= 1;
            this->minutes += 60;
        }

        while (this->hours < 0)
        {
            this->hours += 24;
        }

        Time result;
        result.hours = this->hours;
        result.minutes = this->minutes;

        return result;
    }

    int totalMinutes()
    {
        return this->hours * 60 + this->minutes;
    }
};

int main()
{
    Time time1;
    time1.hours = 5;
    time1.minutes = 19;

    time1.init();
    time1.change(17, 39);
    time1.init();
    time1.change(25, 68); // change it to 11:30
    time1.init();

    std::cout << std::endl;

    std::cout << time1.totalMinutes() << std::endl;

    Time time2;
    time2.hours = 12;
    time2.minutes = 30;
    time2.init();

    std::cout << (time1 < time2) << std::endl; //1
    std::cout << (time1 == time2) << std::endl; //0
    
    Time time3;
    time3 = time1 - 12; //11:18
    
    time3.init();

    time3 = time2 + 87; //13:57
    time3.init();

    time3 = time3 * 5; //17:45
    time3.init();

    return 0;
}