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
#include "containers/containers.h"
#include <iostream>
#include <assert.h>
#include <stdlib.h>

using namespace std;

void start_test(const char *);
void end_test(void);
int testnr = 0;


/*	containers/Note.cpp	*/
void test_Note_to_int(void);
void test_Note_from_int(void);
void test_Note_octave_up(void);
void test_Note_octave_down(void);
void test_Note_augment(void);
void test_Note_diminish(void);


/*	containers/NoteContainer.cpp	*/
void test_NoteContainer_empty(void);
void test_NoteContainer_add_note(void);
void test_NoteContainer_add_notes(void);
void test_NoteContainer_augment(void);
void test_NoteContainer_diminish(void);


/*	containers/Bar.cpp	*/
void test_Bar_empty(void);
void test_Bar_set_meter(void);
void test_Bar_place_notes(void);


/*	containers/Track.cpp	*/
void test_Track_empty(void);


int 
main(int argc, char **charv) {
	if (argc == 2)
		testnr = atoi(charv[1]);
	printf("==========================================================\n\n");
	printf("                    CMINGUS.CONTAINERS                    \n\n");
	printf("==========================================================\n");
	printf("cmingus_containers 0.1 - Unit Tests\n");
	printf("Copyright(C) 2009, Bart Spaans <bartspaans@gmail.com>\n");
	printf("This program is free software and licensed under the GPLv3\n");
	printf("Compiled on %s, %s\n", __TIME__, __DATE__);
	printf("==========================================================\n");
	printf("                          NOTE                            \n");
	printf("==========================================================\n");
	test_Note_to_int();
	test_Note_from_int();
	test_Note_octave_up();
	test_Note_octave_down();
	test_Note_augment();
	test_Note_diminish();
	printf("==========================================================\n");
	printf("                      NOTECONTAINER                       \n");
	printf("==========================================================\n");
	test_NoteContainer_empty();
	test_NoteContainer_add_note();
	test_NoteContainer_add_notes();
	test_NoteContainer_augment();
	test_NoteContainer_diminish();
	printf("==========================================================\n");
	printf("                           BAR                            \n");
	printf("==========================================================\n");
	test_Bar_empty();
	test_Bar_set_meter();
	test_Bar_place_notes();
	printf("==========================================================\n");
	printf("                          TRACK                           \n");
	printf("==========================================================\n");
	test_Track_empty();
	printf("==========================================================\n");
	printf("  Succesfully completed %d tests.\n", testnr);
	return testnr;
}

void 
start_test(const char* testname)
{
	cout << testnr << ". Testing " << testname << "...";
	testnr++;
}

void 
end_test()
{
	cout << "OK\n";
}

void 
test_Note_to_int() 
{
	Note n;

	start_test("Note::to_int");
	assert(n.to_int() == 48);
	end_test();
}

void
test_Note_from_int()
{
	Note n, o;
	o.from_int(60);

	start_test("Note::from_int");
	assert(o.octave == n.octave + 1);
	assert(o.name.basename == n.name.basename);
	end_test();
}


void 
test_Note_octave_up() 
{
	Note n;
	n.octave_up();

	start_test("Note::octave_up");
	assert(n.octave == 5);
	assert(n.to_int() == 60);
	end_test();
}


void 
test_Note_octave_down() 
{
	Note n;
	n.octave_down();

	start_test("Note::octave_down");
	assert(n.to_int() == 36);
	end_test();
}


void 
test_Note_augment() 
{
	Note n;
	n.augment();

	start_test("Note::augment");
	assert(n.to_int() == 49);
	end_test();
}


void 
test_Note_diminish() 
{
	Note n;
	n.diminish();

	start_test("Note::diminish");
	assert(n.to_int() == 47);
	end_test();
}


void
test_NoteContainer_empty()
{
	NoteContainer n;
	vector<Note> vn;
	vn.push_back(Note((char *) "E"));
	vn.push_back(Note((char *) "F"));
	n.add_notes(vn);

	n.empty();
	start_test("NoteContainer::empty");
	assert(n.notes.size() == 0);
	end_test();
}


void 
test_NoteContainer_add_note()
{
	NoteContainer n;

	n.add_note((char *)"C");
	n.add_note((char *)"E", 7);
	n.add_note((char *)"G", 6);

	
	start_test("NoteContainer::add_note");
	assert(n.notes[0] == Note((char *)"C", 4));
	assert(n.notes[1] == Note((char *) "E", 7));
	assert(n.notes[2] == Note((char *) "G", 6));
	end_test();
}


void 
test_NoteContainer_add_notes()
{
	NoteContainer n;
	vector<Note> vn;
	vn.push_back(Note((char *) "E"));
	vn.push_back(Note((char *) "F"));
	n.add_notes(vn);
	
	start_test("NoteContainer::add_notes");

	assert(n.notes[0] == Note((char *)"E"));
	assert(n.notes[1] == Note((char *) "F"));
	end_test();
}


void
test_NoteContainer_augment()
{
	NoteContainer n;
	n.add_note((char *)"C");
	n.add_note((char *)"E");
	n.augment();
	start_test("NoteContainer::augment");
	assert(n.notes[0] == Note((char *)"C#"));
	assert(n.notes[1] == Note((char *)"E#"));
	end_test();
}


void
test_NoteContainer_diminish()
{
	NoteContainer n;
	n.add_note((char *)"C");
	n.add_note((char *)"E");
	n.diminish();
	start_test("NoteContainer::diminish");
	assert(n.notes[0] == Note("Cb"));
	assert(n.notes[1] == Note("Eb"));
	end_test();
}


void
test_Bar_empty()
{
	Bar b;
	b.empty();
	start_test("Bar::empty");
	assert(b.bar.size() == 0);
	end_test();
}


void
test_Bar_set_meter()
{
	Bar b(NOTE((char *)"C"), cut_time);
	meter res;

	start_test("Bar::set_meter");
	b.get_meter(res);
	assert(res[0] == 2);
	assert(res[1] == 2);
	end_test();
}


void
test_Bar_place_notes()
{
	Bar b;

	start_test("Bar::place_notes");
	assert(b.place_notes(NoteContainer(), 4));
	assert(b.place_notes(NoteContainer(), 4));
	assert(b.place_notes(NoteContainer(), 4));
	assert(b.place_notes(NoteContainer(), 4));
	assert(!b.place_notes(NoteContainer(), 4));
	end_test();
}


void
test_Track_empty()
{
	Track t;
	t.empty();
	start_test("Track::empty");
	assert(t.bars.size() == 0);
	end_test();

}
