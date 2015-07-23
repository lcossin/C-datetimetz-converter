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
 * @file libdatetimetz_converter_tztimeoffset.h
 * @author Laurent Cossin
 * @date   July 2015
 *
 * @ingroup datetimetz_converter_filter
 *
 * @brief Provides some functions to handle a timezone given as a time offset
 *
*/

#ifndef TZTIMEOFFSET_HEADERS

	#define TZTIMEOFFSET_HEADERS

	// special time offset 'Z' for UTC

	#define UTCSPECIALOFFSETTZREGEXP "^Z$"
	#define UTCSPECIALOFFSETTZREGEXPEXPECTEDMATCHES 1

	// valid time offset for UTC
	#define UTCOFFSETTZREGEXP "^([+]00:{0,1}00)$"
	#define UTCOFFSETTZREGEXPEXPECTEDMATCHES_MIN 5
	#define UTCOFFSETTZREGEXPEXPECTEDMATCHES_MAX 6

	// wrong time offset for UTC
	#define UTCWRONGOFFSETTZREGEXP "^([-]00:{0,1}00)$"
	#define UTCWRONGOFFSETTZREGEXPEXPECTEDMATCHES_MIN 5
	#define UTCWRONGOFFSETTZREGEXPEXPECTEDMATCHES_MAX 6

	// regexp for a time offset in ISO format
	// does not handle the simple format +-hh (without mm)
	// time offset for timezone except UTC

	#define OFFSETTZREGEXP "^([+]00:{0,1}00)$|(([+-])([0-1][0-9]|2[0-3]):{0,1}([0-5][0-9]))$"

	// the length of the matching pattern is exactly 5 characters 
	#define OFFSETTZREGEXPEXPECTEDMATCHES_MIN 5
	#define OFFSETTZREGEXPEXPECTEDMATCHES_MAX 6


/// Verifies if a given TZ value is a valid time offset for UTC - cf ISO8601 rules

int
isUTCTimeOffsetTZ(char *TZval);

/// Verifies if a given TZ value is a valid time offset

int
isTimeOffsetTZ(char *TZval);

/// Converts a time offset TZ to seconds

int
convertTimeOffsetToSeconds(char *TZval,int *offsetSeconds);

/// Splits a time string into hours and minutes, and sign factor (1 or -1)

int
splitTimeOffseStrtToValues(char *timeoffsetstr, int *signfactor, int *hours, int *minutes);

/// Splits and converts a time string into seconds
int
splitconvertTimeOffsetStrToValues(char *timeoffsetstr, int *timeoffsetseconds);

#endif

