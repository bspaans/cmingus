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
#include "diatonic.h"


void
get_notes(note key, note* result)
{
	int i, fi = fifths_index(key.basename);
	char nametmp[2];
	note tmp;

	if (fi != 0)
	{
		for (i = 0; i < 7; i++) 
		{
			nametmp[0] = fifths[i];
			nametmp[1] = '\0';
			tmp = NOTE(nametmp);
			tmp.accidentals = key.accidentals;
			if (i < fi - 1) 
				tmp.accidentals += 1;
			result[i] = tmp;
		}
	}
	else 
	{
		result[6] = NOTE("Bb");
		result[6].accidentals += key.accidentals;
		for (i = 0; i < 6; i++) 
		{
			nametmp[0] = fifths[i];
			nametmp[1] = '\0';
			tmp = NOTE(nametmp);
			tmp.accidentals = key.accidentals;
			result[i] = tmp;
		}
	}

	sort_notes(result, 7);
	put_tonic_first(result, 7, key);
}


void
get_notes_from_str(char *key, note *result) 
{
	return get_notes(NOTE(key), result);
}


void 
put_tonic_first(note *notes, int size, note n)
{
	int i, r = -1, a= 0;
	note tmp[7];

	for (i = 0; i < size; i++) 
	{
		if (equals(notes[i], n))
		{
			r = i;
			break;
		}
	}
	if (r == -1) 
		return;

	for(i = r; i < size; i++)
		tmp[a++] = notes[i];
	for(i = 0; i < r; i++)
		tmp[a++] = notes[i];
	
	for (i = 0; i < size; i++) 
		notes[i] = tmp[i];

}



note
int_to_diatonic_note(int n, note key)
{
	int i, current = note_to_int(key);
	int intervals[] = { 0, 2, 4, 5, 7, 9, 11 };
	int known_intervals[7];
	note known_notes[7];
	note res;
	res.basename = 'N';
	res.accidentals = 0;


	if (n < 0 || n > 11)
		return res;

	for (i = 0; i < 7; i++)
		known_intervals[i] = (intervals[i] + current) % 12;

	get_notes(key, known_notes);

	i = int_index( n, known_intervals, 7);
	if ( i != -1 )
		return known_notes[i];

	i = int_index( n - 1, known_intervals, 7);
	if ( i != -1 )
	{
		res = known_notes[i];
		res.accidentals += 1;
		return res;
	}	
	i = int_index( n + 1, known_intervals, 7);
	if ( i != -1 )
	{
		res = known_notes[i];
		res.accidentals -= 1;
	}
	return res;
}

int
int_index(int n, int *a, int size)
{
	int i;
	for (i = 0; i < size; i++)
		if (n == a[i])
			return i;
	return -1;
}


note
diatonic_interval(note key, note on_note, int interval)
{
	note keynotes[7];
	int i, index = -1;

	get_notes(key, keynotes);

	for (i = 0; i < 7; i++)
	{
		if (keynotes[i].basename == on_note.basename)
			index = i;
	}
	return keynotes[ (index + interval) % 7 ];
}
