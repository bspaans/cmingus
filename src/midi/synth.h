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

	private:
		/* Attributes */
		fluid_settings_t *settings;
		fluid_synth_t *synth;
		fluid_audio_driver_t *audio_driver;
		bool initialized;
		char *driver;
		int sfid;

};
