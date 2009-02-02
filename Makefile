INCS=./core/*.c ./mingus.c
LIBS=
CC=gcc

default: 
	$(CC) $(INCS) $(LIBS) -o mingus
