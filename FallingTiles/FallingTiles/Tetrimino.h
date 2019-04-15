#ifndef TETRIMINO_H
#define TETRIMINO_H
#endif

#include <iostream>
#include <cmath>

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
	void setTetrimino(char type);
	void initializeTetrimino(int arr[][MAX_COLS]);
  int wrapIndex(int index, int steps, int maxRows, int maxCols);
	int* tetrimino;

};
