#ifndef TETRIMINO_H
#define TETRIMINO_H

#include <iostream>
#include "Point.hpp"

const int MAX_ROWS = 4;
const int MAX_COLS = 4;

class Tetrimino 
{
    public:
    	Tetrimino();
    	Tetrimino(char type);
    	~Tetrimino();
    	void rotateLeft();
    	void rotateRight();
    	void rotatePointsLeft();
    	void rotatePointsRight();
    	void printTetrimino();
        void plotPointsAndPrint(); // separate later
        void printPointsInfo();
    private:
        void rotate(char direction);
        void rotatePoints(char direction);
    	void setTetrimino(char type);
    	void setTetriminoValues(int arr[][MAX_COLS]);
    	int *tetrimino;
        Point p1;
        Point p2;
        Point p3;
        Point center;
    
};
#endif
