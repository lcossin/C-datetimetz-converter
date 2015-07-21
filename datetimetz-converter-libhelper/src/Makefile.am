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

AM_CPPFLAGS += -Wall -D_XOPEN_SOURCE=600 -DDATADIR=$(pkgdatadir)
AM_LDFLAGS = -module -shared -avoid-version

HELPER_LIBS = 
HELPER_LIBS += libtrace.c
HELPER_LIBS += libassert_custom.c
HELPER_LIBS += libregex_custom.c

FORMAT_LIBS =
FORMAT_LIBS += libdatetimetz_converter_dataparsetimestamps.c
FORMAT_LIBS += libdatetimetz_converter_timestamptzformat.c

# the shared libraries
pkglib_LTLIBRARIES = libdatetimetz_converter_libhelper.la
libdatetimetz_converter_libhelper_la_SOURCES = $(FORMAT_LIBS) $(HELPER_LIBS) 

libdatetimetz_converter_libhelper_la_LDFLAGS = -module -shared -avoid-version -Wl,--allow-multiple-definition

