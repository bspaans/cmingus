bin_PROGRAMS = mingus_core mingus_containers mingus_midi
mingus_core_SOURCES = mingus_core_tests.c
mingus_containers_SOURCES = mingus_container_tests.cpp
mingus_midi_SOURCES = mingus_midi_tests.cpp
SUBDIRS = core containers midi
mingus_core_LDADD = core/libminguscore.a 
mingus_containers_LDADD = containers/libminguscontainers.a core/libminguscore.a
mingus_midi_LDADD = containers/libminguscontainers.a core/libminguscore.a
