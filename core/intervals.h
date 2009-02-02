#ifdef INTERVALS
extern char * interval_names[];
extern char interval_names_shorthand[];
extern char * prefix_names[];
extern int expected_semitones[];
#endif
#ifndef INTERVALS

#define INTERVALS

char * interval_names[] = { "unison",
                          "fifth",
			  "second",
			  "sixth",
			  "third",
			  "seventh",
			  "fourth" };

char interval_names_shorthand[] = { '1', '5', '2', '6',
                                    '3', '7', '4' };


char * prefix_names[] = { 
	"diminished",
	"minor",
	"major",
	"perfect",
	"augmented",
	};

int expected_semitones[] = {0, 7, 2, 9, 4, 11, 5};

#endif

#define DIMINISHED 0
#define MINOR 1
#define MAJOR 2
#define PERFECT 3
#define AUGMENTED 4



typedef struct interval {
	short shorthand;
	short prefix;
	int accidentals;
} interval;

int measure(char *, char *);
interval determine_interval(char *, char *);
