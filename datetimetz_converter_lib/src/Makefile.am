AUTOMAKE_OPTIONS = dejagnu

AM_CPPFLAGS =

if OS_IS_DARWIN
 AM_CPPFLAGS += -DDARWIN
endif

if OS_IS_LINUX
 AM_CPPFLAGS += -DLINUX
endif

if OS_IS_CYGWIN
 AM_CPPFLAGS += -DCYGWIN
endif

#AM_CPPFLAGS += -Wall -I$(top_srcdir)/include -I$(top_srcdir)/src -D_XOPEN_SOURCE=600 -DDATADIR=$(pkgdatadir)
AM_CPPFLAGS += -Wall $(TZCONVERTLIBHELPER_INCLUDE) -D_XOPEN_SOURCE=600 -DDATADIR=$(pkgdatadir)
AM_LDFLAGS = -module -shared -avoid-version

CONSISTENCY_LIBS =
CONSISTENCY_LIBS += libdatetimetz_converter_consistency.c libdatetimetz_converter_iso8601verifier.c
CONSISTENCY_LIBS += libdatetimetz_converter_iso8601assert.c libdatetimetz_converter_assert.c 

CONVERTER_LIBS =
CONVERTER_LIBS += libdatetimetz_converter_epoch.c
CONVERTER_LIBS += libdatetimetz_converter_tzanytype.c 

# the shared libraries
pkglib_LTLIBRARIES = libdatetimetz_converter_lib.la
libdatetimetz_converter_lib_la_SOURCES = $(CONVERTER_LIBS) $(CONSISTENCY_LIBS)
libdatetimetz_converter_lib_la_LIBADD = $(TZCONVERTLIBHELPER_LTLIB)

#libdatetimetz_converter_lib_la_LDFLAGS = -module -shared

libdatetimetz_converter_lib_la_LDFLAGS = -module -shared -avoid-version -Wl,--allow-multiple-definition

# not needed, replaced by AM_LDFLAGS
#libdatetimetz_converter_lib_la_LDFLAGS = -shared -module

