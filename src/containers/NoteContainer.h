class NoteContainer 
{
	public:
		/* constructors */
		NoteContainer();
		NoteContainer(std::vector<Note>);

		/* attributes */
		std::vector<Note> notes;

		/* methods */
		void add_note(Note);
		void add_note(note);
		void add_note(note, int);
		void add_note(char *);
		void add_note(char *, int);
		void add_notes(std::vector<Note>);
		void empty(void);
		void augment(void);
		void diminish(void);
};
