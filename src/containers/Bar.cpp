#include "containers.h"

Bar::Bar()
{
	key = NOTE((char *) "C");
	set_meter(common_time);
}


Bar::Bar(note k)
{
	Bar();
	key = k;
}


Bar::Bar(note k, meter m)
{
	Bar();
	key = k;
	set_meter(m);
}


void
Bar::set_meter(meter m)
{
	empty();
	bar_meter[0] = m[0];
	bar_meter[1] = m[1];
	if (is_valid_meter(m))
		bar_length = m[0] * 1.0 / m[1];
	else if (m[0] == 0 && m[1] == 0)
		bar_length = 0.0;

	// #warning should raise exception.
}


void
Bar::get_meter(meter res)
{
	res[0] = bar_meter[0];
	res[1] = bar_meter[1];
}


void
Bar::empty()
{
	bar.clear();
	current_beat = 0.0;

}


bool
Bar::place_notes(NoteContainer notes, int duration)
{
	if (current_beat + 1.0 / duration <= bar_length 
		       || bar_length == 0.0)
	{
		BarEntry b(current_beat, duration, notes);
		bar.push_back(b);
		current_beat += 1.0 / duration;
		return true;
	}
	return false;
}
