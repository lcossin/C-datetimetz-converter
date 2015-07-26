/*
    This file is part of datetimetz_converter_demo.

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

#include "libdatetimetz_converter_dataparsetimestamps.h"

int 
parseRawString(
	char* rawTimestampTZStr, 
	char* outTimestampStrNoTZ, char* outTZ)
{

	// stores the parsed string using strtok
	char tmpStr[RAWTIMESTAMPMAXLENGTH];

	char* inDatenoTZ;
	char* inTimenoTZ;

	log_debug(__FUNCTION__, "starting");
	log_debug(__FUNCTION__, rawTimestampTZStr);

	// duplicates the input string to the temporary string

	strcpy(tmpStr,rawTimestampTZStr);

	// split the temporary string

	// first part : date

  inDatenoTZ = strtok(tmpStr," ");	

	log_debug(__FUNCTION__, inDatenoTZ);

	// next : time

  inTimenoTZ = strtok(NULL," ");	

	log_debug(__FUNCTION__, inTimenoTZ);

	// next : timezone

  strcpy(outTZ,strtok(NULL," "));	

	log_debug(__FUNCTION__, outTZ);

	// concatenate date + time to outTimestampStrNoTZ - output argument

	sprintf(outTimestampStrNoTZ,"%sT%s",inDatenoTZ,inTimenoTZ);

	log_debug(__FUNCTION__, "leaving"); 

	return EXIT_SUCCESS;

} // parseRawString

