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
	// We need the (nr_of_dots + 1) element in the geometric series with common ratio 0.5
	return 0.5 * v / (1.0 - (float) pow(0.5, nr_of_dots + 1));
}


parsed_value
determine(value v)
{
	parsed_value result;
	return result;
}
