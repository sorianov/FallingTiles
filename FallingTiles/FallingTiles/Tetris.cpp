#include "Tetrimino.h"
#include "Board.h"

int main() {
  /*
	char types[7] = { 'i', 'j', 'l', 'o', 's', 't', 'z' };
	for (int i = 0; i < 7; i++) {
		Tetrimino* t = new Tetrimino(types[i]);
		t->printTetrimino();
		delete t;
		std::cout << std::endl;
	}
  */
	Tetrimino *t = new Tetrimino('z');
    Board *b = new Board();

    std::cout << "Board printed: " << std::endl;
    b->printBoard();
    std::cout << std::endl;

    /*
    std::cout << "Rotate Left:" << std::endl;
	t->printTetrimino();
    std::cout << std::endl;
    t->rotateLeft();
    t->printTetrimino();
    std::cout << std::endl;
    t->rotateLeft();
    t->printTetrimino();
    std::cout << std::endl;
    t->rotateLeft();
    t->printTetrimino();
    std::cout << std::endl;
    
    std::cout << std::endl;
    
    std::cout << "Rotate Right:" << std::endl;
	t->printTetrimino();
    std::cout << std::endl;
    t->rotateRight();
    t->printTetrimino();
    std::cout << std::endl;
    t->rotateRight();
    t->printTetrimino();
    std::cout << std::endl;
    t->rotateRight();
    t->printTetrimino();
    std::cout << std::endl;
    */

	return 0;
}
