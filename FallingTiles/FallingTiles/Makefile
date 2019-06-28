fallingtiles : main.o Tetrimino.o Board.o Point.o PointCollection.o
	g++ -o fallingtiles main.o Tetrimino.o Board.o Point.o PointCollection.o

main.o : main.cpp Tetrimino.hpp Board.hpp
	g++ -c main.cpp

Tetrimino.o : Tetrimino.cpp Tetrimino.hpp
	g++ -c Tetrimino.cpp

Board.o : Board.cpp Board.hpp Tetrimino.hpp
	g++ -c Board.cpp

Point.o : Point.cpp Point.hpp
	g++ -c Point.cpp

PointCollection.o : PointCollection.cpp PointCollection.hpp Point.hpp
	g++ -c PointCollection.cpp

clean :
	rm *.o
