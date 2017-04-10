

all: test


test: main.o
	g++ main.o -o Test  -llibre-engine -lSDL2 -lGLEW -lSDL2_image -lGL

main.o: main.cpp
	g++ -c main.cpp -g -std=c++11 -Wall -Werror -pedantic-errors
