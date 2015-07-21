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

#include "libdatetimetz_converter_timestamptzformat.h"
#include "libdatetimetz_converter_tzanytype.h"

#include "libdatetimetz_converter_consistency.h"
#include "libdatetimetz_converter_datatypes.h"

int
compareTimestampsNoTZ(char *timestamp, char *expectedtimestamp)
{

	char msg[TRACE_MESSAGE_MAXLENGTH];

	int compareres;

	compareres = strcmp(timestamp, expectedtimestamp);

	sprintf(msg,"[compareTimestampsNoTZ] compare '%s' with '%s' res=%d", timestamp, expectedtimestamp, compareres); log_debug(msg);

	return compareres;

} //compareTimestampsNoTZ

int
compareTimestampToSameTZ(
	char* inTimestampStr, char* inTimestampFmtStr,
	char* inTZ)
{

	int compareres;
	int res;

	char c_out_time_string[40];
	char msg[TRACE_MESSAGE_MAXLENGTH];

	// calls the conversion function

	res = condcheckConvertTimestampTZByFmtStr2TZ(
		inTimestampStr, inTimestampFmtStr,
		c_out_time_string, inTimestampFmtStr,
		inTZ, inTZ, 0);

	if ( ! res ) 
	{
		compareres = compareTimestampsNoTZ(c_out_time_string, inTimestampStr);

		sprintf(msg,"[compareTimestampToItself] compare '%-20s' '%s' -> '%-20s' res=%d", inTimestampStr, inTZ, c_out_time_string,compareres); 

		res = compareres;

	}
	else
	{
		sprintf(msg,"[compareTimestampToItself] compare '%-20s' '%s' -> '%-20s' res=%d", inTimestampStr, inTZ, "NO_RESULT", res);
	}

	if ( ! res) 
		log_fine(msg);
	else
		log_critical(msg);

	return res;

} // compareTimestampToSameTZ

int
compareTimestampBackToSameTZ(
	char* inTimestampStr, char* inTimestampFmtStr,
	char* inTZ, char* targetTZ)
{

	int compareres;
	int res;

	char target_timestampstr[40];	/*!< timestamp in the target timezone */
	char back_timestampstr[40];	/*!< timestamp back in the original timezone */

	char msg[TRACE_MESSAGE_MAXLENGTH];

	// calls the conversion function original timezone -> target timezone

	res = condcheckConvertTimestampTZByFmtStr2TZ(
		inTimestampStr, inTimestampFmtStr,
		target_timestampstr, inTimestampFmtStr,
		inTZ, targetTZ, 0);

	if ( ! res )
	{

		// calls the conversion function target timezone -> original timezone

		res = condcheckConvertTimestampTZByFmtStr2TZ(
			target_timestampstr, inTimestampFmtStr,
			back_timestampstr, inTimestampFmtStr,
			targetTZ, inTZ, 0);

		if ( ! res )
		{

			compareres = compareTimestampsNoTZ(back_timestampstr, inTimestampStr);

			sprintf(msg,"[compareTimestampBackToSameTZ] compare '%-20s' '%s' -> '%s' -> '%s' '%-20s' res=%d", inTimestampStr, inTZ, targetTZ, inTZ, back_timestampstr,compareres); 

			res = compareres;

		}
		else
		{
			sprintf(msg,"[compareTimestampBackToSameTZ] compare '%-20s' '%s' -> '%s' -> '%s' '%-20s' res=%d", inTimestampStr, inTZ, targetTZ, inTZ, "NO_RESULT", res);
		}

	}
	else
	{

		sprintf(msg,"[compareTimestampBackToSameTZ] compare '%-20s' '%s' -> '%s' -> '%s' '%-20s' res=%d", inTimestampStr, inTZ, inTZ, targetTZ, "NO_RESULT", res);

	}

	if ( ! res) 
		log_fine(msg);
	else
		log_critical(msg);

	return res;

} // compareTimestampBackToSameTZ

int
checkTimestampConsistency(
	char* inTimestampNoTZStr, char* inTimestampFmtStr,
	char* inTZ)
{

	char msg[TRACE_MESSAGE_MAXLENGTH];

	int res = 0;
	int expectedres = 0;

	res += compareTimestampToSameTZ(inTimestampNoTZStr, inTimestampFmtStr, inTZ);
	res += compareTimestampBackToSameTZ(inTimestampNoTZStr, inTimestampFmtStr, inTZ, EPOCH_TIMEZONE);

	if ( res == expectedres )
	{
		sprintf(msg,"[checkTimestampConsistency] '%s' '%s' is globally consistent res=%d",inTimestampNoTZStr, inTZ,res);
		log_finest(msg);
	}
	else
	{
		sprintf(msg,"[checkTimestampConsistency] '%s' '%s' is NOT consistent res=%d",inTimestampNoTZStr, inTZ,res);
		log_finest(msg);
	}

	return res;

} // checkTimestampConsistency

