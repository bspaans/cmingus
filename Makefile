SRCS=./core/*.c ./mingus.c
OBJ=core/notes.o core/intervals.o core/diatonic.o
OPTS=-Wall -O3
LIBS=

default: 
	$(CC) $(SRCS) $(OPTS) $(LIBS) -o mingus

static: $(OBJ)
	$(AR) rcs libmingus.a $(OBJ)
	rm $(OBJ)

