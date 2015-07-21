
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

