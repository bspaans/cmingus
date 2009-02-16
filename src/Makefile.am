bin_PROGRAMS = mingus_core mingus_containers mingus_midi
mingus_core_SOURCES = mingus_core_tests.c
mingus_containers_SOURCES = mingus_container_tests.cpp
mingus_midi_SOURCES = mingus_midi_tests.cpp

SUBDIRS = core containers midi
mingus_core_LDADD = core/libminguscore.la 
mingus_containers_LDADD = containers/libminguscontainers.la core/libminguscore.la
mingus_midi_LDADD = containers/libminguscontainers.la core/libminguscore.la midi/libmingusmidi.la

lib_LTLIBRARIES = libmingus.la
libmingus_la_SOURCES = 
libmingus_la_LIBADD = midi/libmingusmidi.la

nobase_include_HEADERS = core/notes.h core/diatonic.h core/chords.h core/intervals.h core/meter.h core/value.h core/core.h core/progressions.h containers/Note.h containers/NoteContainer.h containers/Bar.h containers/BarEntry.h containers/Track.h containers/containers.h midi/midi.h midi/synth.h
