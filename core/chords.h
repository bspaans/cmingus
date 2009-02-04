void triad(note, note, note*);
void triads(note, note**);
void seventh_chord(note, note, note*);


#define major_triad(n, res) (triad(n, n, res))
#define minor_triad(n, res) (triad(n, minor_seventh(n), res))
#define diminished_triad(n, res) (triad(n, minor_second(n), res))
