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

#include "libdatetimetz_converter_consistency.h"
#include "libdatetimetz_converter_prereqs.h"

int 
isTimestampConsistentorAbort(
	char *timestamp, char *timestampformat,
	char *timezone,
	int abortOnFailure
)
{

	int res;

	char msg[TRACE_MESSAGE_MAXLENGTH];

	sprintf(msg,"entering isTimestampConsistentorAbort abortOnFailure=%d",abortOnFailure);
	log_debug(msg);

	res = checkTimestampConsistency(timestamp, timestampformat, timezone);

	if ( ! res )
	{
		sprintf(msg, "[isTimestampConsistentorAbort] %s %s is a valid timestamp",timestamp,timezone);
		log_finest(msg);
	}
	else
	{
		sprintf(msg, "[isTimestampConsistentorAbort] %s %s is a wrong timestamp",timestamp,timezone);
		log_critical(msg);
		if ( abortOnFailure )
			abort();
	}

	sprintf(msg,"leaving isTimestampConsistentorAbort abortOnFailure=%d",abortOnFailure);
	log_debug(msg);

	return res;

} // isTimestampConsistentorAbort

