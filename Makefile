SRCS=./core/*.c ./mingus.c
OBJ=core/notes.o core/intervals.o core/diatonic.o
LIBS=
CC=gcc

default: 
	$(CC) $(INCS) $(LIBS) -o mingus

static: $(OBJ)
	ar rcs libmingus.a $(OBJ)
	rm $(OBJ)

