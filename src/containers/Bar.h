class Bar 
{

	public:
		// Constructors
		Bar();

		// Attributes
		note key;
		float current_beat;
		float length;
		// meter ; needs meter and value module

		std::vector<BarEntry> bar;

		// Methods
		void empty(void);

};
