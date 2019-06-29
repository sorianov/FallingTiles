#ifndef POINTCOLLECTION_H
#define POINTCOLLECTION_H

#include "Point.hpp"

class PointGrid {
    public:
        PointGrid();
        PointGrid(int, int, int);
        ~PointGrid();
        bool addPoint(int, int);
        bool removePoint(Point);
        int distance(Point, Point);
        void rotatePointsLeft();
        void rotatePointsRight();
        void printGrid();
    private:
        int numRows; // Number of rows in our 'grid'.
        int numCols; // Number of columns in our 'grid'.
        int maxPoints; // Maximum number of points we can store.
        int currentNumPoints; // Current number of Points being stored.
        int** initGrid(); // Initialize 2D array.
        void deallocGrid(int**); // Dealloc pointer of pointers.
        Point *pointStorage; // Array we'll use to store our Points.
        void rotatePoints(char direction);

};

#endif
