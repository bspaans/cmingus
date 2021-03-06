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


#include "notes.h"
#include <string.h>
#include <stdlib.h>

void quick_sort(note *, int, int);
int partition(note *, int, int);

char note_names[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
int note_values[] = {  9,   11,  0,   2,   4,   5 ,  7 };

char fifths[] = { 'F', 'C', 'G', 'D', 'A', 'E', 'B'};
char *naive_note_list[] = { "C", "C#", "D", "D#", "E", "F", 
	                     "F#", "G", "G#", "A", "A#", "B"}; 


int 
is_valid_note_str(char *n) 
{
	int i, len = strlen(n);

	// check notename
	if (note_name_index(n[0]) == -1)
		return 0;	
	
	// check accidentals
	for (i = 1; i < len; i++) 
		if (n[i] != '#' && n[i] != 'b')
			return 0;

	return 1;
}


note
str_to_note(char *n)
{
	note res;
	res.basename = 'N';
	res.accidentals = 0;
	if (is_valid_note_str(n))
	{
		res.basename = n[0];
		res.accidentals = get_accidentals_value(n);
		return res;
	}
	return res;
}


void
note_to_str(note n, char *res) {
	int i;
	res[0] = n.basename;
	res[1] = '\0';
	for (i = 0; i < abs(n.accidentals); i++) 
	{
		if (n.accidentals < 0)
			res[i + 1] = 'b';
		else
			res[i + 1] = '#';
		res[i + 2] = '\0';
	}
}



int note_to_int(note n)
{
	int i = note_name_index(n.basename);
	int val1, val2, res;

	//warning: should handle error(?)
	if (i == -1)
		return -1;

	val1 = note_values[i];
	val2 = n.accidentals;

	res = (val1 + val2) % 12;
	if (res >= 0)
		return res;
	
	res = 12 - (abs(val1 + val2) % 12);
	if (res != 12)
		return res;
	return 0;
}


int 
get_accidentals_value(char *note) {
	
	int i, val = 0;
	for (i = 1; i < strlen(note); i++) {
		switch (note[i]) {
			case 'b':
				val--;
				break;
			case '#':
				val++;
				break;
			default:
				return -10000;
		}
	}
	return val;
}


note 
int_to_note(int n)
{
	char *tmp;
	note res;
	tmp = naive_note_list[n % 12];
	res.basename = tmp[0];
	res.accidentals = get_accidentals_value(tmp);
	return res;
}


int 
fifths_index(char notename) 
{
	int i;
	for (i = 0; i < 7; i++)
		if (fifths[i] == notename)
			return i;
	return -1;
}


note
augment_note(note n)
{
	n.accidentals += 1;
	return n;
}


note
diminish_note(note n)
{
	n.accidentals -= 1;
	return n;
}


void
sort_notes(note *a, int size)
{
	quick_sort(a, 0, size - 1);
}


void
quick_sort(note *a, int l, int r)
{
	if (l >= r)
		return;

	int j;
	j = partition(a, l, r);
	quick_sort(a, l, j - 1);
	quick_sort(a, j + 1, r);
}


int
partition(note *a, int l, int r)
{
	int pivot, i, j;
	note tmp;
	pivot = note_to_int(a[l]);
	i = l; j = r + 1;

	while ( 1) 
	{
		do ++i; while (note_to_int(a[i]) <= pivot && i <= r);
		do --j; while (note_to_int(a[j]) > pivot);
		if (i >= j) break;
		tmp = a[i]; a[i] = a[j]; a[j] = tmp;
	}
	tmp = a[l]; a[l] = a[j]; a[j] = tmp;
	return j;

}

inline int
note_index (note n, note *notes, int size)
{
	while ( size-- > 1 && !equals(n, notes[size]));
	return ( size == 0 ) ? -1: size;
}

inline int
equal_notes(note *n1, note *n2, int compare)
{
	while(compare-- > 1 && equals(n1[compare], n2[compare]));
	return compare == 0;
}
