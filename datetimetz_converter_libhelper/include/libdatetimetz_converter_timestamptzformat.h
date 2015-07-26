/*
    This file is part of libdatetimetz_converter.

    Copyright (C) 2015 Laurent Cossin

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; 
    version 2.1 of the License.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

/** 
 * @file libdatetimetz_converter_timestamptzformat.h
 * @author Laurent Cossin
 * @copyright GNU Lesser General Public License

 * @date   July 2015
 *
 * @ingroup datetimetz_converter_helper
 *
 * @brief Provides some constants and some functions to manage the timestamp formats
 *
*/

#ifndef TIMESTAMPTZFORMAT_HEADERS

	#define TIMESTAMPTZFORMAT_HEADERS

	#include "libdatetimetz_converter_datatypes.h"

/*
		constants for date-time formats
*/

/*
		constants for a bit vector
*/

	/// ISO8601 format option
	const int  iso8601Flag	= 1; 

	/// Timezone abbreviation option
	const int  TZAbbrevFlag	= 2; 

	/// Timezone offset option
	const int  TZOffsetFlag	= 4; 

	/// Posix format option
	const int  PosixFlag		= 8; 

	/// Olson timezone option
	const int  TZOlsonFlag	= 16;

/*
		format options for strptime
*/

	#define TIMESTAMPFORMATMAXLENGTH 255

	/// strptime - timezone offset
	const char TZOffsetFmt[] = "%z"; 

	/// strptime - timezone abbreviation
	const char TZAbbrevFmt[] = "%Z"; 

/*
		format options for strptime, ISO8601-compliant
*/

	/// strptime - ISO8601 without timezone
	const char iso8601noTZFmt[]			= "%Y-%m-%dT%H:%M:%S";

	/// strptime - ISO8601 + timezone offset
	const char iso8601TZOffset[]		= "%Y-%m-%dT%H:%M:%S %z";

	/// strptime - ISO8601 + timezone abbreviation
	const char iso8601TZAbbrev[]		= "%Y-%m-%dT%H:%M:%S %Z";

	/// strptime - ISO8601 + timezone offset + timezone abbreviation
	const char iso8601TZCombined[]	= "%Y-%m-%dT%H:%M:%S %z %Z";

/*
	builder functions
*/

/// builds the format string according to the options (FmtFlags)

int 
buildFmtStr(int FmtFlags, char* FmtStr);


/*
	sets the options with the default settings
*/

/// set the default options for a timestamp as input

int 
setDefaultInputFmtOpts(int* flags);

/// set the default options for a timestamp as output

int 
setDefaultOutputFmtOpts(int* flags);

/*
	sets the bits in a bit vector
*/

///	enables Olson timezone option

int 
setOlsonOpts(int* flags);

/// enables the ISO8601 format

int 
setISO8601Opts(int* flags);

/// enables ISO8601 format + Olson timezone

int 
setISO8601OlsonOpts(int* flags);

/// enables option Olson timezone - wrapper for setOlsonOpts

int 
setOlsonInputFmtOpts(int* flags);

/// enables option Olson timezone - wrapper for setOlsonOpts

int 
setOlsonOutputFmtOpts(int* flags);

#endif

