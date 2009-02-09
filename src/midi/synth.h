class Synth {

	public:
		/* Constructors and Deconstructors */
		Synth();
		~Synth();

		/* Methods */
		void init(void);

	private:
		/* Attributes */
		fluid_settings_t *settings;
		fluid_synth_t *synth;
		bool initialized;

};
