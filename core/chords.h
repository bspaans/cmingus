void triad(note, note, note*);
void augmented_triad(note, note*);
void triads(note, note**);
void seventh_chord(note, note, note*);
void diminished_seventh_chord(note, note*);
void minor_major_seventh_chord(note, note*);


#define major_triad(n, res) (triad(n, n, res))
#define minor_triad(n, res) (triad(n, minor_seventh(n), res))
#define diminished_triad(n, res) (triad(n, minor_second(n), res))


#define major_seventh_chord(n, res) (seventh_chord(n, n, res))
#define minor_seventh_chord(n, res) (seventh_chord(n, minor_seventh(n), res))
#define dominanth_seventh_chord(n, res) (seventh_chord(n, major_fourth(n), res))
#define half_diminished_seventh_chord(n, res) (seventh_chord(n, minor_second(n), res))
#define minor_seventh_flat_five_chord(n, res) (seventh_chord(n, minor_second(n), res))

