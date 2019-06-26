#include "Point.hpp"

Point::Point()
{
    this->x = 0;
    this->y = 0;
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
}

Point::~Point()
{
    this->x = 0;
    this->y = 0;
}

int Point::getX()
{
    return this->x;
}

int Point::getY()
{
    return this->y;
}

int Point::setX(int x)
{
    this->x = x;
    return this->x;
}

int Point::setY(int y)
{
    this->y = y;
    return this->y;
}

void Point::setXY(int x, int y)
{
    this->x = x;
    this->y = y;
}

