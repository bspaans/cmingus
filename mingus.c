#include <stdio.h>
#include <assert.h>
#define INTERVALS
#include "core/intervals.h"

void test_determine_interval(void);
void test_note_to_int(void);
void start_test(char *);
void end_test(void);

int testnr = 0;

int 
main() 
{
	printf("cmingus 0.1 - Unit Tests\n");
	printf("========================\n");
	test_note_to_int();
	test_determine_interval();
}


void 
start_test(char *test) 
{
	printf("%d. Testing %s...", testnr++, test);
}


void 
end_test() 
{
	printf("OK\n");
}

void 
test_note_to_int() 
{
	start_test("note_to_int");
	assert(note_to_int("C") == 0);
	assert(note_to_int("C##") == 2);
	assert(note_to_int("D") == 2);
	assert(note_to_int("E") == 4);
	assert(note_to_int("F") == 5);
	assert(note_to_int("G") == 7);
	assert(note_to_int("A") == 9);
	assert(note_to_int("A#") == 10);
	assert(note_to_int("Bb") == 10);
	assert(note_to_int("B") == 11);
	assert(note_to_int("Cb") == 11);
	assert(note_to_int("Cbbbb") == 8);
	assert(note_to_int("Cbbbbbbbb") == 4);
	assert(note_to_int("Cbbbbbbbbbbb") == 1);
	assert(note_to_int("Cbbbbbbbbbbbb") == 0);
	assert(note_to_int("Cbbbbbbbbbbbbbbbb") == 8);
	assert(note_to_int("Bbbbbbbbb") == 3);
	end_test();
}

void 
test_determine_interval() 
{

	interval c = determine_interval("C", "E");
	
	start_test("determine_interval");
	assert(c.prefix == MAJOR);
	assert(c.shorthand == 4);
	end_test();
}

