#Name: Sharon
#Project: Lab6

#This is a Makefile for my lab6 assignment. 

EXECUTABLES=
SRC=lab6.c
OBJ=lab6.o 

CC=gcc
CFLAGS=-g

all:$(EXECUTABLES)

$(EXECUTABLES): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -Wall -Wextra
	$(CC) $(CFLAGS) -o $@ $(OBJ)

spiritd:

moles:

clean:
	rm -f $(EXECUTABLES) $(OBJ) *~