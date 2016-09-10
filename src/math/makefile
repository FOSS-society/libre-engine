
CC = g++
CFLAGS = -std=c++11 -Wall -Werror -pedantic-error -lm

SOURCES = $(wildcard *.c)

all: math
	mkdir ../../bin/math
	cp *.o ../../bin/math/

math: $(SOURCES)
	$(CC) -o $@ $^ $(CFLAGS)
