#Name: Sharon
#Project: Lab6

#This is a Makefile for my lab6 assignment. 

EXECUTABLES1=spiritd
EXECUTABLES2=moles

SRC1=spiritd.c
SRC2= moles.c

OBJ1=spiritd.o 
OBJ2=moles.o

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

spiritd:$(EXECUTABLES1)

$(EXECUTABLES1): $(SRC1)
	$(CC) $(CFLAGS) -c $(SRC1) -Wall -Wextra
	$(CC) $(CFLAGS) -o $@ $(OBJ1)

moles:$(EXECUTABLES2)

$(EXECUTABLES2): $(SRC2)
	$(CC) $(CFLAGS) -c $(SRC2) -Wall -Wextra
	$(CC) $(CFLAGS) -o $@ $(OBJ2)

clean:
	rm -f $(EXECUTABLES1) $(OBJ1) *~
	rm -f $(EXECUTABLES2) $(OBJ2) *~