#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([libstoresimul], [1.0], [arella.1646983@studenti.uniroma1.it])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_MACRO_DIR([m4])
AC_CONFIG_AUX_DIR([build-aux])

AC_SUBST(prefix, ["/usr/local"])
AC_SUBST(libdir, ["$(prefix)/lib"])
AC_SUBST(includedir, ["$(prefix)/include"])
AC_SUBST(pkgconfiginstalldir, ["/usr/share/pkgconfig"])

AM_INIT_AUTOMAKE([foreign 1.13 subdir-objects])

PKG_PROG_PKG_CONFIG([0.25]) # check and set $PKG_CONFIG

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
AC_CHECK_HEADERS_ONCE([ errno.h 
                        stdlib.h 
                        signal.h 
                        string.h 
                        pthread.h 
                        sys/types.h 
                        sys/ipc.h 
                        sys/sem.h])

# Checks for typedefs, structures, and compiler characteristics.

AC_SEARCH_LIBS([pthread_create], [pthread])
AC_SEARCH_LIBS([pthread_detach], [pthread])

# Checks for library functions.
AC_CHECK_FUNCS([memset strerror semget semctl semop])

AC_CONFIG_FILES([storesimul.pc
                 Makefile
                 src/Makefile
                 examples/Makefile
                 man/Makefile])

AC_OUTPUT
