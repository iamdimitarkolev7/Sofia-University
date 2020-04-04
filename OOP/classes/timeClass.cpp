#include <iostream>
#include <cassert>

class Time
{
    private:
    int hours;
    int minutes;

    void setHours(int _hours)
    {
        hours = _hours;
    }

    void setMinutes(int _minutes)
    {
        minutes = _minutes;
    }

    void copy(int _hours, int _minutes)
    {
        setHours(_hours);
        setMinutes(_minutes);
    }

    public:
    Time() : hours(0), minutes(0) {}
    Time(int _hours, int _minutes) : hours(_hours), minutes(_minutes) {}
    Time(const Time &other)
    {
        copy(other.hours, other.minutes);
    }

    Time &operator=(const Time &other)
    {
        if (this != &other)
        {
            copy(other.hours, other.minutes);
        }

        return *this;
    }

    Time operator+(int _minutes) //adding minutes to current time
    {
        minutes += _minutes;

        while (minutes > 60)
        {
            hours += 1;
            minutes -= 60;
        }

        while (hours > 24)
        {
            hours -= 24;
        }

        Time result;
        result.copy(hours, minutes);

        return result;
    }

    Time operator-(int _minutes) // removing minutes from current time
    {
        minutes -= _minutes;

        while (minutes < 0)
        {
            hours -= 1;
            minutes += 60;
        }

        while (hours < 0)
        {
            hours += 24;
        }

        Time result;
        result.copy(hours, minutes);

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

        //std::cout << this->minutes << std::endl;
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
        result.copy(this->hours, this->minutes);

        return result;
    }

    int getHours()
    {
        return hours;
    }

    int getMinutes()
    {
        return minutes;
    }

    int totalMinutes()
    {
        return this->hours * 60 + this->minutes;
    }
    
    void init()
    {
        std::cout << "The time is " << hours << ":" << minutes << std::endl;
    }

    void change(int newHours, int newMinutes)
    {
        while (newHours < 0 || newHours > 24)
        {
            std::cout << "Wrong input! Please try again! Insert correct data for hours: ";
            std::cin >> newHours;
        }

        while (newMinutes < 0 || newMinutes >= 60)
        {
            std::cout << "Wrong input! Please try again! Insert correct data for minutes: ";
            std::cin >> newMinutes;
        }

        copy(newHours, newMinutes);
    }
};

int main()
{
    Time time1(5, 19);

    time1.init();
    time1.change(17, 39);
    time1.init();
    time1.change(25, 68); // change it to 11:30
    time1.init();

    std::cout << std::endl;

    std::cout << time1.totalMinutes() << std::endl;

    Time time2(12, 30);
    time2.init();

    std::cout << (time1 < time2) << std::endl; 
    std::cout << (time1 == time2) << std::endl; //0
    
    Time time3;
    time3 = time1 - 12;
    
    time3.init();

    time3 = time2 + 87; //13:57
    time3.init();

    time3 = time3 * 5; //17:45
    time3.init();

    Time time4;
    time4 = time3;
    std::cout << time4.getHours() << ":" << time4.getMinutes() << std::endl;

    return 0; 
}