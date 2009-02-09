AC_INIT([cmingus], [0.1], [bartspaans@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_SEARCH_LIBS(new_fluid_settings, fluidsynth)
AC_CHECK_HEADERS([fluidsynth.h])
AC_PROG_CC
AC_PROG_CXX
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
 Makefile
 src/Makefile
 src/core/Makefile
 src/containers/Makefile
 src/midi/Makefile
])
AC_PROG_RANLIB
AC_OUTPUT
