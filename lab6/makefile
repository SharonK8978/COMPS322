#Name: Sharon
#Project: Lab6

#This is a Makefile for my lab6 assignment. 

EXECUTABLES=lab6
EXECUTABLES1=spiritd
EXECUTABLES2=moles
SRC=lab6.c
OBJ=lab6.o 

CC=gcc
CFLAGS=-g

all:$(EXECUTABLES)

$(EXECUTABLES): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -Wall -Wextra
	$(CC) $(CFLAGS) -o $@ $(OBJ)

spiritd:$(EXECUTABLES1)

$(EXECUTABLES1): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -Wall -Wextra
	$(CC) $(CFLAGS) -o $@ $(OBJ)

moles:$(EXECUTABLES2)

$(EXECUTABLES2): $(SRC)
	$(CC) $(CFLAGS) -c $(SRC) -Wall -Wextra
	$(CC) $(CFLAGS) -o $@ $(OBJ)

clean:
	rm -f $(EXECUTABLES) $(OBJ) *~