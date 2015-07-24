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

#include <string.h>
#include <stdlib.h>
#include "libdatetimetz_converter_tzanytype.h"

int
main()
{

	char resValue[255];

convertTimestampTZByFmtStr2TZ("2005-03-13T06:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","UTC");
convertTimestampTZByFmtStr2TZ("2005-03-13T06:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Paris");

	return EXIT_SUCCESS;

} // main

