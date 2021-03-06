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

		"major seventh",
		"minor seventh",
		"dominant seventh",
		"diminished seventh",
		"minor/major seventh",

		"minor sixth",
		"major sixth",

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
		
		"M7",
		"m7",
		"dom7",
		"dim7",
		"m/M7",

		"m6",
		"M6",

		"sus2",
		"sus4",

		"7b5",
	};

void
triad(note on_note, note key, note *result)
{
	result[0] = on_note;
	result[1] = interval_third(on_note, key);
	result[2] = interval_fifth(on_note, key);
}

void 
augmented_triad(note on_note, note *result)
{
	major_triad(on_note, result);
	result[2] = augment_note(result[2]);
}

void 
seventh_chord(note on_note, note key, note *result)
{
	triad(on_note, key, result);
	result[3] = interval_seventh(on_note, key);
}

void
diminished_seventh_chord(note on_note, note *result)
{
	diminished_triad(on_note, result);
	result[3] = diminish_note(interval_minor_seventh(on_note));
}


void
minor_major_seventh_chord(note on_note, note *result)
{
	minor_triad(on_note, result);
	result[3] = interval_major_seventh(on_note);

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


chord 
determine_triad(note *n)
{
	interval iv1 = determine_interval(n[0], n[1]);
	interval iv2 = determine_interval(n[0], n[2]);
	chord result;

	result.base = n[0];
	result.suffix = UNKNOWN;

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
	else if (i1 == 3 && iv1.prefix == MINOR)
	{
		if (i2 == 7)
		{
			if (iv2.prefix == MINOR)
				result.suffix = MINOR_SEVENTH;
			else if (iv2.prefix == MAJOR)
				result.suffix = MINOR_MAJOR_SEVENTH;
		}
		if (i2 == 6 && iv2.prefix == MAJOR)
			result.suffix = MINOR_SIXTH;
	}
	else if (i1 == 3 && iv1.prefix == MAJOR)
	{
		if (i2 == 7)
		{
			if (iv2.prefix == MINOR)
				result.suffix = DOMINANT_SEVENTH;
			else if (iv2.prefix == MAJOR)
				result.suffix = MAJOR_SEVENTH;
		}
		if (i2 == 6 && iv2.prefix == MAJOR)
			result.suffix = MAJOR_SIXTH;
	}
	else if (i1 == 5 && iv1.prefix == MAJOR)
	{
		if (i2 == 7)
		{
			if (iv2.prefix == MINOR)
				result.suffix = MINOR_SEVENTH;
			else if (iv2.prefix == MAJOR)
				result.suffix = MAJOR_SEVENTH;
		}
	}
	return result;
}
