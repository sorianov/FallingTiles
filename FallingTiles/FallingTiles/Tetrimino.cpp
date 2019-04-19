#include "Tetrimino.h"

Tetrimino::Tetrimino(char type) {
	this->tetrimino = new int[MAX_ROWS * MAX_COLS];

	this->setTetrimino(type);
}

Tetrimino::Tetrimino() {
	this->tetrimino = new int[MAX_ROWS * MAX_COLS];

	this->setTetrimino('i');
}

void Tetrimino::rotateLeft() {
  int maxRowsIndex = MAX_ROWS - 1;
  int currRow = 0;
  int currCol = 0;
  int currIndex = 0;
  int newRow = 0;
  int newCol = 0;
  int newIndex = 0;
  int *rotateTetrimino = new int[MAX_ROWS * MAX_COLS];
  
  for (int i = 0; i < MAX_ROWS; i++) {
    for (int j = 0; j < MAX_COLS; j++) {
      currRow = i * MAX_ROWS;
      currCol = j;
      currIndex = currRow + currCol;

      newCol = i;
      newRow = maxRowsIndex - j;
      newIndex = newRow * MAX_ROWS + newCol;
      
      rotateTetrimino[newIndex] = this->tetrimino[currIndex];
    }
  }
  delete [] this->tetrimino;
  this->tetrimino = rotateTetrimino;
	return;
}

void Tetrimino::rotateRight() {
  int maxRowsIndex = MAX_ROWS - 1;
  int currRow = 0;
  int currCol = 0;
  int currIndex = 0;
  int newRow = 0;
  int newCol = 0;
  int newIndex = 0;
  int *rotateTetrimino = new int[MAX_ROWS * MAX_COLS];
  
  for (int i = 0; i < MAX_ROWS; i++) {
    for (int j = 0; j < MAX_COLS; j++) {
      currRow = i * MAX_ROWS;
      currCol = j;
      currIndex = currRow + currCol;
      
      newCol = maxRowsIndex - i;  
      newRow = j;
      newIndex = newRow * MAX_ROWS + newCol;
      
      rotateTetrimino[newIndex] = this->tetrimino[currIndex];
    }
  }
  
  delete [] this->tetrimino;
  this->tetrimino = rotateTetrimino;
	return;
}

void Tetrimino::setTetrimino(char type) {
	int arr[MAX_ROWS][MAX_COLS] = { 0 };
	switch (type) {
	case  'i':
		arr[2][0] = 1;
		arr[2][1] = 1;
		arr[2][2] = 1;
		arr[2][3] = 1;
		break;
	case 'j':
		arr[1][1] = 1;
		arr[2][1] = 1;
		arr[2][2] = 1;
		arr[2][3] = 1;
		break;
	case 'l':
		arr[1][2] = 1;
		arr[2][0] = 1;
		arr[2][1] = 1;
		arr[2][2] = 1;
		break;
	case 'o':
		arr[1][1] = 1;
		arr[1][2] = 1;
		arr[2][1] = 1;
		arr[2][2] = 1;
		break;
	case 's':
		arr[1][1] = 1;
		arr[1][2] = 1;
		arr[2][0] = 1;
		arr[2][1] = 1;
		break;
	case 't':
		arr[1][1] = 1;
		arr[2][0] = 1;
		arr[2][1] = 1;
		arr[2][2] = 1;
		break;
	case 'z':
		arr[1][0] = 1;
		arr[1][1] = 1;
		arr[2][1] = 1;
		arr[2][2] = 1;
		break;
	}
	this->initializeTetrimino(arr);
	return;
}
void Tetrimino::initializeTetrimino(int arr[][MAX_COLS]) {
	for (int i = 0; i < MAX_ROWS; i++) {
		for (int j = 0; j < MAX_COLS; j++) {
			this->tetrimino[i * MAX_COLS + j] = arr[i][j];
		}
	}
	return;
}

Tetrimino::~Tetrimino() {
	delete[] this->tetrimino;
	this->tetrimino = nullptr;
}

void Tetrimino::printTetrimino() {
	for (int i = 0; i < MAX_COLS; i++) {
		for (int j = 0; j < MAX_COLS; j++) {
			std::cout << this->tetrimino[i * MAX_COLS + j] << ", ";
		}
		std::cout << std::endl;
	}
}
