#ifndef BOARD_H
#define BOARD_H

#include "Tetrimino.hpp"

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
        int **board;
        void initializeBoard(int**&);
        void deallocBoard(int**&);
};
#endif
