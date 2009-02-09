#include "midi.h"

Synth::Synth()
{
	initialized = false;
}

void
Synth::init() 
{
	if (!initialized) {
		settings = new_fluid_settings();
		synth = new_fluid_synth(settings);
		initialized = true;
	}
	fluid_settings_setnum(settings, "synth.gain", 0.1);
	fluid_settings_setnum(settings, "synth.sample-rate", 
			44100);
	fluid_settings_setint(settings, "synth.midi-channels", 16);
}

Synth::~Synth() 
{
	if (initialized) 
	{
		delete_fluid_synth(synth);
		delete_fluid_settings(settings);
	}

}
