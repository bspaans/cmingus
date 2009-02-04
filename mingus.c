/*

================================================================================
    
    cmingus, a reimplementation of mingus in C.
    Copyright (C) 2008, Bart Spaans

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

================================================================================

*/

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "core/intervals.h"
#include "core/diatonic.h"

/* 	core/notes.c	 	*/
void test_get_accidentals_value(void);
void test_str_to_note(void);
void test_note_to_int(void);
void test_int_to_note(void);
void test_augment(void);
void test_diminish(void);

/*	core/diatonic.c		*/
void test_get_notes(void);
void test_int_to_diatonic_note(void);
void test_diatonic_interval(void);

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
	test_str_to_note();
	test_note_to_int();
	test_int_to_note();
	test_augment();
	test_diminish();
	printf("==========================================================\n");
	printf("                         DIATONIC                         \n");
	printf("==========================================================\n");
	test_get_notes();
	test_int_to_diatonic_note();
	test_diatonic_interval();
	printf("==========================================================\n");
	printf("                         INTERVAL                         \n");
	printf("==========================================================\n");
	test_determine_interval();
	test_interval_to_string();
	printf("==========================================================\n");
	printf("  Succesfully completed %d tests.\n", testnr);
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
test_str_to_note()
{
	note n, r;
	n.accidentals = 0;
	n.basename = 'C';
	r = str_to_note("C");

	start_test("str_to_note");
	assert(r.accidentals == n.accidentals);
	assert(r.basename ==  n.basename);
	end_test();
}

void
test_augment()
{
	int i;
	char result[12] = "";
	char *cases[] = {"C", "Db", "C##", "C#b", "C###"};
	char *answers[] = {"C#", "D", "C###", "C#", "C####"};
	note n;
	start_test("augment");
	for (i = 0; i < 5; i++) 
	{
		result[0] = '\0';
		n = str_to_note(cases[i]);
		note_to_str(augment(str_to_note(cases[i])), result);
		assert(strcmp(answers[i], result) == 0);
	}
	end_test();
}

void
test_diminish()
{
	int i;
	char result[12] = "";
	char *cases[] = {"C", "Db", "C##", "Cb#", "C###"};
	char *answers[] = {"Cb", "Dbb", "C#", "Cb", "C##"};
	
	start_test("diminish");
	for (i = 0; i < 5; i++) 
	{
		result[0] = '\0';
		note_to_str(diminish(str_to_note(cases[i])), result);
		assert( strcmp(result, answers[i]) == 0);
	}
	end_test();
}



void 
test_note_to_int() 
{
	start_test("note_to_int");
	assert(note_to_int(str_to_note("C")) == 0);
	assert(note_to_int(str_to_note("C##")) == 2);
	assert(note_to_int(str_to_note("D")) == 2);
	assert(note_to_int(str_to_note("E")) == 4);
	assert(note_to_int(str_to_note("F")) == 5);
	assert(note_to_int(str_to_note("G")) == 7);
	assert(note_to_int(str_to_note("A")) == 9);
	assert(note_to_int(str_to_note("A#")) == 10);
	assert(note_to_int(str_to_note("Bb")) == 10);
	assert(note_to_int(str_to_note("B")) == 11);
	assert(note_to_int(str_to_note("Cb")) == 11);
	assert(note_to_int(str_to_note("Cbbbb")) == 8);
	assert(note_to_int(str_to_note("Cbbbbbbbb")) == 4);
	assert(note_to_int(str_to_note("Cbbbbbbbbbbb")) == 1);
	assert(note_to_int(str_to_note("Cbbbbbbbbbbbb")) == 0);
	assert(note_to_int(str_to_note("Cbbbbbbbbbbbbbbbb")) == 8);
	assert(note_to_int(str_to_note("Bbbbbbbbb")) == 3);
	end_test();
}

void
test_int_to_note()
{
	char result[2] = "" ;
	char *notes[] = {"C", "C#", "D", "D#", "E", "F"};
	unsigned int x;

	start_test("int_to_note");
	for (x = 0; x < 6; x++) 
	{
		result[0] = '\0';
		note_to_str(int_to_note(x), result);
		assert(note_to_int(int_to_note(x)) == x);
		assert(strcmp(notes[x], result) == 0);
	}
	end_test();
}

void 
test_determine_interval() 
{

	interval c = INTERVAL("C", "E");
	
	start_test("determine_interval");
	assert(c.prefix == MAJOR);
	assert(interval_names_shorthand[(int) c.shorthand] - '0' == 3);
	end_test();
}

void
test_interval_to_string()
{
	interval ivals[] = { 
		INTERVAL("C", "E"),
		INTERVAL("C", "D#"),
		INTERVAL("E", "D#"),
		INTERVAL("B", "C"),
		};
	char *answers[] = {
		"major third",
		"augmented second",
		"major seventh",
		"minor second",
		};

	int i;	
	char result[100];

	start_test("interval_to_string");
	for (i = 0; i < 4; i++) {
		interval_to_string(ivals[i], result);
		assert(strcmp(result, answers[i]) == 0);
	}
	end_test();
}

void
test_get_notes()
{
	note result[7];
	char res[12];
	int i, j;
	char *cases[] = { "F", "C", "G", "Eb"};
	char *answers[4][7] = { 
		{"F", "G", "A", "Bb", "C", "D", "E"},
		{"C", "D", "E", "F", "G", "A", "B"},
		{"G", "A", "B", "C", "D", "E", "F#"},
		{"Eb", "F", "G", "Ab", "Bb", "C", "D"}
	};

	start_test("get_notes");
	for (i = 0; i < 4; i ++)
	{
		get_notes(NOTE(cases[i]), result);
		for (j =0; j < 7; j++)
		{
			note_to_str(result[j], res);
			assert(strcmp(res, answers[i][j]) == 0);
		}

	}
	end_test();
}


void
test_int_to_diatonic_note()
{
	note key1 = NOTE("C");
	note key2 = NOTE("F");
	note res1 = NOTE("B");
	note res2 = NOTE("A#");
	note res3 = NOTE("Bb");

	start_test("int_to_diatonic_note");
	assert(equals(int_to_diatonic_note(11, key1), res1));
	assert(equals(int_to_diatonic_note(10, key1), res2));
	assert(equals(int_to_diatonic_note(10, key2), res3));
	end_test();

}


void 
test_diatonic_interval()
{
	char *notes[] = { "C", "D", "E", "F", "G", "A", "B" };
	char result[12];
	int i;

	start_test("diatonic_interval");
	for ( i = 0; i < 7; i++)
	{
		note_to_str(diatonic_interval(NOTE("C"), NOTE("C"), i), result);
		assert(strcmp(result, notes[i]) == 0);
	}
	end_test();
}
