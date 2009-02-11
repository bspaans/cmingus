#include "value.h"
#include <math.h>


value 
dots(value v, int nr_of_dots)
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
