fallingtiles : main.o Tetrimino.o Board.o
	g++ -o fallingtiles main.o Tetrimino.o Board.o

main.o : main.cpp Tetrimino.hpp Board.hpp
	g++ -c main.cpp

Tetrimino.o : Tetrimino.cpp Tetrimino.hpp
	g++ -c Tetrimino.cpp
Board.o : Board.cpp Board.hpp Tetrimino.hpp
	g++ -c Board.cpp
