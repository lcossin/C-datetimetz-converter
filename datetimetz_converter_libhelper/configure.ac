#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.69])
AC_INIT([datetimetz-converter-libhelper], [0.5], [https://github.com/lcossin/C-datetimetz-converter])

AC_COPYRIGHT([Copyright (C) 2015 Laurent Cossin])
AC_REVISION([$Revision: 0.5$])

AC_CONFIG_MACRO_DIR([m4])

# enable Warning all
# enable tar-pax instead of tar v7 (default)
AM_INIT_AUTOMAKE([dejagnu check-news tar-pax dist-zip dist-bzip2 -Wall])

# custom variables

# new default folder
prefix=/usr/local/mytools

# apply the customized variables
AC_SUBST(prefix)

# enable the required features
AC_USE_SYSTEM_EXTENSIONS

# not required, replaced by CFLAGS _XOPEN_SOURCE=600
# AC_GNU_SOURCE

# config.h
AC_CONFIG_SRCDIR([include/config.h.in])
AC_CONFIG_HEADERS([include/config.h])

# Checks for programs.
AC_PROG_CC
AM_PROG_AR([act-if-fail])

# Checks for library functions.
AC_FUNC_MALLOC
AC_FUNC_MKTIME
AC_FUNC_REALLOC
AC_CHECK_FUNCS([regcomp setenv uname])


# Checks for libraries.
AC_ENABLE_SHARED
AC_DISABLE_STATIC
#LT_INIT
LT_INIT([dlopen])
# AC_PROG_LIBTOOL(libtool)

# Checks for header files.
AC_CHECK_HEADERS([regex.h stdio.h stdlib.h string.h time.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_TYPE_SIZE_T

# Define arguments according to the operating system
AM_CONDITIONAL(OS_IS_DARWIN, [test x"$(uname)" = "xDarwin"])
AM_CONDITIONAL(OS_IS_LINUX,  [test x"$(uname)" = "xLinux"])
AM_CONDITIONAL(OS_IS_CYGWIN,  [test x"$(uname)" = "xCygwin"* ])

# List of Makefile files
AC_CONFIG_FILES([Makefile
                 doc/Makefile
                 include/Makefile
                 src/Makefile
    ])

# Doxygen settings for documentation building
DX_DOXYGEN_FEATURE(ON)
DX_DOT_FEATURE(OFF)
DX_HTML_FEATURE(ON)
DX_CHM_FEATURE(OFF)
DX_CHI_FEATURE(OFF)
DX_MAN_FEATURE(ON)
DX_RTF_FEATURE(ON)
DX_XML_FEATURE(OFF)
DX_PDF_FEATURE(OFF)
DX_PS_FEATURE(OFF)
DX_INIT_DOXYGEN([$PACKAGE_NAME], [doxygen.cfg], [doc/$PACKAGE_NAME])

# Run all
AC_OUTPUT
