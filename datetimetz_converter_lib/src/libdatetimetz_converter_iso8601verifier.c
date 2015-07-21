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

#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libtrace.h"
#include "libregex_custom.h"

#include "libdatetimetz_converter_timestamptzformat.h"
#include "libdatetimetz_converter_tzanytype.h"

#include "libdatetimetz_converter_datatypes.h"
#include "libdatetimetz_converter_consistency.h"
#include "libdatetimetz_converter_iso8601verifier.h"
#include "libdatetimetz_converter_iso8601assert.h"

int 
isISO8601noTZ(char *strval)
{

	log_debug("entering assert_isISO8601noTZ");

	char msg[TRACE_MESSAGE_MAXLENGTH];

	int res;

	if ( regexp_verify(strval, ISO8601NOTZREGEXP) == ISO8601NOTZREGEXPEXPECTEDMATCHES )
	{
		sprintf(msg, "[assert_isISO8601noTZ] %s is a valid ISO8601 timestamp",strval); log_finest(msg);
		res = 0;
	}
	else
	{
		sprintf(msg, "[assert_isISO8601noTZ] %s is a NOT valid ISO8601 timestamp",strval); log_critical(msg);
		res = 1;
	}

	log_debug("leaving assert_isISO8601noTZ");

	return res;

} // isISO8601noTZ

int
compareISOTimestampTZToSameTZ(
	char* inTimestampNoTZStr,
	char* inTZ)
{

	char msg[TRACE_MESSAGE_MAXLENGTH];

	int res = 0;
	int compareres;

	char  inTimestampFmt[40] ;

	strcpy(inTimestampFmt,  iso8601noTZFmt);
	//strcpy(inTimestampFmt, iso8601TZCombined);
	//strcpy(inTimestampFmt, iso8601TZOffset);
	//strcpy(inTimestampFmt, iso8601TZAbbrev);

	log_debug("starting compareISOTimestampTZToSameTZ");

	res = assert_isISO8601noTZ(inTimestampNoTZStr);

	if ( ! res )
	{

		// calls the next level comparison function

		compareres = compareTimestampToSameTZ(
			inTimestampNoTZStr, inTimestampFmt,
		inTZ);

		sprintf(msg,"[compareISOTimestampTZToSameTZ] compare %s %s res=%d",inTimestampNoTZStr, inTZ, compareres); 

		if ( ! compareres)
			log_fine(msg);
		else
			log_critical(msg);

		res = compareres;

	}

	sprintf(msg,"leaving compareISOTimestampTZToSameTZ res=%d",res);
	log_debug(msg);

	return res;

} // compareISOTimestampTZToSameTZ

int
compareISOTimestampTZBackToSameTZ(
	char* inTimestampNoTZStr,
	char* inTZ, char* targetTZ)
{

	char msg[TRACE_MESSAGE_MAXLENGTH];

	int res = 0;
	int compareres;

	char  inTimestampFmt[40] ;

	strcpy(inTimestampFmt,  iso8601noTZFmt);
	//strcpy(inTimestampFmt, iso8601TZCombined);
	//strcpy(inTimestampFmt, iso8601TZOffset);
	//strcpy(inTimestampFmt, iso8601TZAbbrev);

	log_debug("starting compareISOTimestampTZBackToSameTZ");

	res = assert_isISO8601noTZ(inTimestampNoTZStr);

	if ( ! res )
	{

		// calls the next level comparison function

		compareres = compareTimestampBackToSameTZ(
			inTimestampNoTZStr, inTimestampFmt,
		inTZ, targetTZ);

		sprintf(msg,"[compareISOTimestampTZBackToSameTZ] compare %s %s -> %s -> %s res=%d",inTimestampNoTZStr, inTZ, targetTZ, inTZ, compareres); 

		if ( ! compareres)
			log_fine(msg);
		else
			log_critical(msg);

		res = compareres;

	}

	sprintf(msg,"leaving compareISOTimestampTZBackToSameTZ res=%d",res);
	log_debug(msg);

	return res;

} // compareISOTimestampTZBackToSameTZ

int
checkISOTimestampTZConsistency(
	char* inTimestampNoTZStr,
	char* inTZ)
{

	char msg[TRACE_MESSAGE_MAXLENGTH];

	int res = 0;
	int expectedres = 0;

	res += compareISOTimestampTZToSameTZ(inTimestampNoTZStr, inTZ);
	res += compareISOTimestampTZBackToSameTZ(inTimestampNoTZStr, inTZ, EPOCH_TIMEZONE);

	if ( res == expectedres )
	{
		sprintf(msg,"[checkISOTimestampTZConsistency] %s %s is globally consistent res=%d",inTimestampNoTZStr, inTZ,res);
		log_finest(msg);
	}
	else
	{
		sprintf(msg,"[checkISOTimestampTZConsistency] %s %s is NOT consistent res=%d",inTimestampNoTZStr, inTZ,res);
		log_finest(msg);
	}

	sprintf(msg,"leaving checkISOTimestampTZConsistency res=%d",res);
	log_debug(msg);

	return res;

} // checkISOTimestampTZConsistency

