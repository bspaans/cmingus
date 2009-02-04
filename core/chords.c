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
seventh_chord(note on_note, note key, note *result)
{
	triad(on_note, key, result);
	result[3] = seventh(on_note, key);
}

