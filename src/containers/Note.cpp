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

int main() {
	char res[20];
	Note n;
	n.augment();
	note_to_str(n.name, res);
	cout << n.octave << '\n';
	cout << res << '\n';
	return 0;
}
