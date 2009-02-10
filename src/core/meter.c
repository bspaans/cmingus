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
