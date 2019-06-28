#include <iostream>
#include <iomanip>
#include "Tetrimino.hpp"
#include "Point.hpp"

void init_tet_print(char type)
{
   Tetrimino t = Tetrimino(type);
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
}

int main()
{
    char types[7] = { 'i', 'j', 'l', 'o', 's', 't', 'z' };
    for (int i = 0; i < 7; i++) {
        init_tet_print(types[i]);
        std::cout << std::endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
