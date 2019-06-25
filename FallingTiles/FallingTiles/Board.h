#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include "Tetrimino.h"

const int NUM_ROWS = 20;
const int NUM_COLS = 10;

class Board 
{
    public:
        Board();
        ~Board();
        void printBoard();
        bool addTetrimino(Tetrimino *tetrimino, int x, int y);
    private:
        int *board;
        void initializeBoard();
};
#endif
