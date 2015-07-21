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
 * @file libdatetimetz_converter_iso8601verifier.h
 * @author Laurent Cossin
 * @date   July 2015
 *
 * @ingroup datetimetz_converter_consistency
 *
 * @brief Provides some functions to compare results after timezone conversion
 *
*/

#ifndef ISO8601CONSISTENCY_HEADERS

	#define ISO8601CONSISTENCY_HEADERS


/// compares a timestamp (in ISO8601 format) after conversion to the same timezone 

/**

		@param[in] inTimestampNoTZStr	The timestamp string
		@param[in] inTZ					The timezone

		@return return value of strcmp comparing the timestamp with the expected timestamp
		@retval 0 : timestamp matches the expected timestamp
		@retval <>0 : return value of the strcmp function

*/

int
compareISOTimestampTZToSameTZ(
	char* inTimestampNoTZStr,
	char* inTZ);

/// compares a timestamp (in ISO8601 format) after conversion to another timezone and back to the original timezone

/**
		@remark The expected final timestamp is the same string as the original one as input parameter

		@param[in] inTimestampNoTZStr	The timestamp string
		@param[in] inTZ					The timezone
		@param[in] targetTZ					The target timezone

		@return return value of strcmp comparing the timestamp with the expected timestamp
		@retval 0 : timestamp matches the expected timestamp
		@retval <>0 : return value of the strcmp function

*/

int
compareISOTimestampTZBackToSameTZ(
	char* inTimestampNoTZStr,
	char* inTZ, char* targetTZ);

/// checks if the given timestamp (in ISO8601 format) is consistent after some conversions

int
checkISOTimestampTZConsistency(
	char* inTimestampNoTZStr,
	char* inTZ);

	#define ISO8601NOTZREGEXP "^[1-2][0-9]{3}-((0[1,3-9]|1[0-2])-(0[1-9]|[1-2][0-9]|3[0-1])|02-(0[1-9]|[1-2][0-9]))T([0-1][0-9]|2[0-3]):([0-5][0-9]):([0-5][0-9])"

	#define ISO8601NOTZREGEXPEXPECTEDMATCHES 19

/// Verifies if a string matches an ISO8601 value without any timezone

/**

	@param[in] strval The string to evaluate

	@return		The result of the test
	@retval	0			if strval is an ISO8601 value
	@retval	<>0		if strval is NOT an ISO8601 value

*/

int 
isISO8601noTZ(char *strval);

#endif

