#include "intervals.h"
#include <string.h>
#include <stdlib.h>

extern int note_to_int(char *);
extern int fifths_index(char);
extern int get_accidentals_value(char *);

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
	"perfect",
	"augmented",
	};

int 
expected_semitones[] = {0, 7, 2, 9, 4, 11, 5};


int 
measure(char * note1, char * note2) 
{
	int result;
	result = note_to_int(note2) - note_to_int(note1);
	if (result < 0)
		return 12 - result * -1;
	return result;
}


interval 
determine_interval(char * note1, char * note2) 
{

	int f1, f2, fifth_steps, semitones, expected_steps;
	interval result;

	// unison sidecase
	if (note1 == note2) 
	{
		result.shorthand = 0;
		f1 = get_accidentals_value(note1);
		f2 = get_accidentals_value(note2);
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


	f1 = fifths_index(note1[0]);
	f2 = fifths_index(note2[0]);

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
