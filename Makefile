SRCS=./core/*.c ./mingus.c
OBJ=core/notes.o core/intervals.o core/diatonic.o
LIBS=

default: 
	$(CC) $(SRCS) $(LIBS) -o mingus

static: $(OBJ)
	$(AR) rcs libmingus.a $(OBJ)
	rm $(OBJ)

