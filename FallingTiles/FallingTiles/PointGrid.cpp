#include <iostream>
#include "PointGrid.hpp"

PointGrid::PointGrid()
{
    numRows = 0;
    numCols = 0;
    maxPoints = 0;
    currentNumPoints = 0;
    pointStorage = nullptr;
}

PointGrid::PointGrid(int rows, int cols, int points)
{
    numRows = rows;
    numCols = cols;
    maxPoints = points;
    currentNumPoints = 0;
    pointStorage = nullptr;
}

PointGrid::~PointGrid()
{
    if (pointStorage != nullptr) {
        delete [] pointStorage;
        pointStorage = nullptr;
    }
}

bool PointGrid::addPoint(int x, int y)
{
    Point p;
    bool empty;

    if (pointStorage == nullptr) {
        pointStorage = new Point[maxPoints];
    }

    // If we add another point, we exceed maxPoints. We don't
    // want to cause an out of bounds error.
    if (currentNumPoints + 1 > maxPoints) {
        return false;
    }

    // If the Point fits on our grid, add it to an available spot.
    if (x <= numRows && y <= numCols) {

        for (int i = 0; i < maxPoints; i++) {
            p = pointStorage[i];
            p.isEmpty(empty);
            if (empty) {
                p.setXY(x, y);
                pointStorage[i] = p;
                currentNumPoints++;
                return true;
            }
        }
    }

    return false;
}

void PointGrid::rotatePointsLeft()
{
    rotatePoints('l');
}

void PointGrid::rotatePointsRight()
{
    rotatePoints('r');
}

void PointGrid::rotatePoints(char direction)
{
    int x = 0;
    int y = 0;
    int newX = 0;
    int newY = 0;
    Point p;
    bool empty;

    for (int i = 0; i < maxPoints; i++) {
        p = pointStorage[i];
        p.isEmpty(empty);
        // Can't rotate nothing...I guess technically you can,
        // but you know what I mean.
        if (empty) {
            break;
        }

        p.getX(x);
        p.getY(y);

        if (direction == 'l') {
            newX = (numRows - 1) - y;
            newY = x;
        }

        if (direction == 'r') {
            newX = y;
            newY = (numRows - 1) - x;
        }

        p.setXY(newX, newY);
        pointStorage[i] = p;
    }
}

int PointGrid::distance(Point a, Point b)
{
    return 0; // TODO
}

bool PointGrid::removePoint(Point p)
{
    return true; // TODO
}

int** PointGrid::initGrid() {
    int** grid = nullptr;
    grid = new int* [numRows];
    for (int i = 0; i < numRows; i++) {
        grid[i] = new int[numCols];
    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            grid[i][j] = 0;
        }
    }
    return grid;
}

void PointGrid::deallocGrid(int** grid) {
    for (int i = 0; i < numRows; i++) {
        delete [] grid[i];
        delete [] grid[i];
        grid[i] = nullptr;
    }

    delete [] grid;
    grid = nullptr;
}


void PointGrid::printGrid()
{
    int** board = initGrid();
    int x = 0;
    int y = 0;
    Point p;

    for (int i = 0; i < maxPoints; i++) {
        p = pointStorage[i];
        p.getX(x);
        p.getY(y);
        board[x][y] = 1;
    }

    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numCols; j++) {
            std::cout << board[i][j] << ", ";
        }
        std::cout << std::endl;
    }
    deallocGrid(board);
}
