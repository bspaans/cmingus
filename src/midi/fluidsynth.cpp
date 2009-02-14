#include "midi.h"
#include <string.h>
#include <iostream>

#include "../../config.h"
#if !HAVE_WINDOWS_H
#include <unistd.h>
#else
#include <windows.h>
#endif

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
		fluid_set_log_function(FLUID_PANIC, NULL, NULL);
		fluid_set_log_function(FLUID_ERR, NULL, NULL);
		fluid_set_log_function(FLUID_WARN, NULL, NULL);
		fluid_set_log_function(FLUID_INFO, NULL, NULL);
		fluid_set_log_function(FLUID_DBG, NULL, NULL);
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
	}
	audio_driver = new_fluid_audio_driver(settings, synth);
}


void
Synth::load_soundfont(char *filename)
{
	sfid = fluid_synth_sfload(synth, filename, false);
	fluid_synth_program_reset(synth);
}


void
Synth::sleep(int milliseconds)
{
#if !HAVE_WINDOWS_H
	usleep(milliseconds * 1000);
#else
	Sleep(milliseconds);
#endif 
}


void
Synth::play_Note(Note n, int channel = 1, int velocity = 100)
{
	fluid_synth_noteon(synth, channel, n.to_int() + 12, velocity);
}


void
Synth::stop_Note(Note n, int channel = 1)
{
	fluid_synth_noteoff(synth, channel, n.to_int() + 12);
}


void
Synth::play_NoteContainer(NoteContainer n, int channel = 1, int velocity = 100)
{
	std::vector<Note>::iterator iter = n.notes.begin();
	while ( iter < n.notes.end() )
		play_Note(*iter++, channel, velocity);
}


void
Synth::stop_NoteContainer(NoteContainer n, int channel)
{
	std::vector<Note>::iterator iter = n.notes.begin();
	while ( iter < n.notes.end() )
		stop_Note(*iter++, channel);
}


float
Synth::play_Bar(Bar b, int channel = 1, float bpm = 120)
{
	float qn_length = 60000.0 / bpm;
	std::vector<BarEntry>::iterator iter = b.bar.begin();

	while ( iter < b.bar.end() )
	{
		play_NoteContainer( (*iter).notes, channel );
		sleep ( (int) qn_length * 4.0 / (*iter).value);
		stop_NoteContainer( (*iter).notes, channel );
		*iter++;
	}

	return bpm;
}


void
Synth::play_Track(Track t, int channel = 1, float bpm = 120)
{
	std::vector<Bar *>::iterator iter = t.bars.begin();
	while ( iter < t.bars.end()) 
	{
		bpm = play_Bar( (**iter), channel, bpm );
		*iter++;
	}
}

void
Synth::set_instrument(int channel, int instr)
{
	set_instrument(channel, instr, 0);
}


void
Synth::set_instrument(int channel, int instr, int bank)
{
	fluid_synth_program_select(synth, channel, sfid, bank, instr);
}


