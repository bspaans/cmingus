#include "meter.h"

meter common_time = {4, 4};
meter cut_time = {2, 2};
	
int 
valid_beat_duration(int duration)
{
	int r;
	if (duration <= 0)
		return 0;
	else if (duration == 1)
		return 1;

	r = duration;
	while (r != 1)
	{
		if (r % 2 == 1)
			return 0;
		r /= 2;
	}
	return 1;
}


int
is_valid_meter(meter m)
{
	return m[0] >= 0 && valid_beat_duration(m[1]);
}


int
is_compound_meter(meter m)
{
	return is_valid_meter(m) && m[0] % 3 == 0;
}


int
is_simple_meter(meter m)
{
	return is_valid_meter(m);
}


int 
is_asymmetrical_meter(meter m)
{
	return is_valid_meter(m) && m[0] % 2 == 1;
}
