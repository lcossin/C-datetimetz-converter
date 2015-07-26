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

#include "libdatetimetz_converter_timestampverifier.h"
#include "libdatetimetz_converter_assert.h"

int 
assert_TimestampTZIsValid(
	char *timestamp, char *timestampformat,
	char *timezone,
	int abortOnFailure
)
{

	int res;

	char msg[TRACE_MESSAGE_MAXLENGTH];

	sprintf(msg,"entering abortOnFailure=%d",abortOnFailure);
	log_debug(__FUNCTION__, msg);

	res = checkTimestampConsistency(timestamp, timestampformat, timezone);

	if ( ! res )
	{
		sprintf(msg, "[assert_TimestampTZIsValid] %s %s is a valid timestamp",timestamp,timezone);
		log_finest(__FUNCTION__, msg);
	}
	else
	{
		sprintf(msg, "[assert_TimestampTZIsValid] %s %s is a wrong timestamp",timestamp,timezone);
		log_critical(__FUNCTION__, msg);
		if ( abortOnFailure )
			abort();
	}

	sprintf(msg,"leaving abortOnFailure=%d",abortOnFailure);
	log_debug(__FUNCTION__, msg);

	return res;

} // assert_TimestampTZIsValid

