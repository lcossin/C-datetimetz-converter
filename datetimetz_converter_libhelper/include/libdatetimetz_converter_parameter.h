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
 * @file libdatetimetz_converter_parameter.h
 * @author Laurent Cossin
 * @copyright GNU Lesser General Public License

 * @date   July 2015
 *
 * @ingroup datetimetz_converter_helper
 *
 * @brief Provides some variables 
 *
*/

#ifndef CONFIG_HEADERS

	#define CONFIG_HEADERS
	// #include "config.h"

#endif

#ifndef PARAMETERS_HEADERS

	#define PARAMETERS_HEADERS

	/* Constants and variables that define what actions to perform in case of failure */
 
/// Continue after a failure
	#define CONTINUEONFAILURE 0

/// Abort the program after a CRITICAL error
	#define ABORTONFAILURE 1

/// Abort the program after a CRITICAL error
	#define ABORTONCRITICAL 2

/// Abort the program after a WARNING error
	#define ABORTONWARNING 4

/// The bit flags that define the actions be done in case of failure
int actionOnFailureOpts;

#endif

