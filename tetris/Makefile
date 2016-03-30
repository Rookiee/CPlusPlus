CC=g++
CFLAGS= -Wall -std=c++11
PROG = tetris
OBJS = Tetris.o Game.o Figure.o Block.o

LIBS= -lglut -lGLU -lGL

all:$(PROG) 

$(PROG): $(OBJS)
	$(CC) $(CFLAGS) -o $(PROG) $(OBJS) $(LIBS)

Tetris.o: Tetris.cpp
	$(CC) $(CFLAGS) -c Tetris.cpp

Game.o: Game.cpp
	$(CC) $(CFLAGS) -c Game.cpp

Figure.o: Figure.cpp
	$(CC) $(CFLAGS) -c Figure.cpp

Block.o: Block.cpp
	$(CC) $(CFLAGS) -c Block.cpp

clean:
	rm -f $(PROG) $(OBJS)
