#Name: Sharon
#Project: Lab2

#This is a Makefile for my lab2 assignment. 

EXECUTABLES1=launch 
EXECUTABLES2=tube
SRC1=launch.c
SRC2=tube.c
OBJ1=launch.o 
OBJ2=tube.o

CC=gcc
CFLAGS=-g

all: launch tube

launch:$(EXECUTABLES1)

$(EXECUTABLES1): $(SRC1)
	$(CC) $(CFLAGS) -c $(SRC1) -Wall -Wextra
	$(CC) $(CFLAGS) -o $@ $(OBJ1)

tube:$(EXECUTABLES2)

$(EXECUTABLES2): $(SRC2)
	$(CC) $(CFLAGS) -c $(SRC2) -Wall -Wextra
	$(CC) $(CFLAGS) -o $@ $(OBJ2)


clean:
	rm -f $(EXECUTABLES1) $(OBJ1) *~
	rm -f $(EXECUTABLES2) $(OBJ2) *~