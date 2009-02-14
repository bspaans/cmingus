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
#include "midi/midi.h"
#include <iostream>
#include <assert.h>
#include <stdlib.h>

using namespace std;

void start_test(const char *);
void end_test(void);
int testnr = 0;
Synth synth;

void test_FluidSynth_init(void);
void test_FluidSynth_play_Note(void);
void test_FluidSynth_play_NoteContainer(void);
void test_FluidSynth_play_Bar(void);


int 
main(int argc, char **charv) {
	if (argc == 2)
		testnr = atoi(charv[1]);
	printf("==========================================================\n\n");
	printf("                       CMINGUS.MIDI                       \n\n");
	printf("==========================================================\n");
	printf("cmingus_midi 0.1 - Unit Tests\n");
	printf("Copyright(C) 2009, Bart Spaans <bartspaans@gmail.com>\n");
	printf("This program is free software and licensed under the GPLv3\n");
	printf("Compiled on %s, %s\n", __TIME__, __DATE__);
	printf("==========================================================\n");
	printf("                        FLUIDSYNTH\n");
	printf("==========================================================\n");
	test_FluidSynth_init();
	test_FluidSynth_play_Note();
	test_FluidSynth_play_NoteContainer();
	test_FluidSynth_play_Bar();
	printf("==========================================================\n");
	printf("  Succesfully completed %d tests.\n", testnr);
	printf("==========================================================\n");
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
test_FluidSynth_init()
{
	start_test("init");
	synth.init((char *) "", (char *)"/home/bspaans/workspace/fluidsynth/ChoriumRevA.SF2");
	end_test();
}


void
test_FluidSynth_play_Note()
{
	Note n((char *) "C");
	Note n2((char *) "E");

	start_test("play_Note");
	synth.set_instrument(1, 30);
	synth.set_instrument(2, 2);
	synth.set_instrument(0, 1);
	synth.play_Note(n, 1, 100);
	synth.play_Note(n2, 2, 100);
	synth.play_Note(n, 0, 100);
	synth.sleep(250);
	synth.stop_Note(n, 1);
	synth.stop_Note(n2, 2);
	synth.stop_Note(n, 0);
	end_test();
}

void
test_FluidSynth_play_NoteContainer()
{
	NoteContainer n;
	n.add_note((char *)"A");
	n.add_note((char *)"C");
	n.add_note((char *)"F");
	start_test("play_NoteContainer");
	synth.play_NoteContainer(n, 1, 100);
	synth.sleep(250);
	synth.stop_NoteContainer(n, 1);
	end_test();
}


void
test_FluidSynth_play_Bar()
{
	Bar b;
	NoteContainer n;
	n.add_note((char *)"C");
	n.add_note((char *)"E");
	n.add_note((char *)"G");
	b.place_notes(n, 4);
	b.place_notes(n, 4);
	b.place_notes(n, 2);
	start_test("play_Bar");
	synth.play_Bar(b, 1, 120);
	end_test();
}
