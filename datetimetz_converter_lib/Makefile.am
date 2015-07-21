ACLOCAL_AMFLAGS = -Im4
AUTOMAKE_OPTIONS = dejagnu

SUBDIRS = doc include src tests

EXTRA_DIST = doc

MOSTLYCLEANFILES = $(DX_CLEANFILES)

pkginclude_HEADERS = include/*.h

include $(top_srcdir)/aminclude.am
#include aminclude.am

dist-local : doxygen-doc ;

all-local : dist-local ;

