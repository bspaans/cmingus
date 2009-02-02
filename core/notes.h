int note_to_int(char *);
void int_to_note(int, char *);

int is_enharmonic(char *, char *);
int is_valid_note(char *);
int note_name_index(char);
int fifths_index(char);
int get_accidentals_value(char *);

void augment(char *, char *);
void diminish(char *, char *);

extern char note_names[];
extern int note_values[];
extern char fifths[];
extern char *naive_note_list[];
