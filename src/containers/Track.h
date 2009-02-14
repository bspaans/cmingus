class Track
{

	public:
		// Constructors
		Track();

		// Attributes
		std::vector<Bar *> bars;
		//std::string name;

		// Instrument; not implemented yet.
		
		// Methods
		void empty(void);
		void add_bar(Bar *);

};
