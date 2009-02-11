#include "value.h"
#include <math.h>

ratio r_triplet = {3, 2};
ratio r_quintuplet = {5, 4};
ratio r_septuplet4 = {7, 4};
ratio r_septuplet8 = {7, 8};

value base_values[]      = {   0.25, 0.5, 1, 2, 4,8,16,32,64,128};

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
determine_value(value v)
{
	parsed_value result;
	result.dots = 0;
	result.tuplet_ratio[0] = 1;
	result.tuplet_ratio[1] = 1;
	int x = 0;
	float bv, scaled;
	for (x; x<10; x++)
	{
		bv = base_values[x];
		if (v == bv)
		{
			result.base = v;
			return result;
		}
		if (v < bv)
			break;
	}
	scaled = v / pow(2, x - 2);
	if (scaled >= 0.9375)
	{
		result.base = base_values[x];
		return result;
	}
	else if (scaled >= 0.8125)
	{
		result.base = base_values[x - 1];
		result.tuplet_ratio[0] = 7;
		result.tuplet_ratio[1] = 4;
		return result;
	}
	else if (scaled >= 17 / 24.0)
	{
		result.base = base_values[x - 1];
		result.tuplet_ratio[0] = 3;
		result.tuplet_ratio[1] = 2;
		return result;
	}
	else if (scaled >= 31 / 48.0)
	{
		result.base = base_values[x];
		result.dots = 1;
		return result;
	}
	else if (scaled >= 67 / 112.0)
	{
		result.base = base_values[x - 1];
		result.tuplet_ratio[0] = 5;
		result.tuplet_ratio[1] = 4;
		return result;
	}

	int i;
	for (i = 2; i < 5; i++)
	{
		if (scaled >= dotted_value(base_values[x], i) / 
				base_values[x])
		{
			result.base = base_values[x];
			result.dots = i;
			return result;
		}
	}
	result.base = base_values[x];
	return result;
}
