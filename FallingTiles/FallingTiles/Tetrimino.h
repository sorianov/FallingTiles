#ifndef TETRIMINO_H
#define TETRIMINO_H
#endif

#include <iostream>

const int MAX_ROWS = 4;
const int MAX_COLS = 4;

class Tetrimino {
public:
	Tetrimino();
	Tetrimino(char type);
	~Tetrimino();
	void rotateLeft();
	void rotateRight();
	void printTetrimino();
private:
    void rotate(char direction);
	void setTetrimino(char type);
	void setTetriminoValues(int arr[][MAX_COLS]);
	int *tetrimino;

};
