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
 * @file libassert_custom.h
 * @author Laurent Cossin
 * @copyright GNU Lesser General Public License
 *
 * @date   July 2015
 *
 * @ingroup datetimetz_converter_helper
 *
 * @brief Provides some custom 'assert' routines
 *
*/

#ifndef ASSERT_CUSTOM_HEADERS

	#define ASSERT_CUSTOM_HEADERS

// assert 'pointer is initialized'

int
assert_pointer_is_not_null(void *ptr, char *ptrname);

// assert 'string is not empty'

int
assert_string_is_not_null(char *string, char *stringname);

#endif

