/*
		This file is part of libdatetimetz_converter.

    Copyright (C) 2015 Laurent Cossin

    This library is free software; you can redistribute it and/or
    modify it under the terms of the GNU Lesser General Public
    License as published by the Free Software Foundation; either
    version 2.1 of the License, or (at your option) any later version.

    This library is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public
    License along with this library; if not, write to the Free Software
    Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA
*/

/**
 * @file libdatetimetz_converter_epoch.h
 * @author Laurent Cossin
 * @date   July 2015
 *
 * @ingroup datetimetz_converter
 *
 * @brief Provides some functions to convert timestamp to Epoch
 *
*/

#ifndef EPOCH_HEADERS

	#define EPOCH_HEADERS

/// converts a timestamp string to a time_t Epoch (inherits TZ environment variable)

/**
		converts timestamp string to time_t Epoch

		inherits	: TZ environment variable

		input		: inTimestampStr + inTimestampFmtStr
		output	: epochtimet (time_t)

*/

int 
convertTimestampStr2Epochtimet(
        char* inTimestampStr, char* inTimestampFmtStr,
        time_t *epochtimet
);

#endif

