#Name: Sharon
#Project: Lab7

#This is a Makefile for my lab7 assignment. 

EXECUTABLES1=matrix_gen
EXECUTABLES2=matrix_add

SRC1=matrix_gen.c
SRC2=matrix_add.c

OBJ1=matrix_gen.o 
OBJ2=matrix_add.o

CC=gcc
CFLAGS=-g

all:$(EXECUTABLES1)

$(EXECUTABLES1): $(SRC1)
	$(CC) $(CFLAGS) -c $(SRC1) -Wall -Wextra
	$(CC) $(CFLAGS) -o $@ $(OBJ1)

	$(EXECUTABLES2)

$(EXECUTABLES2): $(SRC2)
	$(CC) $(CFLAGS) -c $(SRC2) -Wall -Wextra
	$(CC) $(CFLAGS) -o $@ $(OBJ2)

matrix_gen:$(EXECUTABLES1)

$(EXECUTABLES1): $(SRC1)
	$(CC) $(CFLAGS) -c $(SRC1) -Wall -Wextra
	$(CC) $(CFLAGS) -o $@ $(OBJ1)

matrix_add:$(EXECUTABLES2)

$(EXECUTABLES2): $(SRC2)
	$(CC) $(CFLAGS) -c $(SRC2) -Wall -Wextra
	$(CC) $(CFLAGS) -o $@ $(OBJ2)

clean:
	rm -f $(EXECUTABLES1) $(OBJ1) *~
	rm -f $(EXECUTABLES2) $(OBJ2) *~