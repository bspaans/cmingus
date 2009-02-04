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
