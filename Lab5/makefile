#Name: Sharon
#Project: Lab5

#This is a Makefile for my lab5 assignment. 

EXECUTABLES=a.out
SRC=lab5.c
OBJ=lab5.o 

CC=gcc
CFLAGS=-g

all:$(EXECUTABLES)

$(EXECUTABLES): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -Wall -Wextra
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -f $(EXECUTABLES) $(OBJ) *~