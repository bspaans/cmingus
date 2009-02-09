#include "midi.h"
#include <string.h>

Synth::Synth()
{
	driver = (char *) "";
	initialized = false;
	settings = NULL;
	synth = NULL;
	audio_driver = NULL;

}

void
Synth::init() 
{
	if (!initialized) {
		settings = new_fluid_settings();
		synth = new_fluid_synth(settings);
		initialized = true;

		fluid_settings_setnum(settings, (char *) "synth.gain", 0.1);
		fluid_settings_setnum(settings, (char *) "synth.sample-rate", 44100);
		fluid_settings_setint(settings, (char *) "synth.midi-channels", 16);
	}
}

void 
Synth::init(char *driver) 
{
	init();
	start(driver);
}

void
Synth::init(char *driver, char *SF2)
{
	init(driver);
	load_soundfont(SF2);
}

Synth::~Synth() 
{
	if (initialized) 
	{
		if (synth != NULL)
			delete_fluid_synth(synth);
		if (settings != NULL)
			delete_fluid_settings(settings);
		if (audio_driver != NULL)
			delete_fluid_audio_driver(audio_driver);
	}

}


void
Synth::start(char *fluidsynth_driver)
{
	driver = fluidsynth_driver;
	if (strcmp(driver, "") != 0) {
		fluid_settings_setstr(settings, (char *) "audio.driver", driver);
		audio_driver = new_fluid_audio_driver(settings, synth);
	}


}


void
Synth::load_soundfont(char *filename)
{
	sfid = fluid_synth_sfload(synth, filename, true);
}
