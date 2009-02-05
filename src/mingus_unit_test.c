/*

================================================================================
    
    cmingus, a reimplementation of mingus in C.
    Copyright (C) 2008-2009, Bart Spaans <bartspaans@gmail.com>

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
#include "core/notes.h"
#include "core/diatonic.h"
#include "core/intervals.h"
#include "core/chords.h"
#include "core/progressions.h"

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
void test_second(void);
void test_third(void);
void test_fifth(void);
void test_major_second(void);
void test_perfect_fourth(void);
void test_minor_sixth(void);
void test_minor_seventh(void);


/* 	core/chords.c		*/
void test_triad(void);
void test_seventh_chord(void);
void test_major_triad(void);
void test_minor_triad(void);
void test_diminished_triad(void);
void test_augmented_triad(void);
void test_major_seventh_chord(void);
void test_minor_seventh_chord(void);
void test_dominanth_seventh_chord(void);
void test_half_diminished_seventh_chord(void);
void test_diminished_seventh_chord(void);
void test_minor_major_seventh_chord(void);
void test_I(void);
void test_II(void);
void test_III(void);
void test_IV(void);
void test_V(void);
void test_VI(void);
void test_VII(void);
void test_II7(void);
void test_V7(void);
void test_VII7(void);
void test_chord_suffix_to_string(void);
void test_chord_to_string(void);
void test_determine_triad(void);

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
	test_second();
	test_third();
	test_fifth();
	test_major_second();
	test_perfect_fourth();
	test_minor_sixth();
	test_minor_seventh();
	printf("==========================================================\n");
	printf("                          CHORDS                          \n");
	printf("==========================================================\n");
	test_triad();
	test_seventh_chord();
	test_major_triad();
	test_minor_triad();
	test_diminished_triad();
	test_augmented_triad();
	test_major_seventh_chord();
	test_minor_seventh_chord();
	test_dominanth_seventh_chord();
	test_half_diminished_seventh_chord();
	test_diminished_seventh_chord();
	test_minor_major_seventh_chord();
	test_I();
	test_II();
	test_III();
	test_IV();
	test_V();
	test_VI();
	test_VII();
	test_II7();
	test_V7();
	test_VII7();
	test_chord_suffix_to_string();
	test_chord_to_string();
	test_determine_triad();
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
	assert(get_accidentals_value("Cbb") == -2);
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
	char *cases[] = { "F", "F#", "C", "G", "Eb"};
	char *answers[5][7] = { 
		{"F", "G", "A", "Bb", "C", "D", "E"},
		{"F#", "G#", "A#", "B", "C#", "D#", "E#"},
		{"C", "D", "E", "F", "G", "A", "B"},
		{"G", "A", "B", "C", "D", "E", "F#"},
		{"Eb", "F", "G", "Ab", "Bb", "C", "D"}
	};

	start_test("get_notes");
	for (i = 0; i < 5; i ++)
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


void
test_second()
{

	char result[12];
	char *notes[] = {"C", "E", "F", "G", "A#" };
	char *answers[] = {"D", "F", "G", "A", "B" };
	int i;

	start_test("second");
	for (i = 0; i < 5; i ++)
	{
		note_to_str(second(NOTE(notes[i]), NOTE("C")), result);
		assert(strcmp(result, answers[i]) == 0);
	}
	end_test();


}


void
test_third()
{

	char result[12];
	char *notes[] = {"C", "E", "F", "G", "A#" };
	char *answers[] = {"E", "G", "A", "B", "C" };
	int i;

	start_test("third");
	for (i = 0; i < 5; i ++)
	{
		note_to_str(third(NOTE(notes[i]), NOTE("C")), result);
		assert(strcmp(result, answers[i]) == 0);
	}
	end_test();


}


void
test_fifth()
{

	char result[12];
	char *notes[] = {"C", "E", "F", "G", "A#", "B" };
	char *answers[] = {"G", "B", "C", "D", "E", "F" };
	int i;

	start_test("fifth");
	for (i = 0; i < 6; i ++)
	{
		note_to_str(fifth(NOTE(notes[i]), NOTE("C")), result);
		assert(strcmp(result, answers[i]) == 0);
	}
	end_test();


}


void
test_major_second()
{

	char result[12];
	char *notes[] = {"C", "E", "F", "G", "A#" };
	char *answers[] = {"D", "F#", "G", "A", "B#" };
	int i;

	start_test("major_second");
	for (i = 0; i < 5; i ++)
	{
		note_to_str(major_second(NOTE(notes[i])), result);
		assert(strcmp(result, answers[i]) == 0);
	}
	end_test();


}


void
test_perfect_fourth()
{

	char result[12];
	char *notes[] = {"C", "E", "F", "G", "A#", "B", "F#", };
	char *answers[] = {"F", "A", "Bb", "C", "D#", "E", "B" };
	int i;

	start_test("perfect_fourth");
	for (i = 0; i < 7; i ++)
	{
		note_to_str(perfect_fourth(NOTE(notes[i])), result);
		assert(strcmp(result, answers[i]) == 0);
	}
	end_test();


}


void
test_minor_sixth()
{

	char result[12];
	char *notes[] = {"C", "E", "F", "G", "A#" };
	char *answers[] = {"Ab", "C", "Db", "Eb", "F#" };
	int i;

	start_test("minor_sixth");
	for (i = 0; i < 5; i ++)
	{
		note_to_str(minor_sixth(NOTE(notes[i])), result);
		assert(strcmp(result, answers[i]) == 0);
	}
	end_test();
}


void
test_minor_seventh()
{

	char result[12];
	char *notes[] = {"C", "E", "F", "G", "A#" };
	char *answers[] = {"Bb", "D", "Eb", "F", "G#" };
	int i;

	start_test("minor_seventh");
	for (i = 0; i < 5; i ++)
	{
		note_to_str(minor_seventh(NOTE(notes[i])), result);
		assert(strcmp(result, answers[i]) == 0);
	}
	end_test();
}


void
test_triad()
{
	char *result[7][3] = { 
		{ "C", "E", "G" },
		{ "D", "F", "A" },
		{ "E", "G", "B" },
		{ "F", "A", "C" },
		{ "G", "B", "D" },
		{ "A", "C", "E" },
		{ "B", "D", "F" }
		};
	note tri[3];
	note res[3];

	int i;
	start_test("triad");
	for (i = 0; i < 7; i ++)
	{
		tri[0] = NOTE(result[i][0]);
		tri[1] = NOTE(result[i][1]);
		tri[2] = NOTE(result[i][2]);
		triad(NOTE(result[i][0]), NOTE("C"), res);
		assert(equal_notes(res, tri, 3));
	}
	end_test();
}


void
test_major_triad()
{
	char *result[7][3] = { 
		{ "C", "E", "G" },
		{ "D", "F#", "A" },
		{ "E", "G#", "B" },
		{ "F", "A", "C" },
		{ "G", "B", "D" },
		{ "A", "C#", "E" },
		{ "B", "D#", "F#" }
		};
	note tri[3];
	note res[3];

	int i;
	start_test("major_triad");
	for (i = 0; i < 7; i ++)
	{
		tri[0] = NOTE(result[i][0]);
		tri[1] = NOTE(result[i][1]);
		tri[2] = NOTE(result[i][2]);
		major_triad(NOTE(result[i][0]), res);
		assert(equal_notes(res, tri, 3));
	}
	end_test();
}


void
test_minor_triad()
{
	char *result[7][3] = { 
		{ "C", "Eb", "G" },
		{ "D", "F", "A" },
		{ "E", "G", "B" },
		{ "F", "Ab", "C" },
		{ "G", "Bb", "D" },
		{ "A", "C", "E" },
		{ "B", "D", "F#" }
		};
	note tri[3];
	note res[3];

	int i;
	start_test("minor_triad");
	for (i = 0; i < 7; i ++)
	{
		tri[0] = NOTE(result[i][0]);
		tri[1] = NOTE(result[i][1]);
		tri[2] = NOTE(result[i][2]);
		minor_triad(NOTE(result[i][0]), res);
		assert(equal_notes(res, tri, 3));
	}
	end_test();
}



void
test_diminished_triad()
{
	char *result[7][3] = { 
		{ "C", "Eb", "Gb" },
		{ "D", "F", "Ab" },
		{ "E", "G", "Bb" },
		{ "F", "Ab", "Cb" },
		{ "G", "Bb", "Db" },
		{ "A", "C", "Eb" },
		{ "B", "D", "F" }
		};
	note tri[3];
	note res[3];

	int i;
	start_test("diminished_triad");
	for (i = 0; i < 7; i ++)
	{
		tri[0] = NOTE(result[i][0]);
		tri[1] = NOTE(result[i][1]);
		tri[2] = NOTE(result[i][2]);
		diminished_triad(NOTE(result[i][0]), res);
		assert(equal_notes(res, tri, 3));
	}
	end_test();
}


void
test_I()
{
	char *result[7][3] = { 
		{ "C", "E", "G" },
		{ "D", "F#", "A" },
		{ "E", "G#", "B" },
		{ "F", "A", "C" },
		{ "G", "B", "D" },
		{ "A", "C#", "E" },
		{ "B", "D#", "F#" }
		};
	note tri[3];
	note res[3];

	int i;
	start_test("I");
	for (i = 0; i < 7; i ++)
	{
		tri[0] = NOTE(result[i][0]);
		tri[1] = NOTE(result[i][1]);
		tri[2] = NOTE(result[i][2]);
		I(NOTE(result[i][0]), res);
		assert(equal_notes(res, tri, 3));
	}
	end_test();
}


void
test_II()
{
	char *result[7][3] = { 
		{ "C", "Eb", "G" },
		{ "D", "F", "A" },
		{ "E", "G", "B" },
		{ "F", "Ab", "C" },
		{ "G", "Bb", "D" },
		{ "A", "C", "E" },
		{ "B", "D", "F#" }
		};
	note tri[3];
	note res[3];

	int i;
	start_test("II");
	for (i = 0; i < 7; i ++)
	{
		tri[0] = NOTE(result[i][0]);
		tri[1] = NOTE(result[i][1]);
		tri[2] = NOTE(result[i][2]);
		II(minor_seventh(NOTE(result[i][0])), res);
		assert(equal_notes(res, tri, 3));
	}
	end_test();
}


void
test_III()
{
	char *result[7][3] = { 
		{ "C", "Eb", "G" },
		{ "D", "F", "A" },
		{ "E", "G", "B" },
		{ "F", "Ab", "C" },
		{ "G", "Bb", "D" },
		{ "A", "C", "E" },
		{ "B", "D", "F#" }
		};
	note tri[3];
	note res[3];

	int i;
	start_test("III");
	for (i = 0; i < 7; i ++)
	{
		tri[0] = NOTE(result[i][0]);
		tri[1] = NOTE(result[i][1]);
		tri[2] = NOTE(result[i][2]);
		III(minor_sixth(NOTE(result[i][0])), res);
		assert(equal_notes(res, tri, 3));
	}
	end_test();
}


void
test_IV()
{
	char *result[7][3] = { 
		{ "C", "E", "G" },
		{ "D", "F#", "A" },
		{ "E", "G#", "B" },
		{ "F", "A", "C" },
		{ "G", "B", "D" },
		{ "A", "C#", "E" },
		{ "B", "D#", "F#" }
		};
	note tri[3];
	note res[3];

	int i;
	start_test("IV");
	for (i = 0; i < 7; i ++)
	{
		tri[0] = NOTE(result[i][0]);
		tri[1] = NOTE(result[i][1]);
		tri[2] = NOTE(result[i][2]);
		IV(perfect_fifth(NOTE(result[i][0])), res);
		assert(equal_notes(res, tri, 3));
	}
	end_test();
}

void
test_V()
{
	char *result[7][3] = { 
		{ "C", "E", "G" },
		{ "D", "F#", "A" },
		{ "E", "G#", "B" },
		{ "F", "A", "C" },
		{ "G", "B", "D" },
		{ "A", "C#", "E" },
		{ "B", "D#", "F#" }
		};
	note tri[3];
	note res[3];

	int i;
	start_test("V");
	for (i = 0; i < 7; i ++)
	{
		tri[0] = NOTE(result[i][0]);
		tri[1] = NOTE(result[i][1]);
		tri[2] = NOTE(result[i][2]);
		V(perfect_fourth(NOTE(result[i][0])), res);
		assert(equal_notes(res, tri, 3));
	}
	end_test();
}

void
test_VI()
{
	char *result[7][3] = { 
		{ "C", "Eb", "G" },
		{ "D", "F", "A" },
		{ "E", "G", "B" },
		{ "F", "Ab", "C" },
		{ "G", "Bb", "D" },
		{ "A", "C", "E" },
		{ "B", "D", "F#" }
		};
	note tri[3];
	note res[3];

	int i;
	start_test("VI");
	for (i = 0; i < 7; i ++)
	{
		tri[0] = NOTE(result[i][0]);
		tri[1] = NOTE(result[i][1]);
		tri[2] = NOTE(result[i][2]);
		VI(minor_third(NOTE(result[i][0])), res);
		assert(equal_notes(res, tri, 3));
	}
	end_test();
}

void
test_VII()
{
	char *result[7][3] = { 
		{ "C", "Eb", "Gb" },
		{ "D", "F", "Ab" },
		{ "E", "G", "Bb" },
		{ "F", "Ab", "Cb" },
		{ "G", "Bb", "Db" },
		{ "A", "C", "Eb" },
		{ "B", "D", "F" }
		};
	note tri[3];
	note res[3];

	int i;
	start_test("VII");
	for (i = 0; i < 7; i ++)
	{
		tri[0] = NOTE(result[i][0]);
		tri[1] = NOTE(result[i][1]);
		tri[2] = NOTE(result[i][2]);
		VII(minor_second(NOTE(result[i][0])), res);
		assert(equal_notes(res, tri, 3));
	}
	end_test();
}
void
test_augmented_triad()
{
	char *result[7][3] = { 
		{ "C", "E", "G#" },
		{ "D", "F#", "A#" },
		{ "E", "G#", "B#" },
		{ "F", "A", "C#" },
		{ "G", "B", "D#" },
		{ "A", "C#", "E#" },
		{ "B", "D#", "F##" }
		};
	note tri[3];
	note res[3];

	int i;
	start_test("augmented_triad");
	for (i = 0; i < 7; i ++)
	{
		tri[0] = NOTE(result[i][0]);
		tri[1] = NOTE(result[i][1]);
		tri[2] = NOTE(result[i][2]);
		augmented_triad(NOTE(result[i][0]), res);
		assert(equal_notes(res, tri, 3));
	}
	end_test();
}


void 
test_seventh_chord()
{
	char *result[7][4] = { 
		{ "C", "E", "G", "B" },
		{ "D", "F", "A", "C" },
		{ "E", "G", "B", "D" },
		{ "F", "A", "C", "E" },
		{ "G", "B", "D", "F" },
		{ "A", "C", "E", "G" },
		{ "B", "D", "F", "A" }
		};
	note sev[4];
	note res[4];

	int i;
	start_test("seventh_chord");
	for (i = 0; i < 7; i ++)
	{
		sev[0] = NOTE(result[i][0]);
		sev[1] = NOTE(result[i][1]);
		sev[2] = NOTE(result[i][2]);
		sev[3] = NOTE(result[i][3]);
		seventh_chord(NOTE(result[i][0]), NOTE("C"), res);
		assert(equal_notes(res, sev, 4));
	}
	end_test();
}


void 
test_major_seventh_chord()
{
	char *result[7][4] = { 
		{ "C", "E", "G", "B" },
		{ "D", "F#", "A", "C#" },
		{ "E", "G#", "B", "D#" },
		{ "F", "A", "C", "E" },
		{ "G", "B", "D", "F#" },
		{ "A", "C#", "E", "G#" },
		{ "B", "D#", "F#", "A#" }
		};
	note sev[4];
	note res[4];

	int i;
	start_test("major_seventh_chord");
	for (i = 0; i < 7; i ++)
	{
		sev[0] = NOTE(result[i][0]);
		sev[1] = NOTE(result[i][1]);
		sev[2] = NOTE(result[i][2]);
		sev[3] = NOTE(result[i][3]);
		major_seventh_chord(NOTE(result[i][0]), res);
		assert(equal_notes(res, sev, 4));
	}
	end_test();
}


void 
test_minor_seventh_chord()
{
	char *result[7][4] = { 
		{ "C", "Eb", "G", "Bb" },
		{ "D", "F", "A", "C" },
		{ "E", "G", "B", "D" },
		{ "F", "Ab", "C", "Eb" },
		{ "G", "Bb", "D", "F" },
		{ "A", "C", "E", "G" },
		{ "B", "D", "F#", "A" }
		};
	note sev[4];
	note res[4];

	int i;
	start_test("minor_seventh_chord");
	for (i = 0; i < 7; i ++)
	{
		sev[0] = NOTE(result[i][0]);
		sev[1] = NOTE(result[i][1]);
		sev[2] = NOTE(result[i][2]);
		sev[3] = NOTE(result[i][3]);
		minor_seventh_chord(NOTE(result[i][0]), res);
		assert(equal_notes(res, sev, 4));
	}
	end_test();
}


void 
test_dominanth_seventh_chord()
{
	char *result[7][4] = { 
		{ "C", "E", "G", "Bb" },
		{ "D", "F#", "A", "C" },
		{ "E", "G#", "B", "D" },
		{ "F", "A", "C", "Eb" },
		{ "G", "B", "D", "F" },
		{ "A", "C#", "E", "G" },
		{ "B", "D#", "F#", "A" }
		};
	note sev[4];
	note res[4];

	int i;
	start_test("dominanth_seventh_chord");
	for (i = 0; i < 7; i ++)
	{
		sev[0] = NOTE(result[i][0]);
		sev[1] = NOTE(result[i][1]);
		sev[2] = NOTE(result[i][2]);
		sev[3] = NOTE(result[i][3]);
		dominanth_seventh_chord(NOTE(result[i][0]), res);
		assert(equal_notes(res, sev, 4));
	}
	end_test();
}


void 
test_half_diminished_seventh_chord()
{
	char *result[7][4] = { 
		{ "C", "Eb", "Gb", "Bb" },
		{ "D", "F", "Ab", "C" },
		{ "E", "G", "Bb", "D" },
		{ "F", "Ab", "Cb", "Eb" },
		{ "G", "Bb", "Db", "F" },
		{ "A", "C", "Eb", "G" },
		{ "B", "D", "F", "A" }
		};
	note sev[4];
	note res[4];

	int i;
	start_test("half_diminished_seventh_chord");
	for (i = 0; i < 7; i ++)
	{
		sev[0] = NOTE(result[i][0]);
		sev[1] = NOTE(result[i][1]);
		sev[2] = NOTE(result[i][2]);
		sev[3] = NOTE(result[i][3]);
		half_diminished_seventh_chord(NOTE(result[i][0]), res);
		assert(equal_notes(res, sev, 4));
	}
	end_test();
}


void 
test_diminished_seventh_chord()
{
	char *result[7][4] = { 
		{ "C", "Eb", "Gb", "Bbb" },
		{ "D", "F", "Ab", "Cb" },
		{ "E", "G", "Bb", "Db" },
		{ "F", "Ab", "Cb", "Ebb" },
		{ "G", "Bb", "Db", "Fb" },
		{ "A", "C", "Eb", "Gb" },
		{ "B", "D", "F", "Ab" }
		};
	note sev[4];
	note res[4];

	int i;
	start_test("diminished_seventh_chord");
	for (i = 0; i < 7; i ++)
	{
		sev[0] = NOTE(result[i][0]);
		sev[1] = NOTE(result[i][1]);
		sev[2] = NOTE(result[i][2]);
		sev[3] = NOTE(result[i][3]);
		diminished_seventh_chord(NOTE(result[i][0]), res);
		assert(equal_notes(res, sev, 4));
	}
	end_test();
}


void 
test_minor_major_seventh_chord()
{
	char *result[7][4] = { 
		{ "C", "Eb", "G", "B" },
		{ "D", "F", "A", "C#" },
		{ "E", "G", "B", "D#" },
		{ "F", "Ab", "C", "E" },
		{ "G", "Bb", "D", "F#" },
		{ "A", "C", "E", "G#" },
		{ "B", "D", "F#", "A#" }
		};
	note sev[4];
	note res[4];

	int i;
	start_test("minor_major_seventh_chord");
	for (i = 0; i < 7; i ++)
	{
		sev[0] = NOTE(result[i][0]);
		sev[1] = NOTE(result[i][1]);
		sev[2] = NOTE(result[i][2]);
		sev[3] = NOTE(result[i][3]);
		minor_major_seventh_chord(NOTE(result[i][0]), res);
		assert(equal_notes(res, sev, 4));
	}
	end_test();
}


void 
test_II7()
{
	char *result[7][4] = { 
		{ "C", "Eb", "G", "Bb" },
		{ "D", "F", "A", "C" },
		{ "E", "G", "B", "D" },
		{ "F", "Ab", "C", "Eb" },
		{ "G", "Bb", "D", "F" },
		{ "A", "C", "E", "G" },
		{ "B", "D", "F#", "A" }
		};
	note sev[4];
	note res[4];

	int i;
	start_test("II7");
	for (i = 0; i < 7; i ++)
	{
		sev[0] = NOTE(result[i][0]);
		sev[1] = NOTE(result[i][1]);
		sev[2] = NOTE(result[i][2]);
		sev[3] = NOTE(result[i][3]);
		II7(minor_seventh(NOTE(result[i][0])), res);
		assert(equal_notes(res, sev, 4));
	}
	end_test();
}


void 
test_V7()
{
	char *result[7][4] = { 
		{ "C", "E", "G", "Bb" },
		{ "D", "F#", "A", "C" },
		{ "E", "G#", "B", "D" },
		{ "F", "A", "C", "Eb" },
		{ "G", "B", "D", "F" },
		{ "A", "C#", "E", "G" },
		{ "B", "D#", "F#", "A" }
		};
	note sev[4];
	note res[4];

	int i;
	start_test("V7");
	for (i = 0; i < 7; i ++)
	{
		sev[0] = NOTE(result[i][0]);
		sev[1] = NOTE(result[i][1]);
		sev[2] = NOTE(result[i][2]);
		sev[3] = NOTE(result[i][3]);
		V7(perfect_fourth(NOTE(result[i][0])), res);
		assert(equal_notes(res, sev, 4));
	}
	end_test();
}


void 
test_VII7()
{
	char *result[7][4] = { 
		{ "C", "Eb", "Gb", "Bb" },
		{ "D", "F", "Ab", "C" },
		{ "E", "G", "Bb", "D" },
		{ "F", "Ab", "Cb", "Eb" },
		{ "G", "Bb", "Db", "F" },
		{ "A", "C", "Eb", "G" },
		{ "B", "D", "F", "A" }
		};
	note sev[4];
	note res[4];

	int i;
	start_test("VII7");
	for (i = 0; i < 7; i ++)
	{
		sev[0] = NOTE(result[i][0]);
		sev[1] = NOTE(result[i][1]);
		sev[2] = NOTE(result[i][2]);
		sev[3] = NOTE(result[i][3]);
		VII7(minor_second(NOTE(result[i][0])), res);
		assert(equal_notes(res, sev, 4));
	}
	end_test();
}


void 
test_chord_suffix_to_string()
{
	char result[30];
	start_test("chord_suffix_to_string");
	chord_suffix_to_string(MINOR_TRIAD, result, 0);
	assert(strcmp(result, "minor triad") == 0);
	chord_suffix_to_string(MINOR_TRIAD, result, 1);
	assert(strcmp(result, "m") == 0);
	end_test();

}

void
test_chord_to_string()
{
	chord c;
	char result[30];
	c.base = NOTE("C#");
	c.suffix = AUGMENTED_TRIAD;
	start_test("chord_to_string");
	chord_to_string(c, result, 0);
	assert(strcmp(result, "C# augmented triad") == 0);
	chord_to_string(c, result, 1);
	assert(strcmp(result, "C#aug") == 0);
	end_test();
}


void
test_determine_triad()
{
	char *cases[12][3] = {
		{"C", "E", "G"},
		{"A", "C", "E"},
		{"D", "E", "A"},
		{"B", "D", "F"},
		{"F", "A", "C#"},
		{"Eb", "G", "Bbb"},
		{"C", "Eb", "B"},
		{"C", "Eb", "Bb"},
		{"C", "E", "Bb"},
		{"C", "E", "B"},
		{"C", "E", "A"},
		{"C", "Eb", "A"},
		};
	char *answers[] = {
		"C major triad",
		"A minor triad",
		"D suspended second triad",
		"B diminished triad",
		"F augmented triad",
		"Eb dominant flat five",
		"C minor/major seventh",
		"C minor seventh",
		"C dominant seventh",
		"C major seventh",
		"C major sixth",
		"C minor sixth",
		};

	int i;
	note notes[3];
	char res[20];

	start_test("determine_triad");
	for (i = 0; i < 12; i++) 
	{
		notes[0] = NOTE(cases[i][0]);
		notes[1] = NOTE(cases[i][1]);
		notes[2] = NOTE(cases[i][2]);

		chord_to_string(determine_triad(notes), res, 0);
		assert(strcmp(res, answers[i]) == 0);
	}
	end_test();

}
