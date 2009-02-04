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
#include "intervals.h"
#include "diatonic.h"
#include <string.h>
#include <stdlib.h>

char * 
interval_names[] = { 
		"unison",
		"fifth",
		"second",
		"sixth",
		"third",
		"seventh",
		"fourth" };


char 
interval_names_shorthand[] = { '1', '5', '2', '6',
				'3', '7', '4' };


char * 
prefix_names[] = { 
	"diminished",
	"minor",
	"major",
	"augmented",
	};

int 
expected_semitones[] = {0, 7, 2, 9, 4, 11, 5};


int 
measure(note note1, note note2) 
{
	int result;
	result = note_to_int(note2) - note_to_int(note1);
	if (result < 0)
		return 12 - result * -1;
	return result;
}


interval
determine_interval_str(char *note1, char *note2)
{
	return determine_interval( 
			str_to_note(note1),
			str_to_note(note2));
}


interval 
determine_interval(note note1, note note2) 
{

	int f1, f2, fifth_steps, semitones, expected_steps;
	interval result;
	result.prefix = 0;
	result.accidentals = 0;

	// unison sidecase
	if (note1.basename == note2.basename) 
	{
		result.shorthand = 1;
		f1 = note1.accidentals;
		f2 = note2.accidentals;
		result.accidentals = f2 - f1;

		if (f1 == f2) 
			result.prefix = MAJOR;
		else if (f1 < f2) 
			result.prefix = AUGMENTED;
		else if (f1 - f2 == 1)
			result.prefix = MINOR;
		else 
			result.prefix = DIMINISHED;

		return result;
	}


	f1 = fifths_index(note1.basename);
	f2 = fifths_index(note2.basename);

	if (f2 < f1)
		fifth_steps = 7 - f1 + f2;
	else
		fifth_steps = f2 - f1;

	expected_steps = expected_semitones[fifth_steps];
	semitones = measure(note1, note2);
	result.shorthand = fifth_steps;
	result.accidentals = semitones - expected_steps;

	if (expected_steps == semitones) 
		result.prefix = MAJOR;
	else if (expected_steps + 1 <= semitones) 
		result.prefix = AUGMENTED;
	else if (expected_steps - 1 == semitones) 
		result.prefix = MINOR;
	else if (expected_steps - 2 >= semitones) 
		result.prefix = MAJOR;
	return result;

}


void 
interval_to_string(interval i, char *result)
{
	strcpy(result, prefix_names[(int) i.prefix]);
	strcat(result, " ");
	strcat(result, interval_names[(int) i.shorthand]);

}
