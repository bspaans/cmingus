#include "notes.h"
#include <string.h>
#include <stdlib.h>


int note_name_index(char note) 
{
	if (note >= 'A' && note <= 'G')
		return note - 'A';
	return -1;
}

int is_valid_note(char * note) 
{
	int i, len = strlen(note);

	// check notename
	if (note_name_index(note[0]) == -1)
		return 0;	
	
	// check accidentals
	for (i = 1; i < len; i++) 
		if (note[i] != '#' && note[i] != 'b')
			return 0;

	return 1;
}

int is_enharmonic(char * note1, char * note2)
{
	return (note_to_int(note1) == note_to_int(note2));
}

int note_to_int(char * note)
{
	int i = note_name_index(note[0]);
	int val1, val2;

	//warning: should handle error(?)
	if (i == -1)
		return -1;

	val1 = note_values[i];
	val2 = get_accidentals_value(note);
	if (val2 == -10000)
		return -1;

	return (val1 + val2) % 12;

}

int get_accidentals_value(char * note) {
	
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

char * int_to_note(int n)
{
	return naive_note_list[n % 12];
}

int fifths_index(char notename) 
{
	int i;
	for (i = 0; i < 7; i++)
		if (fifths[i] == notename)
			return i;
	return -1;
}

void augment(char *note, char *result)
{
	int len = strlen(note);

	if (note[len - 1] != 'b') {
		strcpy(result, note);
		result[len] = '#';
		result[len + 1] = '\0';
	}
	else {
		strcpy(result, note);
		result[len-1] = '\0';
	}
}

void diminish(char *note, char *result)
{
	int len = strlen(note);

	if (note[len - 1] != '#') {
		strcpy(result, note);
		result[len] = 'b';
		result[len + 1] = '\0';
	}
	else {
		strcpy(result, note);
		result[len-1] = '\0';
	}
}


