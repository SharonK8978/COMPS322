#Name: Sharon
#Project: Lab3

#This is a Makefile for my lab3 assignment. 

EXECUTABLES=catcher
SRC=lab3.c
OBJ=lab3.o 

CC=gcc
CFLAGS=-g

all:$(EXECUTABLES)

$(EXECUTABLES): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -Wall -Wextra
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -f $(EXECUTABLES) $(OBJ) *~