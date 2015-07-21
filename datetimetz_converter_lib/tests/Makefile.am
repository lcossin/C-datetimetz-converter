AUTOMAKE_OPTIONS = dejagnu

EXTRA_DIST = testtzconverter-memleaks.sh.am

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

AM_CPPFLAGS += -Wall
AM_CPPFLAGS += -D_XOPEN_SOURCE=600
AM_CPPFLAGS += -DDATADIR=$(pkgdatadir)
AM_CPPFLAGS += $(TZCONVERTLIBHELPER_INCLUDE) 

AM_LDFLAGS  = -module -shared -avoid-version
AM_LDFLAGS += -Wl,--allow-multiple-definition

TZ_LIBS = 
TZ_LIBS += ../src/libdatetimetz_converter_lib.la
TZ_LIBS += $(TZCONVERTLIBHELPER_LTLIB)

MEMLEAKS_PROG = testtzconverter_memleaks
MEMLEAKS_FILE  = testtzconverter-memleaks
MEMLEAKS_CFILE = $(MEMLEAKS_FILE).c
MEMLEAKS_SHELL = $(MEMLEAKS_FILE).sh
MEMLEAKS_BIN = $(bindir)/$(MEMLEAKS_PROG).sh

TZTESTS_ERRORS = testtzconverter_WrongParameters testtzconverter_WrongTimestamps

TZTESTS_UTC = testtzconverter_UTC
TZTESTS_UTC += testtzconverter_GMToffset

TZTESTS_EU = testtzconverter_DST_Berlin
TZTESTS_EU += testtzconverter_DST_CET 

TZTESTS_FAILURES =
TZTESTS_FAILURES += testtzconverter_DST_CEST
TZTESTS_FAILURES += testtzconverter_DST_EST

TZTESTS_USA2007 = testtzconverter_DST_NewYork
TZTESTS_USA2007 += testtzconverter_DST_EST5EDT

TZTESTS_TZDATA2015e = testtzconverter_DST_tzdata2015e

TZTESTS_DST = $(TZTESTS_EU) $(TZTESTS_USA2007) $(TZTESTS_TZDATA2015e) 

TZTESTS_TECH = $(TZTESTS_ERRORS) 
#### TZTESTS_TECH +=$(TZTESTS_MEMLEAKS)

TZTESTS_ALL = $(TZTESTS_UTC) $(TZTESTS_DST) $(TZTESTS_TECH)

TESTS = $(TZTESTS_ALL)
check_PROGRAMS = $(TZTESTS_ALL) $(TZTESTS_FAILURES)

testtzconverter_DST_Berlin_SOURCES = testtzconvert-DST-Berlin.c
testtzconverter_DST_Berlin_LDADD = $(TZ_LIBS)

testtzconverter_DST_CET_SOURCES = testtzconvert-DST-CET.c
testtzconverter_DST_CET_LDADD = $(TZ_LIBS)

testtzconverter_DST_CEST_SOURCES = testtzconvert-DST-CEST.c
testtzconverter_DST_CEST_LDADD = $(TZ_LIBS)

testtzconverter_DST_NewYork_SOURCES = testtzconvert-DST-NewYork.c
testtzconverter_DST_NewYork_LDADD = $(TZ_LIBS)

testtzconverter_DST_EST_SOURCES = testtzconvert-DST-EST.c
testtzconverter_DST_EST_LDADD = $(TZ_LIBS)

testtzconverter_DST_EST5EDT_SOURCES = testtzconvert-DST-EST5EDT.c
testtzconverter_DST_EST5EDT_LDADD = $(TZ_LIBS)

testtzconverter_DST_tzdata2015e_SOURCES = testtzconvert-DST-tzdata2015e.c
testtzconverter_DST_tzdata2015e_LDADD = $(TZ_LIBS)

testtzconverter_UTC_SOURCES = testtzconvert-UTC.c
testtzconverter_UTC_LDADD = $(TZ_LIBS)

testtzconverter_GMToffset_SOURCES = testtzconvert-GMToffset.c
testtzconverter_GMToffset_LDADD = $(TZ_LIBS)

testtzconverter_WrongParameters_SOURCES = testtzconvert-WrongParameters.c
testtzconverter_WrongParameters_LDADD = $(TZ_LIBS)

testtzconverter_WrongTimestamps_SOURCES = testtzconvert-WrongTimestamps.c
testtzconverter_WrongTimestamps_LDADD = $(TZ_LIBS)

bin_PROGRAMS = $(MEMLEAKS_PROG)
testtzconverter_memleaks_SOURCES = testtzconverter-memleaks.c
testtzconverter_memleaks_LDADD = $(TZ_LIBS)

check-local : install ;
	cat $(MEMLEAKS_SHELL).am | sed -e "s;#BINDIR#;$(bindir);" -e "s;#PROGNAME#;$(MEMLEAKS_PROG);" > $(MEMLEAKS_BIN)
	chmod u+x $(MEMLEAKS_BIN); ls -l $(MEMLEAKS_BIN); 
	$(MEMLEAKS_BIN);
	rm $(MEMLEAKS_BIN)


