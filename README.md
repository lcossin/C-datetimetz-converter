# C-datetimetz-converter
Some libraries in C to convert date time between timezones

## How to contribute ?

Feel free to create new issues for any type of requests, request a fix for bugs, ask for some enhancements.

## Sub projects

The projects is composed of sub projects.

### Libraries 'helper'

Refer to README in the sub-project.

### Libraries 'lib' (timestamp convert)

Refer to README in the sub-project.

### Additional sub-projects

Some wrappers are given as examples to call the timezone converter routines from within other programs : 
* PL/SQL application (Oracle Database)

## Documentation

Documentation is provided in various formats (using Doxygen), HTML, RTF, man pages.

The documentation can be generated again using 'make doxygen-doc' from the library sub-projects.

## How to build ?

First, build the project 'datetimetz_converter_libhelper'.

Then, build the projet 'datetimetz_converter_lib'.

Refer to the README file in the project folders.

### How to customize the target installation path ?

Before running 'make' and 'make install'.

./configure --prefix=[target directory]

Refer to configure help

## How to use the C routines in programs ?

Refer to the C source code for the test units.

folder : datetimetz_converter_lib/tests

## How to make sure the libraries work as expected ?

Go to datetimetz_converter_lib/

Run 'make check'

If valgrind is installed, make check will report the result of the 'no memory leaks' test.

Valgrind does not detect any memory leak.

