#ifndef POINT_H
#define POINT_H

class Point 
{
    public:
        Point();
        Point(int x, int y);
        ~Point();
        int getX();
        int getY();
        int setX(int x);
        int setY(int y);
        void setXY(int x, int y);
    private:
        int x;
        int y;

};

#endif
