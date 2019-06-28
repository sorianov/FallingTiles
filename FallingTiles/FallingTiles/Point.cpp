#include "Point.hpp"

Point::Point()
{
    this->x = -1;
    this->y = -1;
    // if this constructor is called, we'll assume
    // that it's an empty point. The reasoning is that
    // (0,0) is a valid point even though that's our default.
    /* this->empty = true; */
}

Point::Point(int x, int y)
{
    this->x = x;
    this->y = y;
    // We had to have recieved some values
    // so we can say this Point is not empty.
    /* this->empty = false; */
}

Point::~Point() {}

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
    return;
}

bool Point::isEmpty()
{
    // We'll report empty if the user has left a value
    // unset. That'll teach 'em.
    return (this->x == -1 || this->y == -1);
}

