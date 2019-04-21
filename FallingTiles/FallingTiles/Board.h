#ifndef BOARD_H
#define BOARD_h
#endif

#include <iostream>

const int NUM_ROWS = 20;
const int NUM_COLS = 10;

class Board 
{
    public:
        Board();
        ~Board();
        void printBoard();
    private:
        int *board;
        void initializeBoard();
};
