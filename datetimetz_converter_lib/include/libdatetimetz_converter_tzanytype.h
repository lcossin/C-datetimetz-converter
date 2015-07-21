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

/**
 * @file libdatetimetz_converter_tzanytype.h
 * @author Laurent Cossin
 * @date   July 2015
 *
 * @ingroup datetimetz_converter
 *
 * @brief Provides some functions to handle timestamps defined with any type of timezone
 *
*/

#ifndef TZANYTYPE_HEADERS

#define TZANYTYPE_HEADERS

#include <time.h>
#include "libdatetimetz_converter_parameter.h"

/// converts a timestamp given as a string in a timezone to Epoch

/**
    converts a timestamp given as a string in a TZ to Epoch (time_t)

    input   : inTimestampStr, inTZ
    output  : epochtimet (time_t)

*/

int 
convertTimestampTZByFmtStr2Epochtimet(
  char* inTimestampStr,char* inTimestampFmtStr,
  char* inTZ,
  time_t *epochtimet);

/// conditional checkings, then converts

int 
condcheckConvertTimestampTZByFmtStr2TZ( 
 char* inTimestampStr,char* inTimestampFmtStr, 
 char* outTimestampStr, char* outTimestampFmtStr, 
 char* inTZ,char* outTZ, int DoCheck );

/// converts a timestamp given as a string and the timezone to another timezone

/**

    converts a timestamp given as a string (inTimeStr) and its timezone (inTZ)
    to another timezone (targetTZ)

    input   : inTimeStr - timestamp given for the timezone inTZ,
              targetTZ - target timezone

    output  : targetTimeStr - timestamp converted to the target timezone targetTZ

*/

int 
convertTimestampTZByFmtStr2TZ(
 char* inTimestampStr,char* inTimestampFmtStr,
 char* targetTimestampStr, char* targetTimestampFmtStr,
 char* inTZ,char* targetTZ);

/// converts a timestamp in an TZ in a custom format to a timestamp in an TZ in a custom format

/**
    converts a given timestamp in a format (inTimestampFmt) and TZ (inTZ)
    to a timestamp in a format (targetTimestampFmt) in an TZ (targetTZ)
*/

int 
convertTimestampTZByFmt2TZ(
 char* inTimestampStr,int inTimestampFmt,
 char* targetTimestampStr, int targetTimestampFmt,
 char* inTZ,char* targetTZ);

/// converts an ISO8601 timestamp in a TZ to an ISO8601 timestamp in a TZ

/**
    converts a given timestamp in ISO8601 format and a TZ (inTZ)
    to a timestamp in ISO8601 format in a TZ (targetTZ)
*/

int 
convertISOTimestampTZ2TZ(
 char* inTimestampStr,
 char* targetTimestampStr,
 char* inTZ,char* targetTZ);

#endif
