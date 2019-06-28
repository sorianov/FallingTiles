#ifndef TETRIMINO_H
#define TETRIMINO_H

#include "PointGrid.hpp"

const int MAX_ROWS = 4;
const int MAX_COLS = 4;
const int MAX_POINTS = 4;

class Tetrimino 
{
    public:
    	Tetrimino();
    	Tetrimino(char type);
    	void rotateLeft();
    	void rotateRight();
    	void printTetrimino();
    private:
    	void setTetrimino(char type);
        PointGrid tetrimino;
    
};
#endif
