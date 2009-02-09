#include "containers.h"

NoteContainer::NoteContainer() { }
NoteContainer::NoteContainer(std::vector<Note> n) 
{ 
	notes = n;
}


void
NoteContainer::add_note(Note n)
{
	// check if note is already listed.
	notes.push_back(n);
}


void
NoteContainer::add_note(note n)
{
	add_note(Note(n));
}


void
NoteContainer::add_note(note n, int octave)
{
	add_note(Note(n, octave));
}


void
NoteContainer::add_note(char *n)
{
	add_note(Note(n));
}


void
NoteContainer::add_note(char *n, int octave)
{
	add_note(Note(n, octave));
}


void
NoteContainer::add_notes(std::vector<Note> n)
{
	std::vector<Note>::iterator iter1 = n.begin();
	while (iter1 != n.end()) {
		add_note( *iter1 );
		iter1++;
	}
}

void
NoteContainer::empty() 
{
	notes.clear();
}
