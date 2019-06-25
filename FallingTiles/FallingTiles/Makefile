fallingtiles : main.o Tetrimino.o Board.o
	g++ -o fallingtiles main.o Tetrimino.o Board.o

main.o : main.cpp Tetrimino.h Board.h
	g++ -c main.cpp

Tetrimino.o : Tetrimino.cpp Tetrimino.h
	g++ -c Tetrimino.cpp
Board.o : Board.cpp Board.h Tetrimino.h
	g++ -c Board.cpp
