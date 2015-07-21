
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

