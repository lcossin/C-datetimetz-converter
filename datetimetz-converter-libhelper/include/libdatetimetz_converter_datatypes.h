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
 * @file libdatetimetz_converter_datatypes.h
 * @author Laurent Cossin
 * @date   July 2015
 *
 * @ingroup datetimetz_converter_helper
 *
 * @brief Provides the types for the data
 *
*/

#ifndef DATATYPES_HEADERS

	#define DATATYPES_HEADERS

	#ifndef TZ_ENV_SETTINGS

		#define TZ_ENV_VARNAME "TZ"

	#endif

	#ifndef TIMESTAMPDEFAULTCONSTANTS
		#define DEFAULT_TIMEZONE "UTC"
		#define EPOCH_TIMEZONE "UTC"
	#endif

	#ifndef RAWTIMESTAMPMAXLENGTH
		/// max length of a raw data (a row from a file)
		#define RAWTIMESTAMPMAXLENGTH 255
	#endif

	#ifndef TIMESTAMPMAXLENGTH
		#define TIMESTAMPMAXLENGTH 31
		#define TIMESTAMPMAXLENGTHSTR "25"
		// #define TIMESTAMPMAXLENGTHSTR 31
	#endif

	#ifndef TIMEZONESTRUCTDEF

		#define TIMEZONESTRUCTDEF

	/// type definition for timezonestructdef

	typedef struct timezonestructdef timezonestructdef;

	/// type definition for pointer to timezonestructdef

	typedef timezonestructdef *timezonestructptrdef;

	/// type definition for array of pointer to timezonestructdef

	typedef timezonestructptrdef timezonestructarrdef;

	/// structure definition for a timezone

struct timezonestructdef
{
	int		itemcount;

	char *tzname;

	timezonestructptrdef next;

};


	#endif


	#ifndef TIMESTAMPSTRUCTDEF

		#define TIMESTAMPSTRUCTDEF

	/// type definition for timestampstructdef

	typedef struct timestampstructdef timestampstructdef;

	/// type definition for pointer to timestampstructdef

	typedef timestampstructdef *timestampstructptrdef;

	/// type definition for array of pointer to timestampstructdef

	typedef timestampstructptrdef timestampstructarrdef;

	/// structure definition for a timestamp

struct timestampstructdef
{
	int		itemcount;

	char *rawstr;
	char *timestampnoTZstr;
	char *OlsonTZ;

	timestampstructptrdef next;

};

	#endif

#endif

