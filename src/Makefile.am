AM_CFLAGS = -I$(top_srcdir)/include

lib_LTLIBRARIES = $(top_srcdir)/lib/libstoresimul.la

__top_srcdir__lib_libstoresimul_la_SOURCES = \
	storesimul.c \
	internals/atomic.c \
	internals/accessimul.c

__top_srcdir__lib_libstoresimul_la_includedir = $(top_srcdir)/include

nobase_include_HEADERS = \
	$(top_srcdir)/include/storesimul/storesimul.h \
	$(top_srcdir)/include/storesimul/internals/atomic.h \
	$(top_srcdir)/include/storesimul/internals/accessimul.h

__top_srcdir__lib_libstoresimul_la_LDFLAGS = -shared -version-info 1:0