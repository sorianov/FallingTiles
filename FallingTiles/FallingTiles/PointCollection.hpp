#ifndef POINTCOLLECTION_H
#define POINTCOLLECTION_H

#include "Point.hpp"

class PointGrid {
    public:
        PointGrid();
        PointGrid(int maxRows, int maxCols, int maxPoints);
        ~PointGrid();
        bool addPoint(Point p);
        bool removePoint(Point p);
        int distance(Point a, Point b);
    private:
        int numRows; // Number of rows in our 'grid'.
        int numCols; // Number of columns in our 'grid'.
        int maxPoints; // Maximum number of points we can store.
        int currentNumPoints; // Current number of Points being stored.
        Point *pointStorage; // Array we'll use to store our Points.

};

#endif
