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
 * @file libtrace.h
 * @author Laurent Cossin
 * @copyright GNU Lesser General Public License

 * @date   July 2015
 *
 * @ingroup datetimetz_converter_helper
 *
 * @brief Provides some helper functions to handle trace messages
 *
*/

#ifndef DEBUG_HEADERS

	#define DEBUG_HEADERS

/// TRACE MESSAGE maxlength
#define TRACE_MESSAGE_MAXLENGTH 1000

/// TRACE_LEVEL_NONE (constant)
#define TRACE_LEVEL_NONE 0
#define TRACE_LEVEL_NONE_HEADER "NONE"

/// TRACE_LEVEL_CRITICAL (constant)
#define TRACE_LEVEL_CRITICAL 1
#define TRACE_LEVEL_CRITICAL_HEADER "CRIT"

/// TRACE_LEVEL_WARNING (constant)
#define TRACE_LEVEL_WARNING 2
#define TRACE_LEVEL_WARNING_HEADER "WARN"

/// TRACE_LEVEL_INFO (constant)
#define TRACE_LEVEL_INFO 4
#define TRACE_LEVEL_INFO_HEADER "INFO"

/// TRACE_LEVEL_FINE (constant)
#define TRACE_LEVEL_FINE 8
#define TRACE_LEVEL_FINE_HEADER "FINE"

/// TRACE_LEVEL_FINER (constant)
#define TRACE_LEVEL_FINER 16
#define TRACE_LEVEL_FINER_HEADER "FINER"

/// TRACE_LEVEL_FINEST (constant)
#define TRACE_LEVEL_FINEST 32
#define TRACE_LEVEL_FINEST_HEADER "FINEST"

/// TRACE_LEVEL_DEBUG (constant)
#define TRACE_LEVEL_DEBUG 64
#define TRACE_LEVEL_DEBUG_HEADER "DEBUG"

/// TRACE_LEVEL (variable)
extern int TRACE_LEVEL;

/// writes the given message depending on TRACE_LEVEL

/**
  Writes messages according to TRACE_LEVEL

	input : msg - the message to be written

	output stream : stderr (hard coded)

*/

/// Writes a 'critical' level message + aborts the program

int
log_exit_critical(const char *module, char* msg);

/// Writes a 'critical' level message

int
log_critical(const char *module, char* msg);

/// Writes a 'warning' level message

int
log_warning(const char *module, char* msg);

/// Writes a 'info' level message

int 
log_info(const char *module, char* msg); 

/// Writes a 'fine' level message

int
log_fine(const char *module, char* msg);

/// Writes a 'fine' level message

int
log_finer(const char *module, char* msg);

/// Writes a 'finest' level message

int
log_finest(const char *module, char* msg);

/// Writes a 'debug' level message

int
log_debug(const char *module, char* msg);

#endif

