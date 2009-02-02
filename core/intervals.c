#include "intervals.h"
#include <string.h>
#include <stdlib.h>

extern int note_to_int(char *);
extern int fifths_index(char);
extern int get_accidentals_value(char *);

int measure(char * note1, char * note2) 
{
	int result;
	result = note_to_int(note2) - note_to_int(note1);
	if (result < 0)
		return 12 - result * -1;
	return result;
}

/* This function is 7650% faster than its python equivalent
 * when compiled with -O3 on my machine, doing roughly
 * 4.250.000 interval determinations per second! 
 */
char * determine(char * note1, char * note2, int shorthand) 
{

	int f1, f2, fifth_steps, semitones, expected_steps;
	char * result;

	// unison sidecase
	if (note1 == note2) 
	{
		f1 = get_accidentals_value(note1);
		f2 = get_accidentals_value(note2);

		if (f1 == f2) 
		{
			if (shorthand)
				return "1";
			else
				return "major unison";
		}
		else if (f1 < f2) 
		{
			if (shorthand)
				return "#1";
			else
				return "augmented unison";
		}
		else if (f1 - f2 == 1)
		{
			if (shorthand)
				return "b1";
			else
				return "minor unison";
		}
		else 
		{
			if (shorthand)
				return "bb1";
			else
				return "diminished unison";
		}


	}


	f1 = fifths_index(note1[0]);
	f2 = fifths_index(note2[0]);
	fifth_steps = f2 - f1;

	if (f2 < f1)
		fifth_steps = 7 - f1 + f2;

	expected_steps = expected_semitones[fifth_steps];
	semitones = measure(note1, note2);


	if (expected_steps == semitones) 
	{
		if (shorthand)
		{
			result = (char *) malloc(2);
			result[0] = interval_names_shorthand[fifth_steps];
			result[1] = '\0';
			return result;
		}
		else 
		{
			result = (char *) malloc(strlen(interval_names[fifth_steps]) + 7);
			strcpy(result, "major ");
			strcat(result, interval_names[fifth_steps]);
			return result;
		}
	}
	else if (expected_steps + 1 <= semitones) 
	{
		if (shorthand)
		{
			int sharps = semitones - expected_steps;
			result = (char *) malloc (sharps + 2);

			while (sharps != -1)
			{
				result[sharps] = '#';
				sharps -= 1;
			}
			sharps = semitones - expected_steps;
			result[sharps] = interval_names_shorthand[fifth_steps];
			result[sharps + 1] = '\0';
			return result;
		}
		else 
		{
			result = (char *) malloc(strlen(interval_names[fifth_steps]) + 11);
			strcpy(result, "augmented ");
			strcat(result, interval_names[fifth_steps]);
			return result;
		}


	}
	else if (expected_steps - 1 == semitones) 
	{
		if (shorthand)
		{	
			result = (char *) malloc(3);
			result[0] = 'b';
			result[1] = interval_names_shorthand[fifth_steps];
			result[2] = '\0';
			return result;
		}
		else
		{
			result = (char *) malloc(strlen(interval_names[fifth_steps]) + 7);
			strcpy(result, "minor ");
			strcat(result, interval_names[fifth_steps]);
			return result;
		}
	}
	else if (expected_steps - 2 >= semitones) 
	{
		if (shorthand)
		{
			int flats = expected_steps - semitones;
			result = (char *) malloc (flats + 2);

			while (flats != -1)
			{
				result[flats] = 'b';
				flats -= 1;
			}
			flats = expected_steps - semitones;
			result[flats] = interval_names_shorthand[fifth_steps];
			result[flats + 1] = '\0';
			return result;
		}
		else
		{
			result = (char *) malloc(strlen(interval_names[fifth_steps]) + 13);
			strcpy(result, "diminished ");
			strcat(result, interval_names[fifth_steps]);
			return result;
		}	

	}

}
