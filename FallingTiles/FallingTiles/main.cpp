#include <iostream>
#include "Tetrimino.hpp"
#include "Board.hpp"

void print_tet_init(char type)
{
    Tetrimino t = Tetrimino(type);
    std::cout << type << ": " << std::endl;
    t.printTetrimino();
    t.rotateRight();
    std::cout << std::endl;
    t.printTetrimino();
    t.rotateRight();
    std::cout << std::endl;
    t.printTetrimino();
    t.rotateRight();
    std::cout << std::endl;
    t.printTetrimino();
    t.rotateRight();
    std::cout << std::endl;
}

int main()
{
    char types[7] = { 'i', 'j', 'l', 'o', 's', 't', 'z' };
    for (int i = 0; i < 7; i++) {
        print_tet_init(types[i]);
        std::cout << std::endl;
    }

    Board b = Board();

    b.printBoard();

    return 0;
}
