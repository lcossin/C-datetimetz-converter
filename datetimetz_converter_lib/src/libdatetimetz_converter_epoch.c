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

#include "config.h"
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libtrace.h"
#include "libdatetimetz_converter_timestamptzformat.h"
#include "libdatetimetz_converter_epoch.h"

int 
convertTimestampStr2Epochtimet(
	char* inTimestampStr,char* inTimestampFmtStr,
	time_t *epochtimet
)
{

	struct tm		inTM;
	struct tm		*ptrinTM = &inTM;

	log_debug("entering convertTimestampStr2Epoch");

	// initialize the tm structure for the input timestamp
	// ptrinTM = pointer to the inTM structure object

	// reset the DST flag - from a previous run, if any

	ptrinTM->tm_isdst = -1;

	// set the attributes of the tm struct (inTM)

	//strptime_res = strptime(inTimestampStr, inTimestampFmtStr, ptrinTM);	
	strptime(inTimestampStr, inTimestampFmtStr, ptrinTM);	

	// return the Epoch value from the tm struct object
	*epochtimet = mktime(ptrinTM);

	/* for debugging */

	/*

	char c_time_string[40];
	char msg[4000];

	// reverse : textual string of the timestamp in inTM

	strftime(c_time_string,40,"%Y-%m-%d %T %4Z %z", ptrinTM);
	sprintf(msg,"{%s - DST %d} \t",c_time_string,ptrinTM->tm_isdst);
	log_debug(msg);

	*/

	log_debug("leaving convertTimestampStr2Epoch");
	
	return EXIT_SUCCESS;

} // convertTimestampStr2Epochtimet

