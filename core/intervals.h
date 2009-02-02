int measure(char *, char *);
char * determine(char *, char *, int);


char * interval_names[] = { "unison",
                          "fifth",
			  "second",
			  "sixth",
			  "third",
			  "seventh",
			  "fourth" };

char interval_names_shorthand[] = { '1', '5', '2', '6',
                                    '3', '7', '4' };

int expected_semitones[] = {0, 7, 2, 9, 4, 11, 5};
