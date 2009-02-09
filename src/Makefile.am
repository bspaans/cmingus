bin_PROGRAMS = mingus_core mingus_containers
mingus_core_SOURCES = mingus_core_tests.c
mingus_containers_SOURCES = mingus_container_tests.cpp
SUBDIRS = core containers
mingus_core_LDADD = core/libminguscore.a 
mingus_containers_LDADD = core/libminguscore.a containers/libminguscontainers.a
