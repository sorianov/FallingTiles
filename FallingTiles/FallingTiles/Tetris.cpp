#include "Tetrimino.h"

int main() {
	char types[7] = { 'i', 'j', 'l', 'o', 's', 't', 'z' };
	for (int i = 0; i < 7; i++) {
		Tetrimino* t = new Tetrimino(types[i]);
		t->printTetrimino();
		delete t;
		std::cout << std::endl;
	}
	//Tetrimino t = Tetrimino('z');
	//t.printTetrimino();
	return 0;
}