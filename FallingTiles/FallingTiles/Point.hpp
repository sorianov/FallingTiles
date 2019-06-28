#ifndef POINT_H
#define POINT_H

class Point 
{
    public:
        Point();
        Point(int, int);
        void getX(int&);
        void getY(int&);
        void setX(int);
        void setY(int);
        void setXY(int, int);
        void isEmpty(bool&);
    private:
        int x;
        int y;

};

#endif
