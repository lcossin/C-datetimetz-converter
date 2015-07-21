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

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libassert_custom.h"
#include "libtrace.h"

int
assert_pointer_is_not_null(void *ptr, char *ptrname)
{

	char msg[TRACE_MESSAGE_MAXLENGTH];

	if ( ptr )
	{
		sprintf(msg,"[assert_pointer_is_not_null] pointer %s is initialized",ptrname);
		return log_debug(msg);
	}
	else
	{
		sprintf(msg,"[assert_pointer_is_not_null] pointer %s is NULL uninitialized",ptrname);
		return log_exit_critical(msg);
	}

} // assert_pointer_is_not_null

int
assert_string_is_not_null(char *string, char *stringname)
{

	char msg[TRACE_MESSAGE_MAXLENGTH];

	if ( string && strlen(string) )
	{
		sprintf(msg,"[assert_string_is_not_null] %s is not an empty string",stringname);
		return log_debug(msg);
	}
	else
	{
		sprintf(msg,"[assert_string_is_not_null] pointer %s is NULL or empty",stringname);
		return log_exit_critical(msg);
	}

} // assert_string_is_not_null

