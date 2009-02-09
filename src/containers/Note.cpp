#include "containers.h"

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


Note::Note(note n, int o) 
{
	octave = o;
	name = n;
}

Note::Note(char *n)
{
	name = NOTE(n);
	octave = 4;
}


Note::Note(char *n, int o)
{
	name = NOTE(n);
	octave = o;
}


void 
Note::augment() 
{
	name = augment_note(name);
}


void 
Note::diminish()
{
	name = diminish_note(name);
}


void 
Note::octave_up()
{
	octave++;
}


void 
Note::octave_down()
{
	octave--;
	octave = (octave < 0) ? 0 : octave;
}


void 
Note::from_int(int i)
{
	name = int_to_note(i % 12);
	octave = i / 12;
}


int 
Note::to_int() 
{
	note tmp;
	tmp.basename = name.basename;
	tmp.accidentals = 0;
	return 12 * octave + note_to_int(tmp) + name.accidentals;
}


bool
Note::operator==(Note other)
{
	return other.name.basename == name.basename &&
		other.name.accidentals == name.accidentals &&
		other.octave == octave;
}
