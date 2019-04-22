#include "Board.h"

Board::Board() 
{
    this->board = new int[NUM_ROWS * NUM_COLS];
    this->initializeBoard();
}

Board::~Board() 
{
    delete [] this->board;
    this->board = nullptr;
}

void Board::printBoard() 
{
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            std::cout << this->board[i * NUM_COLS + j] << ", ";
        }
        std::cout << std::endl;
    }
}

void Board::initializeBoard() 
{
    int count = 0;
    int index = 0;
    for (int i = 0; i < NUM_ROWS; i++) {
        for (int j = 0; j < NUM_COLS; j++) {
            index = i * NUM_COLS + j;
            this->board[index] = count;
        }
    }
}

bool Board::addTetrimino(Tetrimino *tetrimino, int x, int y)
{
    this->board[x * NUM_COLS + y] = tetrimino->getCenter(); // TODO

    // From center, check to see if the tetrimino can branch out
    // into its shape. If it can, return true, otherwise return false.
