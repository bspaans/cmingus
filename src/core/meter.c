#include "meter.h"

int common_time[2] = {4, 4};
int cut_time[2] = {2, 2};
	
int 
valid_beat_duration(int duration)
{
	int r;
	if (duration <= 0)
		return 0;

	r = duration;
	while (r != 1)
	{
		if (r % 2 == 1)
			return 0;
		r /= 2;
	}
	return 1;
}
