# a simple makefile for running all the necessary c++ files and clearing .o files

CC=g++

CFLAGS=-Wall

all: program run clean

program: 
	$(CC) $(CFLAGS) main.cpp heap.h heap.cpp -o main.out

run: 
	./main.out

clean:
	rm -rf main.out
	rm -rf *.o
