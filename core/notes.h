int note_to_int(char *);
char * int_to_note(int);

int is_enharmonic(char *, char *);
int is_valid_note(char *);
int note_name_index(char);
int fifths_index(char);
int get_accidentals_value(char *);

char *remove_redundant_accidentals(char *);
void augment(char *, char *);
void diminish(char *, char *);
char *to_major(char *);
char *to_minor(char *);

#ifndef _NOTES_H_
#define _NOTES_H_
char note_names[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G'};
int note_values[] = {  9,   11,  0,   2,   4,   5 ,  7 };

char fifths[] = { 'F', 'C', 'G', 'D', 'A', 'E', 'B'};
char * naive_note_list[] = { "C", "C#", "D", "D#", "E", "F", 
	                     "F#", "G", "G#", "A", "A#", "B"}; 

#endif
