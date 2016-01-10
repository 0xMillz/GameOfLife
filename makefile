#Author: Mills McIlroy
#Date: 10/6/2015
#Description: This is my makefile for Game of Life

all: play

play: main.o Cell.o GameOfLife.o
	g++ main.o Cell.o GameOfLife.o -o play

main.o: main.cpp
	g++ -c main.cpp

Cell.o: Cell.cpp
	g++ -c Cell.cpp

GameOfLife: GameOfLife.cpp
	g++ -c GameOfLife.cpp

clean:
	rm *o play