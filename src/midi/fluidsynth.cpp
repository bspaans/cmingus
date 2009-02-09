extern "C" {
	#include <fluidsynth.h>
}
#include "synth.h"
#include "../containers/containers.h"


void
Synth::fluid_init() {
	fluid_settings_t *settings = new_fluid_settings();
	fluid_synth_t *synth;

	synth = new_fluid_synth(settings);

	delete_fluid_synth(synth);
	delete_fluid_settings(settings);
}


