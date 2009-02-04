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

#define unison(n, key) (n)
#define second(n, key) (diatonic_interval(key, n, 1))
#define third(n, key) (diatonic_interval(key, n, 2))
#define fourth(n, key) (diatonic_interval(key, n, 3))
#define fifth(n, key) (diatonic_interval(key, n, 4))
#define sixth(n, key) (diatonic_interval(key, n, 5))
#define seventh(n, key) (diatonic_interval(key, n, 6))

#define major_second(n) (second(n, n))
#define major_third(n) (third(n, n))
#define major_fourth(n) (fourth(n, n))
#define perfect_fourth(n) (fourth(n, n))
#define major_fifth(n) (fifth(n, n))
#define perfect_fifth(n) (fifth(n, n))
#define major_sixth(n) (sixth(n, n))
#define major_seventh(n) (seventh(n, n))

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
