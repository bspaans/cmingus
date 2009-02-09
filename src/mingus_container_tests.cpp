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


/*	containers/NoteContainer.cpp	*/
void test_NoteContainer_empty(void);
void test_NoteContainer_add_note(void);
void test_NoteContainer_add_notes(void);


/*	containers/Bar.cpp	*/
void test_Bar_empty(void);


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
	printf("==========================================================\n");
	printf("                      NOTECONTAINER                       \n");
	printf("==========================================================\n");
	test_NoteContainer_empty();
	test_NoteContainer_add_note();
	test_NoteContainer_add_notes();
	printf("==========================================================\n");
	printf("                           BAR                            \n");
	printf("==========================================================\n");
	test_Bar_empty();
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
	assert(n.notes[0].name.basename == 'C');
	assert(n.notes[1].name.basename == 'E');
	assert(n.notes[2].name.basename == 'G');
	assert(n.notes[0].octave == 4);
	assert(n.notes[1].octave == 7);
	assert(n.notes[2].octave == 6);
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

	assert(n.notes[0].name.basename == 'E');
	assert(n.notes[1].name.basename == 'F');
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
test_Track_empty()
{
	Track t;
	t.empty();
	start_test("Track::empty");
	assert(t.bars.size() == 0);
	end_test();

}
