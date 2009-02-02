#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "core/intervals.h"
#include "core/notes.h"

/* 	core/notes.c	 	*/
void test_get_accidentals_value(void);
void test_note_to_int(void);
void test_int_to_note(void);
void test_augment(void);
void test_diminish(void);

/* 	core/intervals.c	*/
void test_determine_interval(void);
void test_interval_to_string(void);


void start_test(char *);
void end_test(void);

int testnr = 0;

int 
main() 
{
	printf("==========================================================\n");
	printf("                         CMINGUS                          \n");
	printf("==========================================================\n");
	printf("cmingus_core 0.1 - Unit Tests\n");
	printf("Copyright(C) 2009, Bart Spaans <bartspaans@gmail.com>\n");
	printf("This program is free software and licensed under the GPLv3\n");
	printf("Compiled on %s, %s\n", __TIME__, __DATE__);
	printf("==========================================================\n");
	printf("                          NOTES                           \n");
	printf("==========================================================\n");
	test_get_accidentals_value();
	test_augment();
	test_diminish();
	test_note_to_int();
	test_int_to_note();
	printf("==========================================================\n");
	printf("                         INTERVAL                         \n");
	printf("==========================================================\n");
	test_determine_interval();
	test_interval_to_string();
	printf("==========================================================\n");
	return 0;
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
test_get_accidentals_value()
{
	start_test("get_accidentals_value");
	assert(get_accidentals_value("C###") == 3);
	assert(get_accidentals_value("C###bb") == 1);
	assert(get_accidentals_value("Cb#b#######") == 6);
	assert(get_accidentals_value("C######b####b##b###") == 12);
	end_test();
}

void
test_augment()
{
	int i;
	char result[12];
	char *cases[] = {"C", "Db", "C##", "C#b", "C###"};
	char *answers[] = {"C#", "D", "C###", "C#", "C####"};
	
	start_test("test_augment");
	for (i = 0; i < 5; i++) 
	{
		augment(cases[i], result);
		assert(strcmp(result, answers[i]) == 0);
	}
	end_test();
}

void
test_diminish()
{
	int i;
	char result[12];
	char *cases[] = {"C", "Db", "C##", "Cb#", "C###"};
	char *answers[] = {"Cb", "Dbb", "C#", "Cb", "C##"};
	
	start_test("test_diminish");
	for (i = 0; i < 5; i++) 
	{
		diminish(cases[i], result);
		assert(strcmp(result, answers[i]) == 0);
	}
	end_test();
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
test_int_to_note()
{
	char result[2];
	char *notes[] = {"C", "C#", "D", "D#", "E", "F"};
	unsigned int x;

	start_test("int_to_note");
	for (x = 0; x < 6; x++) 
	{
		int_to_note(x, result);
		assert(strcmp(notes[x], result) == 0);
	}
	end_test();
}

void 
test_determine_interval() 
{

	interval c = determine_interval("C", "E");
	
	start_test("determine_interval");
	assert(c.prefix == MAJOR);
	assert(interval_names_shorthand[(int) c.shorthand] - '0' == 3);
	end_test();
}

void
test_interval_to_string()
{
	interval c = determine_interval("C", "E");
	char result[100];

	start_test("interval_to_string");
	interval_to_string(c, result);
	assert(strcmp(result, "major third") == 0);
	end_test();

}
