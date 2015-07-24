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

assert (  convertTimestampTZByFmtStr2TZ("2005-03-27T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","Europe/Berlin","Europe/Berlin") != 0 ) ;
assert (  convertTimestampTZByFmtStr2TZ("2006-03-26T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","Europe/Berlin","Europe/Berlin") != 0 ) ;
assert (  convertTimestampTZByFmtStr2TZ("2007-03-25T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","Europe/Berlin","Europe/Berlin") != 0 ) ;
assert (  convertTimestampTZByFmtStr2TZ("2008-03-30T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","Europe/Berlin","Europe/Berlin") != 0 ) ;
assert (  convertTimestampTZByFmtStr2TZ("2009-03-29T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","Europe/Berlin","Europe/Berlin") != 0 ) ;
assert (  convertTimestampTZByFmtStr2TZ("2010-03-28T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","Europe/Berlin","Europe/Berlin") != 0 ) ;
assert (  convertTimestampTZByFmtStr2TZ("2011-03-27T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","Europe/Berlin","Europe/Berlin") != 0 ) ;
assert (  convertTimestampTZByFmtStr2TZ("2012-03-25T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","Europe/Berlin","Europe/Berlin") != 0 ) ;
assert (  convertTimestampTZByFmtStr2TZ("2013-03-31T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","Europe/Berlin","Europe/Berlin") != 0 ) ;
assert (  convertTimestampTZByFmtStr2TZ("2014-03-30T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","Europe/Berlin","Europe/Berlin") != 0 ) ;
assert (  convertTimestampTZByFmtStr2TZ("2015-03-29T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","Europe/Berlin","Europe/Berlin") != 0 ) ;
assert (  convertTimestampTZByFmtStr2TZ("2016-03-27T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","Europe/Berlin","Europe/Berlin") != 0 ) ;

	return EXIT_SUCCESS;

} // main

