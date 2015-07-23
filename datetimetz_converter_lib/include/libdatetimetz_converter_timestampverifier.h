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
 * @file libdatetimetz_converter_verifier.h
 * @author Laurent Cossin
 * @date   July 2015
 *
 * @ingroup datetimetz_converter_consistency_verifier
 *
 * @brief Provides some functions to compare results after timezone conversion
 *
*/

#ifndef CONSISTENCY_HEADERS

	#define CONSISTENCY_HEADERS

/// compares a timestamp (in a custom format) after conversion to the same timezone

/**

		@param[in] inTimestampStr			The timestamp string
		@param[in] inTimestampFmtStr	The format (string) of the timestamp
		@param[in] inTZ					The timezone

		@return return value of strcmp comparing the timestamp with the expected timestamp
		@retval 0 : timestamp matches the expected timestamp
		@retval <>0 : return value of the strcmp function

*/

int
compareTimestampToSameTZ(
	char* inTimestampStr, char* inTimestampFmtStr,
	char* inTZ);

/// compares a timestamp (in a custom format) after conversion to another timezone and back to the original timezone

/**
		@remark The expected final timestamp is the same string as the original one as input parameter

		@param[in] inTimestampStr	The timestamp string
		@param[in] inTimestampFmtStr	The format of the timestamp string
		@param[in] inTZ					The timezone
		@param[in] targetTZ					The target timezone

		@return return value of strcmp comparing the timestamp with the expected timestamp
		@retval 0 : timestamp matches the expected timestamp
		@retval <>0 : return value of the strcmp function

*/

int
compareTimestampBackToSameTZ(
	char* inTimestampStr, char* inTimestampFmtStr,
	char* inTZ, char* targetTZ);

/// checks if the timestamp (with a custom format) + timezone is consistent

int
checkTimestampConsistency(
	char* inTimestampNoTZStr, char* inTimestampFmtStr,
	char* inTZ);

#endif

