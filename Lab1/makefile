#Name: Sharon
#Project: Lab1

#This is a Makefile for my lab1 assignment. 

EXECUTABLES=time-4-baby-and-me 
SRC=lab1.c
OBJ=lab1.o 

CC=gcc
CFLAGS=-g

all:$(EXECUTABLES)

$(EXECUTABLES): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -Wall -Wextra
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -f $(EXECUTABLES) $(OBJ) *~