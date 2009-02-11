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


#define interval_unison(n, key) (n)
#define interval_second(n, key) (diatonic_interval(key, n, 1))
#define interval_third(n, key) (diatonic_interval(key, n, 2))
#define interval_fourth(n, key) (diatonic_interval(key, n, 3))
#define interval_fifth(n, key) (diatonic_interval(key, n, 4))
#define interval_sixth(n, key) (diatonic_interval(key, n, 5))
#define interval_seventh(n, key) (diatonic_interval(key, n, 6))

#define interval_major_second(n) (interval_second(n, n))
#define interval_major_third(n) (interval_third(n, n))
#define interval_major_fourth(n) (interval_fourth(n, n))
#define interval_perfect_fourth(n) (interval_fourth(n, n))
#define interval_major_fifth(n) (interval_fifth(n, n))
#define interval_perfect_fifth(n) (interval_fifth(n, n))
#define interval_major_sixth(n) (interval_sixth(n, n))
#define interval_major_seventh(n) (interval_seventh(n, n))

#define interval_minor_second(n) (diminish_note(interval_second(n, n)))
#define interval_minor_third(n) (diminish_note(interval_third(n, n)))
#define interval_minor_fourth(n) (diminish_note(interval_fourth(n, n)))
#define interval_minor_fifth(n) (diminish_note(interval_fifth(n, n)))
#define interval_minor_sixth(n) (diminish_note(interval_sixth(n, n)))
#define interval_minor_seventh(n) (diminish_note(interval_seventh(n, n)))


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
