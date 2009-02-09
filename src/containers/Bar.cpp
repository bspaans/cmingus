#include "BarEntry.h"
#include "Bar.h"

Bar::Bar()
{
	key = NOTE((char *) "C");
	current_beat = 0.0;
	length = 1.0;
}

void
Bar::empty()
{
	bar.clear();
}
