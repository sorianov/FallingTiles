#include <iostream>
#include "Board.hpp"

Board::Board() 
{
    board = nullptr;
    initializeBoard(board);
}

Board::~Board() 
{
    deallocBoard(board);
}

void Board::printBoard() 
{
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            std::cout << board[i][j] << " | ";
        }
        std::cout << std::endl;
    }
}

void Board::initializeBoard(int**& board) 
{

    if (board == nullptr) {
        board = new int* [NUM_ROWS];
        for (int i = 0; i < NUM_ROWS; i++) {
            board[i] = new int[NUM_COLS];
            for (int j = 0; j < NUM_COLS; j++) {
                board[i][j] = 0;
            }
        }
    } else {
        deallocBoard(board);
        initializeBoard(board);
    }
}

void Board::deallocBoard(int**& board)
{
    if (board != nullptr) {
        for (int i = 0; i < NUM_ROWS; i++) {
            delete [] board[i]; 
        }
        delete [] board;
        board = nullptr;
    }
}

bool Board::addTetrimino(Tetrimino *tetrimino, int x, int y)
{
    if (x > NUM_ROWS || y > NUM_COLS) {
        return false; // Out of bounds.
    }


    //this->board[x * NUM_COLS + y] = tetrimino->getCenter(); // TODO

    // From center, check to see if the tetrimino can branch out
    // into its shape. If it can, return true, otherwise return false.
    return true;
}
