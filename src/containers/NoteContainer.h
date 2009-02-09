#include <vector>

class NoteContainer 
{
	public:
		NoteContainer();
		std::vector<Note> notes;
		void add_note(Note);
		void empty(void);
		void augment(void);
		void diminish(void);
};
