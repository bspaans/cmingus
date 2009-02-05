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


typedef struct note {
	char basename;
	short accidentals;
} note;

#define NOTE(str) (str_to_note(str))
#define equals(n1, n2) (n1.basename == n2.basename && n1.accidentals == n2.accidentals)
#define note_name_index(n) (((n) >= 'A' && (n) <= 'G') ?  n - 'A' : -1)
#define is_enharmonic(n1, n2) (note_to_int(n1) == note_to_int(n2))

int note_to_int(note);
note int_to_note(int);
note str_to_note(char *);
void note_to_str(note, char *);
void sort_notes(note *, int);
inline int equal_notes(note *, note *, int);
int note_index(note, note*, int);

int is_enharmonic(note, note);
int is_valid_note_str(char *);
int fifths_index(char);
int get_accidentals_value(char *);

note augment(note);
note diminish(note);

extern char note_names[];
extern int note_values[];
extern char fifths[];
extern char *naive_note_list[];


