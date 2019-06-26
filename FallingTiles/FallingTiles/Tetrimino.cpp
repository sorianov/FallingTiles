#include "Tetrimino.hpp"
/**
 * Parameterized Constructor to specify shape of Tetrimino.
 */
Tetrimino::Tetrimino(char type) 
{
    this->tetrimino = new int[MAX_ROWS * MAX_COLS];
    this->p1 = Point();
    this->p2 = Point();
    this->center = Point();
    this->p3 = Point();

    this->setTetrimino(type);
}

/**
 * Default Constructor. Sets Tetrimino to 'i' shape.
 */
Tetrimino::Tetrimino() 
{
    this->tetrimino = new int[MAX_ROWS * MAX_COLS];
    this->p1 = Point();
    this->p2 = Point();
    this->center = Point();
    this->p3 = Point();


    this->setTetrimino('i');
}

/**
 * Destructor
 */
Tetrimino::~Tetrimino() 
{
    delete[] this->tetrimino;
    this->tetrimino = nullptr;
}

/**
 * Tetrimino rotation function. Will rotate left or right depending on
 * character passed as paramter. We create a new array pointer, take rows from
 * existing tetrimino pointer and assign them to new rows on the newly
 * allocated array. Then we delete the existing tetrimino memory and point to
 * the new, rotated one.
 *
 * @visibility private
 *
 * @param char direction The direction to rotate. Should be either 'r' or 'l'.
 *
 * @return void
 */
void Tetrimino::rotate(char direction)
{
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
            currRow = i * MAX_COLS;
            currCol = j;
            currIndex = currRow + currCol;
            
            if (direction == 'l') {
                newCol = i;
                newRow = maxRowsIndex - j;
            } 
            
            if (direction == 'r') {
                newCol = maxRowsIndex - i;  
                newRow = j;
            }
            
            newIndex = newRow * MAX_ROWS + newCol;
            rotateTetrimino[newIndex] = this->tetrimino[currIndex];
        }
    }
    delete [] this->tetrimino;
    this->tetrimino = rotateTetrimino;
    return;
    
}

void Tetrimino::printPointsInfo()
{
    int x = 0;
    int y = 0;
    Point pointsArray[4] = { this->p1, this->p2, this->center, this->p3 };
    for (int i = 0; i < 4; i++) {
        x = pointsArray[i].getX();
        y = pointsArray[i].getY();
        std::cout << "Point info for: " << i << "\t " << x << ", " << y << std::endl;
    }

}

void Tetrimino::rotatePoints(char direction)
{
    int x = 0;
    int y = 0;
    int newX = 0;
    int newY = 0;
    Point pointsArray[4] = { this->p1, this->p2, this->center, this->p3 };
    if (direction == 'l') {
        x = this->p1.getX();
        y = this->p1.getY();
        newX = (MAX_ROWS - 1) - y;
        newY = x;
        this->p1.setXY(newX, newY);
       
        x = this->p2.getX();
        y = this->p2.getY();
        newX = (MAX_ROWS - 1) - y;
        newY = x;
        this->p2.setXY(newX, newY);
       
        x = this->center.getX();
        y = this->center.getY();
        newX = (MAX_ROWS - 1) - y;
        newY = x;
        this->center.setXY(newX, newY);

        x = this->p3.getX();
        y = this->p3.getY();
        newX = (MAX_ROWS - 1) - y;
        newY = x;
        this->p3.setXY(newX, newY);
    }
    
    if (direction == 'r') {
        x = this->p1.getX();
        y = this->p1.getY();
        newX = y;
        newY = (MAX_ROWS - 1) - x;
        this->p1.setXY(newX, newY);

        x = this->p2.getX();
        y = this->p2.getY();
        newX = y;
        newY = (MAX_ROWS - 1) - x;
        this->p2.setXY(newX, newY);

        x = this->center.getX();
        y = this->center.getY();
        newX = y;
        newY = (MAX_ROWS - 1) - x;
        this->center.setXY(newX, newY);

        x = this->p3.getX();
        y = this->p3.getY();
        newX = y;
        newY = (MAX_ROWS - 1) - x;
        this->p3.setXY(newX, newY);

    }
}

void Tetrimino::plotPointsAndPrint()
{
    int x = 0;
    int y = 0;
    int printArr[MAX_ROWS][MAX_COLS] = {0};
    Point pointsArray[4] = { this->p1, this->p2, this->center, this->p3 };
    for (int i = 0; i < 4; i++) {
        x = pointsArray[i].getX();
        y = pointsArray[i].getY();
        printArr[x][y] = 1;
    }
    
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            std::cout << printArr[i][j] << ", ";
        }
        std::cout << std::endl;
    }
}

void Tetrimino::rotatePointsLeft()
{
    this->rotatePoints('l');
}

void Tetrimino::rotatePointsRight()
{
    this->rotatePoints('r');
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
    this->rotate('l');
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
    this->rotate('r');
    return;
}

/**
 * Creates a two dimensional array initialized to 0. Assigns specific
 * coordinates to 1 in order to set the desired Tetrimino shape. Then calls
 * setTetriminoValues with the created array as a parameter in order to
 * initialize the tetrimino pointer.
 *
 * @param char type The tetrimino shape. Should be one of the following:
 *                  i,j,l,o,s,t,z.
 * @return void
 */
void Tetrimino::setTetrimino(char type)
{
    int arr[MAX_ROWS][MAX_COLS] = { 0 };
    switch (type) {
    case  'i':
        arr[2][0] = 1;
        this->p1.setXY(2, 0);
        arr[2][1] = 1;
        this->p2.setXY(2, 1);
        arr[2][2] = 1;
        this->center.setXY(2, 2);
        arr[2][3] = 1;
        this->p3.setXY(2, 3);
        this->printPointsInfo();
        break;
    case 'j':
        arr[1][1] = 1;
        this->p1.setXY(1, 1);
        arr[2][1] = 1;
        this->p2.setXY(2, 1);
        arr[2][2] = 1;
        this->center.setXY(2, 2);
        arr[2][3] = 1;
        this->p3.setXY(2, 3);
        break;
    case 'l':
        arr[1][2] = 1;
        this->p1.setXY(1, 2);
        arr[2][0] = 1;
        this->p2.setXY(2, 0);
        arr[2][1] = 1;
        this->center.setXY(2, 1);
        arr[2][2] = 1;
        this->p3.setXY(2, 2);
        break;
    case 'o':
        arr[1][1] = 1;
        this->p1.setXY(1, 1);
        arr[1][2] = 1;
        this->p2.setXY(1, 2);
        arr[2][1] = 1;
        this->center.setXY(2, 1);
        arr[2][2] = 1;
        this->p3.setXY(2, 2);
        break;
    case 's':
        arr[1][1] = 1;
        this->p1.setXY(1, 1);
        arr[1][2] = 1;
        this->p2.setXY(1, 2);
        arr[2][0] = 1;
        this->center.setXY(2, 0);
        arr[2][1] = 1;
        this->p3.setXY(2, 1);
        break;
    case 't':
        arr[1][1] = 1;
        this->p1.setXY(1, 1);
        arr[2][0] = 1;
        this->p2.setXY(2, 0);
        arr[2][1] = 1;
        this->center.setXY(2, 1);
        arr[2][2] = 1;
        this->p3.setXY(2, 2);
        break;
    case 'z':
        arr[1][0] = 1;
        this->p1.setXY(1, 0);
        arr[1][1] = 1;
        this->p2.setXY(1, 1);
        arr[2][1] = 1;
        this->center.setXY(2, 1);
        arr[2][2] = 1;
        this->p3.setXY(2, 2);
        break;
    }
    this->setTetriminoValues(arr);
    return;
}

/**
 * Iterates over the tetrimino pointer to set it to arr values.
 * 
 * @param int arr The array to take values from
 *
 * @return void
 */
void Tetrimino::setTetriminoValues(int arr[][MAX_COLS])
{
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            this->tetrimino[i * MAX_COLS + j] = arr[i][j];
        }
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
    for (int i = 0; i < MAX_COLS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            std::cout << this->tetrimino[i * MAX_COLS + j] << ", ";
        }
        std::cout << std::endl;
    }
}
