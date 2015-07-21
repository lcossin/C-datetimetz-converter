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
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "libtrace.h"
#include "libassert_custom.h"

#include "libdatetimetz_converter_timestamptzformat.h"

int 
setOlsonOpts(int* flags) 
{

	*flags = *flags | TZOlsonFlag;

	return *flags;

} //setOlsonOpts

int 
setISO8601Opts(int* flags) 
{

	*flags = *flags | iso8601Flag;
	return *flags;

} // setISO8601Opts

int 
setISO8601OlsonOpts(int* flags) 
{

	setISO8601Opts(flags);
	setOlsonOpts(flags);

	return *flags;

} //  setISO8601OlsonOpts

int 
setOlsonInputFmtOpts(int* flags) 
{

	setOlsonOpts(flags);

	return *flags;

} //setOlsonInputFmtOpts

int 
setOlsonOutputFmtOpts(int* flags) 
{

	setOlsonOpts(flags);

	return EXIT_SUCCESS;

} //setOlsonOutputFmtOpts

int 
setDefaultInputFmtOpts(int* flags)
{

  *flags = 0;
	setISO8601Opts(flags);

  return *flags;

} // setDefaultInputFmtOpts

int 
setDefaultOutputFmtOpts(int* flags)
{

  *flags = iso8601Flag | TZAbbrevFlag;

  return *flags;

} //setDefaultOutputFmtOpts


int 
isISO8601(int FmtFlags)
{
	int res;

	res = FmtFlags & iso8601Flag;

	return res;

} //isISO8601

int 
isTZAbbrev(int FmtFlags)
{
	int res;

	res = FmtFlags & TZAbbrevFlag;

	return res;

} //isTZAbbrev

int 
isTZOlson(int FmtFlags)
{

	int res;

	res = FmtFlags & TZOlsonFlag;

	return res;

} //isTZOlson

int 
append2FmtStr(char* FmtStr, const char* addStr)
{

	char *tempstr;
  int  addspace;
  char spacestr[2] = " ";

	size_t currsz = strlen(FmtStr)+1;

	addspace = ( currsz > 1 );

	printf("currsz A %d %zu %p\n",addspace,currsz,FmtStr);
	
	currsz += strlen(addStr);
	
	//printf("currsz B %zu %p ",currsz,FmtStr);

	//printf("currsz C %zu %p ",currsz,str);

	tempstr = (char *) realloc(FmtStr, currsz);

	if (tempstr == NULL)
	{
		free(FmtStr);
	}
	FmtStr = tempstr;

	printf("currsz B %zu %p -> %p\n",currsz,FmtStr,tempstr);

	if ( addspace ) {
		strcat(FmtStr,spacestr);
  }

	strcat(FmtStr, addStr);

	return EXIT_SUCCESS;

} //append2FmtStr


int 
appendISO8601noTZ(char* FmtStr)
{
	int res;

	res = append2FmtStr(FmtStr, iso8601noTZFmt);

	// return EXIT_SUCCESS;

	return res;

} //appendISO8601noTZ

int 
appendTZAbbrev(char* FmtStr)
{
	int res;

	res = append2FmtStr(FmtStr, TZAbbrevFmt);

	// return EXIT_SUCCESS;

	return res;

} //appendTZAbbrev


/// initializes an empty string

int 
initFmtStr(char* FmtStr) {

	if (FmtStr == NULL)
	{
		FmtStr = (char *) malloc(1);
		int assert_res = 0;
		assert_res += assert_pointer_is_not_null(FmtStr,"[initFmtStr] FmtStr");
		if ( assert_res )
			return EXIT_FAILURE;
	}

	FmtStr[0]='\0';
	strcpy(FmtStr,"");

	return EXIT_SUCCESS;

} //initFmtStr


/// builds the format string according to the options (FmtFlags)

int 
buildFmtStr(int FmtFlags, char* FmtStr) 
{

	initFmtStr(FmtStr);

	if ( isISO8601(FmtFlags) ) 
	{
		appendISO8601noTZ(FmtStr);
	}

	if ( isTZAbbrev(FmtFlags) ) 
	{
		appendTZAbbrev(FmtStr);
	}


	return EXIT_SUCCESS;

} // buildFmtStr

