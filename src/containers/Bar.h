class Bar 
{

	public:
		// Constructors
		Bar();
		Bar(note);
		Bar(note, meter);

		// Attributes
		note key;
		std::vector<BarEntry> bar;

		// Methods
		void empty(void);
		void set_meter(meter);
		void get_meter(meter);
		bool place_notes(NoteContainer, int duration);

	private:
		meter bar_meter;
		float current_beat;
		float bar_length;
};
