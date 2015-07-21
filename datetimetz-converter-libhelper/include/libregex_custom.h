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
 * @file libregex_custom.h
 * @author Laurent Cossin
 * @date   July 2015
 *
 * @ingroup datetimetz_converter_helper
 *
 * @brief Provides some custom 'regex' routines
 *
*/

#ifndef REGEX_CUSTOM_HEADERS

	#define REGEX_CUSTOM_HEADERS

	#define REGEXPMAXLENGTH 255
	#define STRINGMAXLENGTH 255


/// Verifies if a string matches a regular expression

/**

	@param[in] string			The string to evaluate
	@param[in] regexpstr	The regular expression

	@return		the size of the longest part matching the regular expression pattern
	@retval 0		if the string does not match the regular expression
	@retval >0	if the string matches the regular expression

*/

int 
regexp_verify(char *string, char *regexpstr);

#endif

