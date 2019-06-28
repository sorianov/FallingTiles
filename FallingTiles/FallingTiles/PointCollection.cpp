#include "PointCollection.hpp"

PointGrid::PointGrid()
{
    this->numRows = 0;
    this->numCols = 0;
    this->maxPoints = 0;
    this->currentNumPoints = 0;
    this->pointStorage = nullptr;
}

PointGrid::PointGrid(int numRows, int numCols, int maxPoints)
{
    this->numRows = numRows;
    this->numCols = numCols;
    this->maxPoints = maxPoints;
    this->currentNumPoints = 0;
    this->pointStorage = new Point[maxPoints];
    for (int i = 0; i < maxPoints; i++) {
        this->pointStorage[i] = Point(); // initialize with empty Points
    }

}

PointGrid::~PointGrid()
{
    if (this->pointStorage != nullptr) {
        delete [] this->pointStorage;
        this->pointStorage = nullptr;
    }
}

bool PointGrid::addPoint(Point p)
{
    int x = p.getX();
    int y = p.getY();
    Point *currPoint = nullptr;

    // If we add another point, we exceed maxPoints. We don't
    // want to cause an out of bounds error.
    if (this->currentNumPoints + 1 > this->maxPoints) {
        return false;
    }

    // If the Point fits on our grid, add it to an available spot.
    if (x <= this->numRows && y <= this->numCols) {

        for (int i = 0; i < this->maxPoints; i++) {
            currPoint = &this->pointStorage[i];
            if (currPoint->isEmpty()) {
                this->pointStorage[i] = p;
                delete currPoint;
                currPoint = nullptr;
                return true;
            }
        }
    }

    if (currPoint != nullptr) {
        delete currPoint;
        currPoint = nullptr;
    }

    return false;
}
