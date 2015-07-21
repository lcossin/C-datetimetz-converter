
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

