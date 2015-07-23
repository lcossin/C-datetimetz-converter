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

#include "config.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libtrace.h"
#include "libassert_custom.h"

#include "libdatetimetz_converter_timestamptzformat.h"
#include "libdatetimetz_converter_epoch.h"
#include "libdatetimetz_converter_tzanytype.h"
#include "libdatetimetz_converter_iso8601assert.h"
#include "libdatetimetz_converter_iso8601verifier.h"
#include "libdatetimetz_converter_tztimeoffset.h"
#include "libdatetimetz_converter_assert.h"

int 
convertTimestampTZByFmtStr2Epochtimet( 
	char* inTimestampStr,char* inTimestampFmtStr,
	char* inTZ, 
	time_t *epochtimet)
{

	int assert_res = 0;
	assert_res += assert_string_is_not_null(inTimestampStr,"[convertTimestampTZByFmtStr2Epochtimet] inTimestampStr");
	assert_res += assert_string_is_not_null(inTimestampFmtStr,"[convertTimestampTZByFmtStr2Epochtimet] inTimestampFmtStr");
	assert_res += assert_string_is_not_null(inTZ,"[convertTimestampTZByFmtStr2Epochtimet] inTZ");
	if ( assert_res )
		return EXIT_FAILURE;

	char msg[TRACE_MESSAGE_MAXLENGTH];
	char envTZbackup[TIMESTAMPMAXLENGTH];

	log_debug("entering convertTimestampTZByFmtStr2Epochtimet");

	int timeoffsetres;
	int timeoffsetseconds;
	char inTZeff[TIMESTAMPMAXLENGTH];

	int res;

	// backup the current value of the TZ environment variable

	if ( getenv(TZ_ENV_VARNAME) )
		strcpy(envTZbackup,getenv(TZ_ENV_VARNAME));
	else
		strcpy(envTZbackup,DEFAULT_TIMEZONE);

	sprintf(msg,"[convertTimestampTZByFmtStr2Epoch] TZ=%s inTimestampStr=%s inTZ=%s",envTZbackup,inTimestampStr,inTZ);
	log_debug(msg);

	// set TZ environment variable according to the input timestamp 
  //	if inTZ=UTC then set TZ to empty value
  //	otherwise set TZ with the value of inTZ

  if ( strcmp(inTZ,EPOCH_TIMEZONE) == EXIT_SUCCESS )
	{
		strcpy(inTZeff,"");
		timeoffsetres = EXIT_FAILURE;
	}
	else
	{
		timeoffsetres = convertTimeOffsetToSeconds(inTZ, &timeoffsetseconds);

		if ( timeoffsetres != EXIT_SUCCESS ) 
			strcpy(inTZeff,inTZ);
		else
			strcpy(inTZeff,"");

	}

	setenv(TZ_ENV_VARNAME,inTZeff,1);

	sprintf(msg,"[convertTimestampTZByFmtStr2Epoch] inTimestampStr=%s inTZ=%s effTZ=%s",inTimestampStr,inTZ,inTZeff);
	log_debug(msg);


	// set the Epoch value for the given timestamp
	res = convertTimestampStr2Epochtimet(inTimestampStr,inTimestampFmtStr,epochtimet);

	if ( timeoffsetres == EXIT_SUCCESS )
	{
		(*epochtimet) -= timeoffsetseconds;
	}

	// restore the initial value of the  TZ environment variable 
	setenv(TZ_ENV_VARNAME,envTZbackup,1);

	sprintf(msg,"leaving convertTimestampTZByFmtStr2Epoch TZ=%s res=%d",envTZbackup,res);
	log_debug(msg);

	return res;

} // convertTimestampTZByFmtStr2Epochtimet


int 
condcheckConvertTimestampTZByFmtStr2TZ( 
 char* inTimestampStr,char* inTimestampFmtStr, 
 char* targetTimestampStr, char* targetTimestampFmtStr, 
 char* inTZ,char* targetTZ, int DoCheck )
{

	int assert_res = 0;
	assert_res += assert_string_is_not_null(inTimestampStr,"[condcheckConvertTimestampTZByFmtStr2TZ] inTimestampStr");
	assert_res += assert_string_is_not_null(inTimestampFmtStr,"[condcheckConvertTimestampTZByFmtStr2TZ] inTimestampFmtStr");
	assert_res += assert_string_is_not_null(targetTimestampFmtStr,"[condcheckConvertTimestampTZByFmtStr2TZ] inTimestampFmtStr");
	assert_res += assert_string_is_not_null(inTZ,"[condcheckConvertTimestampTZByFmtStr2TZ] inTZ");
	assert_res += assert_string_is_not_null(targetTZ,"[condcheckConvertTimestampTZByFmtStr2TZ] targetTZ");
	if ( assert_res )
		return EXIT_FAILURE;

	char msg[TRACE_MESSAGE_MAXLENGTH];
	char envTZbackup[TIMESTAMPMAXLENGTH];

	int timeoffsetres;
	int timeoffsetseconds;

	char targetTZeff[TIMESTAMPMAXLENGTH]; // effectiv target timezone

	int res = 0;

	// stores the result in a tm strut
  struct tm *outTM;

	// stores the epoch for the input timestamp
	time_t epoch_time;

	log_debug("entering condcheckconvertTimestampTZByFmtStr2TZ");

	sprintf(msg,"[condcheckconvertTimestampTZByFmtStr2TZ] inTimestampStr=%s inTZ=%s targetTZ=%s",inTimestampStr, inTZ, targetTZ);
	log_debug(msg);

	if ( DoCheck )
		res = assert_TimestampTZIsValid(inTimestampStr, inTimestampFmtStr, inTZ, actionOnFailureOpts);

	if ( ! res )
	{

		// convert input timestamp to Epoch
			
		res = convertTimestampTZByFmtStr2Epochtimet(inTimestampStr,inTimestampFmtStr,inTZ,&epoch_time);	

		// convert Epoch to the target timezone

	timeoffsetres = convertTimeOffsetToSeconds(targetTZ, &timeoffsetseconds);

	// backup the current settings
	if ( getenv(TZ_ENV_VARNAME) )
		strcpy(envTZbackup,getenv(TZ_ENV_VARNAME));
	else
		strcpy(envTZbackup,DEFAULT_TIMEZONE);

	if ( timeoffsetres != EXIT_SUCCESS ) // not a TZ time offset
	{
		sprintf(msg,"[condcheckconvertTimestampTZByFmtStr2TZ] [ZONEINFO] epoch_time=%zu inTimestampStr=%s inTZ=%s targetTZ=%s", epoch_time,inTimestampStr, inTZ, targetTZ);
	log_debug(msg);

		strcpy(targetTZeff,targetTZ);

	}
	else
	{
		sprintf(msg,"[condcheckconvertTimestampTZByFmtStr2TZ] [TIMEOFFSET] epoch_time=%zu timeoffsetseconds=%d inTimestampStr=%s inTZ=%s targetTZ=%s", epoch_time,timeoffsetseconds, inTimestampStr, inTZ, targetTZ);
		log_debug(msg);

		strcpy(targetTZeff,"");

		epoch_time += timeoffsetseconds;

	}

	sprintf(msg,"[condcheckconvertTimestampTZByFmtStr2TZ] [MAIN] epoch_time=%zu requested targetTZ=%s effectiv targetTZ=%s ",epoch_time, targetTZ, targetTZeff);
	log_debug(msg);

	// set TZ settings to the target TZ (effectiv targetTZ)
	setenv(TZ_ENV_VARNAME,targetTZeff,1);

	outTM = localtime(&epoch_time);

	// format the output string

	if ( timeoffsetres == EXIT_SUCCESS && strchr(targetTimestampFmtStr,'z') )
	{

		char customFmtStr[255];

		sprintf(customFmtStr,"%s %s","%Y-%m-%dT%H:%M:%S",targetTZ);

		strftime(targetTimestampStr,255,customFmtStr, outTM);

	}
	else
	{

	// format the output string

	strftime(targetTimestampStr,255,targetTimestampFmtStr, outTM);

	}

		// restore the TZ settings
		setenv(TZ_ENV_VARNAME,envTZbackup,1);

	} // if after assert_TimestampTZIsValid

	sprintf(msg,"leaving condcheckconvertTimestampTZByFmtStr2TZ res=%d", res);
	log_debug(msg);

	return res;

} // condcheckConvertTimestampTZByFmtStr2TZ


int 
convertTimestampTZByFmtStr2TZ( 
 char* inTimestampStr,char* inTimestampFmtStr, 
 char* targetTimestampStr, char* targetTimestampFmtStr, 
 char* inTZ,char* targetTZ)
{

	int assert_res = 0;
	assert_res += assert_string_is_not_null(inTimestampStr,"[convertTimestampTZByFmtStr2TZ] inTimestampStr");
	assert_res += assert_string_is_not_null(inTimestampFmtStr,"[convertTimestampTZByFmtStr2TZ] inTimestampFmtStr");
	assert_res += assert_string_is_not_null(targetTimestampFmtStr,"[convertTimestampTZByFmtStr2TZ] inTimestampFmtStr");
	assert_res += assert_string_is_not_null(inTZ,"[convertTimestampTZByFmtStr2TZ] inTZ");
	assert_res += assert_string_is_not_null(targetTZ,"[convertTimestampTZByFmtStr2TZ] targetTZ");
	if ( assert_res )
		return EXIT_FAILURE;

	char msg_part1[TRACE_MESSAGE_MAXLENGTH];
	char msg[TRACE_MESSAGE_MAXLENGTH];
	int res;

	log_debug("[convertTimestampTZByFmtStr2TZ] entering convertTimestampTZByFmtStr2TZ");

	res = condcheckConvertTimestampTZByFmtStr2TZ(
		inTimestampStr, inTimestampFmtStr,
		targetTimestampStr, targetTimestampFmtStr,
		inTZ, targetTZ, 1);

	sprintf(msg,"[convertTimestampTZByFmtStr2TZ] [CALL] convertTimestampTZByFmtStr2TZ("
		"\"%s\","
		"\"%s\","
		"%s,"
		"\"%s\","
		"\"%s\","
		"\"%s\""
		") == %d"
		,
		inTimestampStr, inTimestampFmtStr,
		"resValue", targetTimestampFmtStr,
		inTZ, targetTZ,
		res
	); 

	if ( ! res )
	{
		strcpy(msg_part1, msg);
		sprintf(msg,"%s && ! strcmp(resValue,\"%s\")", msg_part1,targetTimestampStr);
	}

	log_debug(msg);

	sprintf(msg,"[convertTimestampTZByFmtStr2TZ] leaving convertTimestampTZByFmtStr2TZ res=%d",res);
	log_debug(msg);

	return res;

} // convertTimestampTZByFmtStr2TZ


int 
convertTimestampTZByFmt2TZ(
 char* inTimestampStr, int inTimestampFmt,
 char* targetTimestampStr, int targetTimestampFmt,
 char* inTZ, char* targetTZ)
{

	char msg[TRACE_MESSAGE_MAXLENGTH];
	int res;

  char* fmtin;
  char* fmtout;

	int assert_res = 0;

  fmtin  = (char *) malloc(1);
	assert_res += assert_pointer_is_not_null(fmtin,"[convertTimestampByFmtTZ2TZ] fmtin");

  fmtout = (char *) malloc(1);
	assert_res += assert_pointer_is_not_null(fmtout,"[convertTimestampByFmtTZ2TZ] fmtout");

	if ( assert_res )
		return EXIT_FAILURE;

	log_debug("[convertTimestampTZ2TZ] entering convertTimestampByFmtTZ2TZ");

  buildFmtStr(inTimestampFmt,		fmtin);
  buildFmtStr(targetTimestampFmt,	fmtout);

  sprintf(msg, "[convertTimestampByFmtTZ2TZ] in=%d fmtin=%s\n",	inTimestampFmt,	fmtin);
	log_debug(msg);

  sprintf(msg, "[convertTimestampByFmtTZ2TZ] out=%d fmtout=%s\n",targetTimestampFmt,fmtout);
	log_debug(msg);

	res = convertTimestampTZByFmtStr2TZ(
		inTimestampStr, fmtin,
		targetTimestampStr, fmtout,
		inTZ, targetTZ
	);

	sprintf(msg,"[convertTimestampTZ2ByFmtTZ] [CALL] convertTimestampTZ2TZ("
		"\"%s\","
		"%d,"
		"\"%s\","
		"%d,"
		"\"%s\","
		"\"%s\","
		") == %d"
		,
		inTimestampStr, inTimestampFmt,
		targetTimestampStr, targetTimestampFmt,
		inTZ, targetTZ,
		res
	); log_debug(msg);

	// release the memory for the local temporary strings (malloc is this function)
	free(fmtin);
	free(fmtout);

	sprintf(msg,"[convertTimestampByFmtTZ2TZ] leaving convertTimestampByFmtTZ2TZ res=%d",res);
	log_debug(msg);

	return res;

} // convertTimestampByFmtTZ2TZ


int 
convertISOTimestampTZ2TZ(
 char* inTimestampStr,
 char* targetTimestampStr,
 char* inTZ,char* targetTZ)
{

	char msg[TRACE_MESSAGE_MAXLENGTH];
	int res;

  int optsin;
  int optsout;

	log_debug("entering convertISOTimestampTZ2TZ");

	res = assert_isISO8601TZ(inTimestampStr, inTZ);

	if ( ! res )
	{

		setISO8601OlsonOpts(&optsin);
		setISO8601Opts(&optsout);

		res = convertTimestampTZByFmt2TZ(
			inTimestampStr, optsin,
			targetTimestampStr, optsout,
			inTZ, targetTZ
		);

	}

	sprintf(msg,"leaving convertISOTimestampTZ2TZ res=%d",res);
	log_debug(msg);

	return res;

} // convertISOTimestampTZ2TZ

