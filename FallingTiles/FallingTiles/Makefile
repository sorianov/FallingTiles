fallingtiles : main.o Tetrimino.o Board.o Point.o PointGrid.o
	g++ -o fallingtiles main.o Tetrimino.o Board.o Point.o PointGrid.o

main.o : main.cpp Tetrimino.hpp Board.hpp
	g++ -c -ggdb main.cpp

Tetrimino.o : Tetrimino.cpp Tetrimino.hpp
	g++ -c -ggdb Tetrimino.cpp

Board.o : Board.cpp Board.hpp Tetrimino.hpp
	g++ -c -ggdb Board.cpp

Point.o : Point.cpp Point.hpp
	g++ -c -ggdb Point.cpp

PointGrid.o : PointGrid.cpp PointGrid.hpp Point.hpp
	g++ -c -ggdb PointGrid.cpp

clean :
	rm *.o
