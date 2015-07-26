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

/**
 * @file libdatetimetz_converter_dataparsetimestamps.h
 * @author Laurent Cossin
 * @copyright GNU Lesser General Public License

 * @date   July 2015
 *
 * @ingroup datetimetz_converter_helper
 *
 * @brief Provides some functions to handle the data for tests
 *
*/

#ifndef DATAPARSETIMESTAMPS_HEADERS

	#define DATAPARSETIMESTAMPS_HEADERS

	#ifndef DATATYPES_HEADERS
		#include "libdatetimetz_converter_datatypes.h"
	#endif

/// parses a row from the input file

int 
parseRawString(
	char* rawTimestampTZStr, 
	char* outTimestampStrNoTZ, char* outOlsonTZ);

#endif

