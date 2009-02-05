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
#include "intervals.h"
#include "chords.h"
#include <string.h>

char *chord_suffix_meaning[] = {
		"invalid",

		"minor triad",
		"major triad",
		"diminished triad",
		"augmented triad",

		"suspended second triad",
		"suspended fourth triad",

		"dominant flat five",

	};

char *chord_suffix_shorthand[] = {
		"ERR",
		
		"m",
		"M",
		"dim",
		"aug",
		
		"sus2",
		"sus4",

		"7b5",
	};

void
triad(note on_note, note key, note *result)
{
	result[0] = on_note;
	result[1] = third(on_note, key);
	result[2] = fifth(on_note, key);
}

void 
augmented_triad(note on_note, note *result)
{
	major_triad(on_note, result);
	result[2] = augment(result[2]);
}

void 
seventh_chord(note on_note, note key, note *result)
{
	triad(on_note, key, result);
	result[3] = seventh(on_note, key);
}

void
diminished_seventh_chord(note on_note, note *result)
{
	diminished_triad(on_note, result);
	result[3] = diminish(minor_seventh(on_note));
}


void
minor_major_seventh_chord(note on_note, note *result)
{
	minor_triad(on_note, result);
	result[3] = major_seventh(on_note);

}

void
chord_suffix_to_string(enum chord_suffix suffix, char *result, int shorthand)
{
	if (!shorthand)
		strcpy(result, chord_suffix_meaning[suffix]);
	else
		strcpy(result, chord_suffix_shorthand[suffix]);
}

void
chord_to_string(chord c, char *result, int shorthand)
{
	note_to_str(c.base, result);
	int i = strlen(result);
	if (!shorthand) {
		result[i++] = ' ';
		result[i] = '\0';
	}
	chord_suffix_to_string(c.suffix, result + i, shorthand);
}

void
determine_triad(note *n, chord *results)
{
	interval iv1 = determine_interval(n[0], n[1]);
	interval iv2 = determine_interval(n[0], n[2]);
	int i = 0;
	chord result;

	result.base = NOTE("N");
	result.suffix = INVALID;
	results[i] = result;

	int i1 = interval_names_shorthand[(int) iv1.shorthand] - '0';
	int i2 = interval_names_shorthand[(int) iv2.shorthand] - '0';
	if (i2 == 5) 
	{
		if (iv2.prefix == MAJOR) {
			switch(i1) {
				case(2):
					result.suffix = SUS2;
					break;
				case(3):
					if (iv1.prefix == MINOR)
						result.suffix = MINOR_TRIAD;
					else if (iv1.prefix == MAJOR)
						result.suffix = MAJOR_TRIAD;
					break;
				case(4):
					result.suffix = SUS4;
					break;
			}
		}
		else if (iv2.prefix == MINOR) {
			if (i1 == 3) {
				if (iv1.prefix == MINOR)
					result.suffix = DIMINISHED_TRIAD;
				else if (iv1.prefix == MAJOR)
					result.suffix = DOMINANT_FLAT_FIVE;
			}

		}
		else if (iv2.prefix == AUGMENTED) {
			if (iv1.prefix == MAJOR)
				result.suffix = AUGMENTED_TRIAD;

		}

	}

	if (result.suffix != INVALID) 
	{
		result.base = n[0];
		results[i++] = result;

	}

}
