

class Note {
	public:
		/* constructors */
		Note();
		Note(note);
		Note(note, int);
		Note(char *);
		Note(char *, int);

		/* attributes */
		note name;
		int octave;

		/* methods */
		void set_note(note);
		void set_note(note, int);
		void set_note(char *);
		void set_note(char *, int);
		void augment();
		void diminish();
		void octave_up();
		void octave_down();
		void to_minor();
		void to_major();
		//void transpose(interval, bool up);
		void from_int(int);
		int to_int();

};
