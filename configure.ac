AC_INIT([cmingus], [0.2], [bartspaans@gmail.com])
AM_INIT_AUTOMAKE([-Wall -Werror foreign])
AC_SEARCH_LIBS(new_fluid_settings, fluidsynth)
AC_CHECK_HEADERS([windows.h])
AC_CHECK_HEADERS([fluidsynth.h])
AC_PROG_CC
AC_PROG_CXX
AC_PROG_LIBTOOL
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([
 Makefile
 src/Makefile
 src/core/Makefile
 src/containers/Makefile
 src/midi/Makefile
 programs/Makefile
])
AC_OUTPUT
