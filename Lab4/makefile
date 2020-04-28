#Name: Sharon
#Project: Lab4

#This is a Makefile for my lab4 assignment. 

EXECUTABLES=dining-p
SRC=lab4.c
OBJ=lab4.o 

CC=gcc
CFLAGS=-g

all:$(EXECUTABLES)

$(EXECUTABLES): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -Wall -Wextra
	$(CC) $(CFLAGS) -o $@ $(OBJ)

dining-p:


clean:
	rm -f $(EXECUTABLES) $(OBJ) *~