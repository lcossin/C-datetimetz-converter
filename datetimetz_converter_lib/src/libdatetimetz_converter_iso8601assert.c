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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libtrace.h"

#include "libdatetimetz_converter_iso8601verifier.h"
#include "libdatetimetz_converter_parameter.h"
#include "libdatetimetz_converter_iso8601assert.h"


int
assert_isISO8601noTZ(char *strval)
{

	log_debug(__FUNCTION__,"entering");

	int res;

	char msg[TRACE_MESSAGE_MAXLENGTH];

	res = isISO8601noTZ(strval);

	if ( ! res )
	{
		sprintf(msg, "[assert_isISO8601noTZ] %s is a valid ISO8601 timestamp",strval);
		log_finest(__FUNCTION__, msg);
	}
	else
	{
		sprintf(msg, "[assert_isISO8601noTZ] %s is NOT a valid ISO8601 timestamp",strval);
		log_critical(__FUNCTION__, msg);
		if (actionOnFailureOpts)
			abort();
	}

	log_debug(__FUNCTION__,"leaving");

	return res;

} // assert_isISO8601noTZ

int
assert_isISO8601TZ(char *timestamp, char *timezone)
{

	int res;

	char msg[TRACE_MESSAGE_MAXLENGTH];

	log_debug(__FUNCTION__,"entering");

	res = assert_isISO8601noTZ(timestamp);

	if ( ! res )
	{

		res = checkISOTimestampTZConsistency(timestamp, timezone);

		if ( ! res )
		{
			sprintf(msg, "[assert_isISO8601TZ] %s %s is a valid ISO8601 timestamp",timestamp,timezone);
			log_finest(__FUNCTION__, msg);
		}
		else
		{
			sprintf(msg, "[assert_isISO8601TZ] %s %s is a wrong ISO8601 timestamp",timestamp,timezone);
			log_critical(__FUNCTION__, msg);
			if ( actionOnFailureOpts )
				abort();
		}

	}

	log_debug(__FUNCTION__,"leaving");

	return res;

} // assert_isISO8601TZ

