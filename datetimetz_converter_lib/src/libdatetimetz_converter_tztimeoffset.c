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
#include "libdatetimetz_converter_timestampverifier.h"
#include "libdatetimetz_converter_tztimeoffset.h"

int
isUTCTimeOffsetTZ(char *TZval)
{

	char msg[TRACE_MESSAGE_MAXLENGTH];
	char traceprog[TRACE_MESSAGE_MAXLENGTH];
	strcpy(traceprog,__FUNCTION__);

	sprintf(msg,"entering TZval=%s", TZval);
	log_debug(__FUNCTION__, msg);

	int res;

	int regexp_res1;
	int regexp_res2;

	regexp_res1 = regexp_verify(TZval, UTCSPECIALOFFSETTZREGEXP);
	regexp_res2 = regexp_verify(TZval, UTCOFFSETTZREGEXP);

	res = ( regexp_res1 == UTCSPECIALOFFSETTZREGEXPEXPECTEDMATCHES )
			|| 
				( regexp_res2 >= UTCOFFSETTZREGEXPEXPECTEDMATCHES_MIN && regexp_res2 <= UTCOFFSETTZREGEXPEXPECTEDMATCHES_MAX );

	if ( res )
	{
		sprintf(msg, "%s is a valid UTC time offset", TZval); log_finest(__FUNCTION__, msg);
		res = EXIT_SUCCESS;
	}
	else
	{
		sprintf(msg, "%s is a NOT valid UTC time offset",TZval); log_critical(__FUNCTION__, msg);
		res = EXIT_FAILURE;
	}

	sprintf(msg,"leaving TZval=%s", TZval);
	log_debug(__FUNCTION__, msg);

	return res;

} // isUTCTimeOffsetTZ


int
isTimeOffsetTZ(char *TZval)
{

	char msg[TRACE_MESSAGE_MAXLENGTH];
	char traceprog[TRACE_MESSAGE_MAXLENGTH];
	strcpy(traceprog,__FUNCTION__);

	sprintf(msg,"entering TZval=%s", TZval);
	log_debug(__FUNCTION__, msg);

	int res;

	int regexpres1;

	int regexpres2;

	regexpres1 = regexp_verify(TZval, OFFSETTZREGEXP);
	regexpres2 = regexp_verify(TZval, UTCWRONGOFFSETTZREGEXP);

	res = ( regexpres1 >= OFFSETTZREGEXPEXPECTEDMATCHES_MIN && regexpres1 <= OFFSETTZREGEXPEXPECTEDMATCHES_MAX )
				&& 
				!( regexpres2 >= UTCWRONGOFFSETTZREGEXPEXPECTEDMATCHES_MIN && regexpres2 <= UTCWRONGOFFSETTZREGEXPEXPECTEDMATCHES_MAX );

	if ( res )
	{
		sprintf(msg, "%s is a valid time offset",TZval); log_finest(__FUNCTION__, msg);
		res = EXIT_SUCCESS;
	}
	else
	{
		sprintf(msg, "%s is a NOT valid time offset",TZval); log_critical(__FUNCTION__, msg);
		res = EXIT_FAILURE;
	}

	sprintf(msg,"leaving TZval=%s", TZval);
	log_debug(__FUNCTION__, msg);

	return res;

} // isTimeOffsetTZ

/// Converts a time offset TZ to seconds

int
convertTimeOffsetToSeconds(char *TZval,int *offsetSeconds)
{

	char msg[TRACE_MESSAGE_MAXLENGTH];
	char traceprog[TRACE_MESSAGE_MAXLENGTH];
	strcpy(traceprog,__FUNCTION__);

	int res;

	sprintf(msg,"entering TZval=%s", TZval);
	log_debug(__FUNCTION__, msg);

	if ( isUTCTimeOffsetTZ(TZval) == EXIT_SUCCESS ) 
	{
		*offsetSeconds = 0;
		res = EXIT_SUCCESS;
	}
	else 
	{
		if ( isTimeOffsetTZ(TZval) == EXIT_SUCCESS )
		{
			splitconvertTimeOffsetStrToValues(TZval, offsetSeconds);
			res = EXIT_SUCCESS;
		}
		else
		{
			res = EXIT_FAILURE;
		}
	}

	sprintf(msg,"leaving TZval=%s", TZval);
	log_debug(__FUNCTION__, msg);

	return res;

} //convertTimeOffsetToSeconds

int
splitTimeOffsetStrToValues(char *timeoffsetstr, int *signfactor, int *hours, int *minutes)
{

	char msg[TRACE_MESSAGE_MAXLENGTH];
	char traceprog[TRACE_MESSAGE_MAXLENGTH];
	strcpy(traceprog,__FUNCTION__);

	int res;

	char timepart[3];

	int minutespos;

	sprintf(msg,"entering TZval=%s hours=%d minutes=%d sign=%d", timeoffsetstr, *hours, *minutes, *signfactor);
	log_debug(__FUNCTION__, msg);

	/// timeoffsetstr can be [sign][hh][mm] or [sign][hh]:[mm]
	/// hours are the 2 first digits (after the leading sign)
	/// minutes are the 2 trailing digits

	minutespos = strlen(timeoffsetstr) - 2;

	/// extracts the sign of the offset

	memset(timepart,'\0',sizeof(timepart)); strncpy(timepart, timeoffsetstr, 1);
	if ( ! strcmp(timepart,"+") ) // time offset starts with '+'
		*signfactor = 1;
	else
		*signfactor = -1;

	memset(timepart,'\0',sizeof(timepart)); strncpy(timepart, timeoffsetstr+1, 2); *hours = atoi(timepart);

	sprintf(msg,"TZval=%s timepart=%s hours=%d", timeoffsetstr, timepart, *hours);
	log_debug(__FUNCTION__, msg);

	memset(timepart,'\0',sizeof(timepart)); strncpy(timepart, timeoffsetstr+minutespos, 2); *minutes = atoi(timepart);

	sprintf(msg,"TZval=%s timepart=%s minutes=%d", timeoffsetstr, timepart, *minutes);
	log_debug(__FUNCTION__, msg);

	sprintf(msg,"leaving TZval=%s hours=%d minutes=%d sign=%d", timeoffsetstr, *hours, *minutes, *signfactor);
	log_debug(__FUNCTION__, msg);


	res = EXIT_SUCCESS;

	return res;

} // splitTimeOffsetStrToValues

int
splitconvertTimeOffsetStrToValues(char *timeoffsetstr, int *timeoffsetseconds)
{

	char msg[TRACE_MESSAGE_MAXLENGTH];
	char traceprog[TRACE_MESSAGE_MAXLENGTH];
	strcpy(traceprog,__FUNCTION__);

	int res;

	int signfactor;
	int hours;
	int minutes;

	splitTimeOffsetStrToValues(timeoffsetstr, &signfactor, &hours, &minutes);

	*timeoffsetseconds = signfactor * ( hours * 3600 + minutes * 60 );

	res = EXIT_SUCCESS;

	sprintf(msg,"leaving TZval=%s timeoffsetseconds=%d hours=%d minutes=%d sign=%d", timeoffsetstr, *timeoffsetseconds, hours, minutes, signfactor);
	log_debug(__FUNCTION__, msg);

	return res;

} // splitconvertTimeOffsetStrToValues

