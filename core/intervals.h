extern char * interval_names[];
extern char interval_names_shorthand[];
extern char * prefix_names[];
extern int expected_semitones[];

#define DIMINISHED 0
#define MINOR 1
#define MAJOR 2
#define PERFECT 3
#define AUGMENTED 4

typedef struct interval {
	char shorthand;
	char prefix;
	signed short accidentals;
} interval;

int measure(char *, char *);
interval determine_interval(char *, char *);
