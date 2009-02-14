#include <string>
#include "containers.h"

Track::Track()
{
	//name = "Untitled";
}


void
Track::add_bar(Bar *b)
{
	bars.push_back(b);
}

void
Track::empty()
{
	bars.clear();
}
