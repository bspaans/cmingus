#define LONGA 0.25
#define BREVE 0.5
#define SEMIBREVE 1
#define MINIM 2
#define CROTCHET 4
#define QUAVER 8
#define SEMIQUAVER 16
#define DEMISEMIQUAVER 32
#define HEMIDEMISEMIQUAVER 64
#define QUASIHEMIDEMISEMIQUAVER 128
#define SEMIHEMIDEMISEMIQUAVER 128

#define WHOLE_NOTE 1
#define HALF_NOTE 2
#define QUARTER_NOTE 4
#define EIGHT_NOTE 8
#define SIXTEENTH_NOTE 16
#define THIRTY_SECOND_NOTE 32
#define SIXTY_FOURTH_NOTE 64
#define HUNDRED_TWENTY_EIGHT_NOTE 128


typedef float value;
typedef int ratio[2];
typedef struct parsed_value {
	value base;
	int dots;
	ratio tuple_ratio;
} parsed_value;

value dotted_value(value, int);
value tuplet(value, ratio);
parsed_value determine(value);

extern ratio r_triplet;
extern ratio r_quintuplet;
extern ratio r_septuplet4;
extern ratio r_septuplet8;

#define add_values(value1, value2) (1 / (1.0 / value1 + 1.0 / value2))
#define subtract_values(value1, value2) (1 / (1.0 / value1 - 1.0 / value2))
#define triplet(v) (tuplet(v, r_triplet))
#define quintuplet(v) (tuplet(v, r_quintuplet))
#define septuplet(v, in_fourths) ((in_fourths) ? \
		(tuplet(v, r_septuplet4)) \
		: tuplet(v,r_septuplet8))
