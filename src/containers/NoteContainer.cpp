#include <vector>
#include "NoteContainer.h"

NoteContainer::NoteContainer() { }
NoteContainer::NoteContainer(std::vector<Note> n) 
{ 
	notes = n;
}


void
NoteContainer::add_note(Note n)
{
	notes.push_back(n);
}


void
NoteContainer::add_note(note n)
{
	notes.push_back(Note(n));
}


void
NoteContainer::add_note(note n, int octave)
{
	notes.push_back(Note(n, octave));
}


void
NoteContainer::add_note(char *n)
{
	notes.push_back(Note(n));
}


void
NoteContainer::add_note(char *n, int octave)
{
	notes.push_back(Note(n, octave));
}


void
NoteContainer::add_notes(std::vector<Note> n)
{
	std::vector<Note>::iterator iter1 = n.begin();
	while (iter1 != n.end()) {
		notes.push_back( *iter1 );
		iter1++;
	}
}

void
NoteContainer::empty() 
{
	notes.clear();
}
