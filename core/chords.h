/*

================================================================================
    
    cmingus, a reimplementation of mingus in C.
    Copyright (C) 2008-2009, Bart Spaans <bartspaans@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.

================================================================================

*/


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

#define tonic7(n, res) (major_seventh_chord(n, res))
#define supertonic7(n, res) (minor_seventh_chord(major_second(n), res))
#define mediant7(n, res) (minor_seventh_chord(major_third(n), res))
#define subdominant7(n, res) (major_seventh_chord(major_fourth(n), res))
#define dominanth7(n, res) (dominanth_seventh_chord(perfect_fifth(n) ,res))
#define submediant7(n, res) (minor_seventh_chord(major_sixth(n), res))
#define subtonic7(n, res) (half_diminished_seventh_chord(major_seventh(n), res))

#define I7(n, res) tonic7(n, res)
#define II7(n, res) supertonic7(n, res)
#define ii7(n, res) supertonic7(n, res)
#define III7(n, res) mediant7(n, res)
#define iii7(n, res) mediant7(n, res)
#define IV7(n, res) subdominant7(n, res)
#define V7(n, res) dominanth7(n, res)
#define VI7(n, res) submediant7(n, res)
#define vi7(n, res) submediant7(n, res)
#define VII7(n, res) subtonic7(n, res)
#define vii7(n, res) subtonic7(n, res)

typedef struct chord {
	note base;
	char chord_suffix;
} chord;

enum chord_suffix {
	/* triads */
	MINOR_TRIAD, MAJOR_TRIAD, DIMINISHED_TRIAD, AUGMENTED_TRIAD
};


void chord_suffix_to_string(enum chord_suffix, char *result, int);
void chord_to_string(chord, char *, int);

