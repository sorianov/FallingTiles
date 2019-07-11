#include <iostream>
#include "Tetrimino.hpp"
#include "PointGrid.hpp"
#include "Point.hpp"

/**
 * Parameterized Constructor to specify shape of Tetrimino.
 */
Tetrimino::Tetrimino(char type) 
{
    tetrimino = PointGrid(MAX_ROWS, MAX_COLS, MAX_POINTS);
    setTetrimino(type);
}

/**
 * Default Constructor. Sets Tetrimino to 'i' shape.
 */
Tetrimino::Tetrimino() 
{
    tetrimino = PointGrid(MAX_ROWS, MAX_COLS, MAX_POINTS);
    setTetrimino('i');
}

/** 
 * Rotates tetrimino left by calling the private rotate function
 *
 * @see rotate(char direction)
 *
 * @return void
 */
void Tetrimino::rotateLeft() 
{
    tetrimino.rotatePointsLeft();
    return;
}


/** 
 * Rotates tetrimino right by calling the private rotate function
 *
 * @see rotate(char direction)
 *
 * @return void
 */
void Tetrimino::rotateRight()
{
    tetrimino.rotatePointsRight();
    return;
}

/**
 * Creates a two dimensional array initialized to 0. Assigns specific
 * coordinates to 1 in order to set the desired Tetrimino shape. Then calls
 * setTetriminoValues with the created array as a parameter in order to
 * initialize the tetrimino pointer. Initialization order matters if you care
 * what the 'center' is.
 *
 * @param char type The tetrimino shape. Should be one of the following:
 *                  i,j,l,o,s,t,z.
 * @return void
 */
void Tetrimino::setTetrimino(char type)
{

    switch (type) {
    case  'i':
        tetrimino.addPoint(2, 0);
        tetrimino.addPoint(2, 1);
        tetrimino.addPoint(2, 2);
        tetrimino.addPoint(2, 3);
        break;
    case 'j':
        tetrimino.addPoint(1, 1);
        tetrimino.addPoint(2, 1);
        tetrimino.addPoint(2, 2);
        tetrimino.addPoint(2, 3);
        break;
    case 'l':
        tetrimino.addPoint(1, 2);
        tetrimino.addPoint(2, 0);
        tetrimino.addPoint(2, 1);
        tetrimino.addPoint(2, 2);
        break;
    case 'o':
        tetrimino.addPoint(1, 1);
        tetrimino.addPoint(1, 2);
        tetrimino.addPoint(2, 1);
        tetrimino.addPoint(2, 2);
        break;
    case 's':
        tetrimino.addPoint(1, 1);
        tetrimino.addPoint(1, 2);
        tetrimino.addPoint(2, 1);
        tetrimino.addPoint(2, 0);
        break;
    case 't':
        tetrimino.addPoint(1, 1);
        tetrimino.addPoint(2, 0);
        tetrimino.addPoint(2, 1);
        tetrimino.addPoint(2, 2);
        break;
    case 'z':
        tetrimino.addPoint(1, 0);
        tetrimino.addPoint(1, 1);
        tetrimino.addPoint(2, 1);
        tetrimino.addPoint(2, 2);
        break;
    default:
        setTetrimino('i');
        break;
    }
    return;
}

/**
 * Iterates over the tetrimino pointer and outputs values to console window.
 *
 * @return void
 */
void Tetrimino::printTetrimino() 
{
    tetrimino.printGrid();

    return;
}
