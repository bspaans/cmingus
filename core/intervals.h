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

#include "notes.h"

note second(note, note);
note third(note, note);
note fourth(note, note);
note fifth(note, note);
note sixth(note, note);
note seventh(note, note);

extern char * interval_names[];
extern char interval_names_shorthand[];
extern char * prefix_names[];
extern int expected_semitones[];

#define DIMINISHED 0
#define MINOR 1
#define MAJOR 2
#define AUGMENTED 3

typedef struct interval {
	char shorthand;
	char prefix;
	signed short accidentals;
} interval;

int measure(note, note);
interval determine_interval(note, note);
interval determine_interval_str(char *, char *);
void interval_to_string(interval, char *);

#define INTERVAL(str1, str2) (determine_interval_str(str1, str2))
