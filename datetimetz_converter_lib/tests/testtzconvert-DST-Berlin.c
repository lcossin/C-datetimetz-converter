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

assert (  convertTimestampTZByFmtStr2TZ("2005-03-13T06:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2005-03-13T07:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2005-03-13T08:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2005-03-13T09:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2005-03-27T00:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2005-03-27T01:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2005-03-27T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2005-03-27T03:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2005-03-27T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2005-03-27T05:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2005-04-03T06:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2005-04-03T08:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2005-04-03T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2005-04-03T09:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2005-10-29T23:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2005-10-30T01:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2005-10-30T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2005-10-30T02:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2005-10-30T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2005-10-30T03:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2005-10-30T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2005-10-30T04:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2005-11-06T06:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2005-11-06T07:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2005-11-06T08:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2005-11-06T09:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2006-03-12T06:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2006-03-12T07:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2006-03-12T08:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2006-03-12T09:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2006-03-26T00:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2006-03-26T01:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2006-03-26T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2006-03-26T03:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2006-03-26T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2006-03-26T05:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2006-04-02T06:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2006-04-02T08:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2006-04-02T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2006-04-02T09:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2006-10-28T23:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2006-10-29T01:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2006-10-29T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2006-10-29T02:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2006-10-29T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2006-10-29T03:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2006-10-29T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2006-10-29T04:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2006-11-05T06:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2006-11-05T07:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2006-11-05T08:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2006-11-05T09:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2007-03-11T06:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2007-03-11T07:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2007-03-11T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2007-03-11T08:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2007-03-25T00:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2007-03-25T01:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2007-03-25T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2007-03-25T03:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2007-03-25T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2007-03-25T05:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2007-04-01T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2007-04-01T07:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2007-04-01T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2007-04-01T09:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2007-10-27T23:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2007-10-28T01:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2007-10-28T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2007-10-28T02:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2007-10-28T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2007-10-28T03:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2007-10-28T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2007-10-28T04:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2007-11-04T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2007-11-04T06:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2007-11-04T08:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2007-11-04T09:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2008-03-09T06:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2008-03-09T07:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2008-03-09T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2008-03-09T08:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2008-03-30T00:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2008-03-30T01:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2008-03-30T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2008-03-30T03:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2008-03-30T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2008-03-30T05:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2008-04-06T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2008-04-06T07:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2008-04-06T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2008-04-06T09:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2008-10-25T23:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2008-10-26T01:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2008-10-26T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2008-10-26T02:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2008-10-26T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2008-10-26T03:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2008-10-26T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2008-10-26T04:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2008-11-02T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2008-11-02T06:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2008-11-02T08:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2008-11-02T09:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2009-03-08T06:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2009-03-08T07:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2009-03-08T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2009-03-08T08:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2009-03-29T00:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2009-03-29T01:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2009-03-29T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2009-03-29T03:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2009-03-29T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2009-03-29T05:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2009-04-05T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2009-04-05T07:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2009-04-05T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2009-04-05T09:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2009-10-24T23:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2009-10-25T01:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2009-10-25T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2009-10-25T02:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2009-10-25T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2009-10-25T03:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2009-10-25T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2009-10-25T04:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2009-11-01T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2009-11-01T06:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2009-11-01T08:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2009-11-01T09:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2010-03-14T06:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2010-03-14T07:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2010-03-14T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2010-03-14T08:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2010-03-28T00:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2010-03-28T01:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2010-03-28T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2010-03-28T03:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2010-03-28T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2010-03-28T05:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2010-04-04T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2010-04-04T07:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2010-04-04T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2010-04-04T09:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2010-10-30T23:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2010-10-31T01:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2010-10-31T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2010-10-31T02:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2010-10-31T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2010-10-31T03:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2010-10-31T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2010-10-31T04:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2010-11-07T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2010-11-07T06:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2010-11-07T08:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2010-11-07T09:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2011-03-13T06:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2011-03-13T07:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2011-03-13T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2011-03-13T08:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2011-03-27T00:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2011-03-27T01:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2011-03-27T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2011-03-27T03:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2011-03-27T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2011-03-27T05:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2011-04-03T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2011-04-03T07:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2011-04-03T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2011-04-03T09:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2011-10-29T23:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2011-10-30T01:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2011-10-30T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2011-10-30T02:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2011-10-30T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2011-10-30T03:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2011-10-30T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2011-10-30T04:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2011-11-06T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2011-11-06T06:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2011-11-06T08:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2011-11-06T09:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2012-03-11T06:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2012-03-11T07:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2012-03-11T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2012-03-11T08:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2012-03-25T00:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2012-03-25T01:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2012-03-25T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2012-03-25T03:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2012-03-25T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2012-03-25T05:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2012-04-01T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2012-04-01T07:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2012-04-01T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2012-04-01T09:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2012-10-27T23:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2012-10-28T01:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2012-10-28T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2012-10-28T02:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2012-10-28T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2012-10-28T03:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2012-10-28T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2012-10-28T04:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2012-11-04T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2012-11-04T06:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2012-11-04T08:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2012-11-04T09:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2013-03-10T06:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2013-03-10T07:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2013-03-10T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2013-03-10T08:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2013-03-31T00:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2013-03-31T01:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2013-03-31T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2013-03-31T03:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2013-03-31T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2013-03-31T05:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2013-04-07T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2013-04-07T07:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2013-04-07T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2013-04-07T09:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2013-10-26T23:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2013-10-27T01:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2013-10-27T00:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2013-10-27T02:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2013-10-27T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2013-10-27T03:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2013-10-27T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2013-10-27T04:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2013-11-03T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2013-11-03T06:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2013-11-03T08:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2013-11-03T09:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2014-03-09T06:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2014-03-09T07:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2014-03-09T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2014-03-09T08:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2014-03-30T00:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2014-03-30T01:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2014-03-30T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2014-03-30T03:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2014-03-30T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2014-03-30T04:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2014-04-06T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2014-04-06T07:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2014-04-06T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2014-04-06T09:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2014-10-25T23:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2014-10-26T01:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2014-10-26T00:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2014-10-26T02:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2014-10-26T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2014-10-26T03:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2014-10-26T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2014-10-26T04:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2014-11-02T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2014-11-02T06:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2014-11-02T08:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2014-11-02T09:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-03-08T06:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-03-08T07:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-03-08T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-03-08T08:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-03-29T00:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-03-29T01:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-03-29T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-03-29T03:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-03-29T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-03-29T04:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-04-05T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-04-05T07:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-04-05T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-04-05T09:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-06-13T00:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-06-13T02:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-06-13T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-06-13T04:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-06-14T00:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-06-14T02:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-06-14T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-06-14T05:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-07-18T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-07-18T03:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-07-18T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-07-18T05:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-07-19T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-07-19T03:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-07-19T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-07-19T04:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-10-24T23:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-10-25T01:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-10-25T00:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-10-25T02:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-10-25T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-10-25T03:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-10-25T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-10-25T04:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-11-01T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-11-01T06:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2015-11-01T08:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2015-11-01T09:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2016-03-13T06:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2016-03-13T07:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2016-03-13T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2016-03-13T08:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2016-03-27T00:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2016-03-27T01:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2016-03-27T01:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2016-03-27T03:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2016-03-27T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2016-03-27T04:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2016-04-03T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2016-04-03T07:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2016-04-03T07:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2016-04-03T09:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2016-10-29T23:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2016-10-30T01:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2016-10-30T00:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2016-10-30T02:00:00 +0200") ); 
assert (  convertTimestampTZByFmtStr2TZ("2016-10-30T02:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2016-10-30T03:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2016-10-30T03:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2016-10-30T04:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2016-11-06T05:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2016-11-06T06:00:00 +0100") ); 
assert (  convertTimestampTZByFmtStr2TZ("2016-11-06T08:00:00","%Y-%m-%dT%H:%M:%S",resValue,"%Y-%m-%dT%H:%M:%S %z","+0000","Europe/Berlin") == 0 && ! strcmp(resValue,"2016-11-06T09:00:00 +0100") ); 

	return EXIT_SUCCESS;

} // main

