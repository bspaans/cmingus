extern "C" 
{
	#include "../core/notes.h"
};
#include "Note.h"
#include <iostream>
using namespace std;

Note::Note() 
{
	octave = 4;
	name = NOTE((char *)"C");
}

Note::Note(note n) 
{
	octave = 4;
	name = n;
}

Note::Note(note n, int octave) 
{
	octave = octave;
	name = n;
}

void Note::augment() 
{
	name = augment_note(name);
}

void Note::diminish()
{
	name = diminish_note(name);
}

void Note::octave_up()
{
	octave++;
}

void Note::octave_down()
{
	octave--;
	octave = (octave < 0) ? 0 : octave;
}

void Note::from_int(int i)
{
	name = int_to_note(i % 12);
	octave = i / 12;
}

int Note::to_int() 
{
	note tmp;
	tmp.basename = name.basename;
	tmp.accidentals = 0;
	int result = note_to_int(tmp);
	return 12 * octave + result + name.accidentals;
}
