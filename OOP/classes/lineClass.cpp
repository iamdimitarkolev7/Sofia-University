#include <iostream>

struct Point
{
    double x;
    double y;
};

class Line
{
public:
    Point point1;
    Point point2;

    bool isParallel(Line otherLine)
    {
        bool checkX = (this->point1.x - otherLine.point1.x == this->point2.x - otherLine.point2.x);
        bool checkY = (this->point1.y - otherLine.point1.y == this->point2.y - otherLine.point2.y);

        return checkX || checkY;
    }

    bool isOnLine(Point p)
    {
        return (this->point1.x <= p.x && this->point2.x >= p.x )
            && (this->point1.y <= p.y && this->point2.y >= p.y);
    }

    Point cross(Line otherLine)
    {
         
    }
};

int main()
{
    //Test task 1
    Line line1, line2;

    line1.point1.x = 0, line1.point1.y = 0;
    line1.point2.x = 0, line1.point2.y = 8;
    line2.point1.x = 1, line2.point1.y = 1;
    line2.point2.x = 1, line2.point2.y = 10;

    std::cout << line1.isParallel(line2) << std::endl;
    std::cout << line1.isParallel(line1) << std::endl;

    //Test task 2
    Point p;
    p.x = 0, p.y = 7;

    std::cout << line1.isOnLine(p) << std::endl;
    std::cout << line2.isOnLine(p) << std::endl;

    //Test task 3
    Line line3;

    line3.point1.x = -1, line3.point1.y = 0;
    line3.point2.x = 5, line3.point2.y = 8;



    return 0;
}