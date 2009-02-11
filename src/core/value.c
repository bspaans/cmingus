#include "value.h"
#include <math.h>

ratio r_triplet = {3, 2};
ratio r_quintuplet = {5, 4};
ratio r_septuplet4 = {7, 4};
ratio r_septuplet8 = {7, 8};

value
tuplet(value v, ratio r)
{
	// Not a macro, because the type checking is pretty important here.
	return r[0] * v / r[1];
}

value 
dotted_value(value v, int nr_of_dots)
{
	value d = 0.0;
	while (nr_of_dots >= 0)
	{
		d += 1.0 / (pow(2, nr_of_dots));
		nr_of_dots--;
	}
	return v / d;
}


parsed_value
determine(value v)
{
	parsed_value result;
	return result;
}
