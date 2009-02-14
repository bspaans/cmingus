class Synth {

	public:
		/* Constructors and Deconstructors */
		Synth();
		~Synth();

		/* Methods */
		void init(void);
		void init(char *);
		void init(char *, char *);
		void start(char *);
		void load_soundfont(char *);
		void sleep(int milliseconds);
		void play_Note(Note, int, int);
		void stop_Note(Note, int);
		void play_NoteContainer(NoteContainer, int, int);
		void stop_NoteContainer(NoteContainer, int);
		float play_Bar(Bar, int, float);
		void set_instrument(int channel, int instr);
		void set_instrument(int channel, int instr, int bank);

	private:
		/* Attributes */
		fluid_settings_t *settings;
		fluid_synth_t *synth;
		fluid_audio_driver_t *audio_driver;
		bool initialized;
		char *driver;
		int sfid;

};
