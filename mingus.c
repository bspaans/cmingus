#include <stdio.h>
#include <assert.h>
#define INTERVALS
#include "core/intervals.h"

void test_determine_interval(void);
void test_note_to_int(void);
void start_test(char *);
void end_test(void);


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
	printf("Testing %s...", test);
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
	assert(note_to_int("D") == 2);
	assert(note_to_int("E") == 4);
	assert(note_to_int("F") == 5);
	assert(note_to_int("G") == 7);
	assert(note_to_int("A") == 9);
	assert(note_to_int("B") == 11);
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

