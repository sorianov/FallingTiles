#include "Point.hpp"

Point::Point()
{
    x = -1;
    y = -1;
}

Point::Point(int x_, int y_)
{
    x = x_;
    y = y_;
}

void Point::getX(int &x_)
{
    x_ = x;
}

void Point::getY(int &y_)
{
    y_ = y;
}

void Point::setX(int x_)
{
    x = x_;
}

void Point::setY(int y_)
{
    y = y_;
}

void Point::setXY(int x_, int y_)
{
    x = x_;
    y = y_;
}

void Point::isEmpty(bool& empty)
{
    // We'll report empty if the user has left a value
    // unset. That'll teach 'em.
    empty = (x == -1 || y == -1);
}

