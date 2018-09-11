#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libstoresimul], [1.0], [arella.1646983@studenti.uniroma1.it])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])
AM_INIT_AUTOMAKE([foreign 1.13])

# Checks for programs.
AC_PROG_CC
LT_PREREQ([2.4])
LT_INIT

# Use the C language and compiler for the following checks
AC_LANG([C])

# Checks for posix support
AC_EGREP_CPP(posix_200809L_supported,
             [#define _POSIX_C_SOURCE 200809L
              #include <unistd.h>
              #ifdef _POSIX_VERSION
              #if _POSIX_VERSION == 200809L
              posix_200809L_supported
              #endif
              #endif
             ],
             [],
             [AC_MSG_FAILURE([*** Implementation must conform to the POSIX.1-2008 standard.])]
)

# Checks for header files.
AC_CHECK_HEADERS([errno.h stdlib.h signal.h string.h pthread.h semaphore.h])

# Checks for typedefs, structures, and compiler characteristics.

AC_SEARCH_LIBS([pthread_create], [pthread])
AC_SEARCH_LIBS([pthread_detach], [pthread])
AC_SEARCH_LIBS([sem_init], [pthread])
AC_SEARCH_LIBS([sem_wait], [pthread])
AC_SEARCH_LIBS([sem_post], [pthread])
AC_SEARCH_LIBS([sem_destroy], [pthread])

# Checks for library functions.
AC_CHECK_FUNCS([memset strerror])

AC_CONFIG_FILES([Makefile
                 src/Makefile
                 examples/Makefile
                 man/Makefile])
AC_OUTPUT
