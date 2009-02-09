class Bar 
{

	public:
		// Constructors
		Bar();

		// Attributes
		note key;
		float current_beat;
		float length;

		std::vector<BarEntry> bar;

		// Methods
		void empty(void);

};
