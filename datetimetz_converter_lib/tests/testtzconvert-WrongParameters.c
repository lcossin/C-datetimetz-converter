/*
    This file is part of datetimetz_converter_demo.

    Copyright (C) 2015 Laurent Cossin

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; version 2 of the License.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License along
    with this program; if not, write to the Free Software Foundation, Inc.,
    51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
*/

#include <assert.h>
#include <string.h>
#include <stdlib.h>
#include "libdatetimetz_converter_tzanytype.h"

int
main()
{

	char resValue[255];

// null input timestamp
assert (  convertTimestampTZByFmtStr2TZ("","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","Europe/Berlin","Europe/Berlin") != 0 ) ;

// null input timezone
assert (  convertTimestampTZByFmtStr2TZ("2016-03-27T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","","Europe/Berlin") != 0 ) ;

// null target timezone
assert (  convertTimestampTZByFmtStr2TZ("2016-03-27T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","Europe/Berlin","") != 0 ) ;

// null input format
assert (  convertTimestampTZByFmtStr2TZ("2016-03-27T02:00:00","",resValue,"%Y-%m-%dT%H:%M:%S %z","Europe/Berlin","Europe/Berlin") != 0 ) ;

// null output format
assert ( convertTimestampTZByFmtStr2TZ("2016-03-27T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"","Europe/Berlin","") != 0 ) ;

	return EXIT_SUCCESS;

} // main

