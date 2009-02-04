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

#define tonic(n, res) (major_triad(n, res))
#define supertonic(n, res) (minor_triad(major_second(n), res))
#define mediant(n, res) (minor_triad(major_third(n), res))
#define subdominant(n, res) (major_triad(major_fourth(n), res))
#define dominanth(n, res) (major_triad(perfect_fifth(n) ,res))
#define submediant(n, res) (minor_triad(major_sixth(n), res))
#define subtonic(n, res) (diminished_triad(major_seventh(n), res))

#define I(n, res) tonic(n, res)
#define II(n, res) supertonic(n, res)
#define ii(n, res) supertonic(n, res)
#define III(n, res) mediant(n, res)
#define iii(n, res) mediant(n, res)
#define IV(n, res) subdominant(n, res)
#define V(n, res) dominanth(n, res)
#define VI(n, res) submediant(n, res)
#define vi(n, res) submediant(n, res)
#define VII(n, res) subtonic(n, res)
#define vii(n, res) subtonic(n, res)
