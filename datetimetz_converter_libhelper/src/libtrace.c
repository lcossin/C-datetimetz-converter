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
#include <time.h>
#include "libtrace.h"
#include "libdatetimetz_converter_parameter.h"
#include "libdatetimetz_converter_timestamptzformat.h"

int TRACE_LEVEL = TRACE_LEVEL_CRITICAL;

int
formatted_now(char **nowstr)
{
	time_t now = time(0);
	struct tm *nowtm = localtime(&now);

	(*nowstr) = malloc(sizeof(char) * TIMESTAMPMAXLENGTH);

	strftime((*nowstr), TIMESTAMPMAXLENGTH, iso8601TZOffset, nowtm);

	return EXIT_SUCCESS;

} // formatted_now

int 
log_message(const char* module, char* msg, int msglevel, char* msgheader)
{
	if ( TRACE_LEVEL >= msglevel )
	{
		char *msg_timestamp;
		char *fmt_msgheader;

		fmt_msgheader = malloc(strlen(msgheader)+3);
		sprintf(fmt_msgheader,"[%s]",msgheader);

		formatted_now(&msg_timestamp);

		fprintf(stderr, "[%s] %-8s [%2d/%2d] [%s] %s\n",msg_timestamp, fmt_msgheader, msglevel, TRACE_LEVEL, module, msg);

		free(msg_timestamp);
		free(fmt_msgheader);

	}

	return EXIT_SUCCESS;

} // log_message

int 
log_exit_critical(const char* module, char* msg)
{
	log_critical(module, msg);
	if ( actionOnFailureOpts )
		abort();
	
	return EXIT_FAILURE;

} // log_exit_critical

int 
log_critical(const char* module, char* msg) {

  log_message(module, msg, TRACE_LEVEL_CRITICAL, TRACE_LEVEL_CRITICAL_HEADER );
  return EXIT_SUCCESS;

} // log_critical

int 
log_warning(const char* module, char* msg) {

  log_message(module, msg, TRACE_LEVEL_WARNING, TRACE_LEVEL_WARNING_HEADER );
  return EXIT_SUCCESS;

} // log_warning

int 
log_info(const char* module, char* msg) {

  log_message(module, msg, TRACE_LEVEL_INFO, TRACE_LEVEL_INFO_HEADER );
  return EXIT_SUCCESS;

} // log_info

int 
log_fine(const char* module, char* msg) {

  log_message(module, msg, TRACE_LEVEL_FINE, TRACE_LEVEL_FINE_HEADER );
  return EXIT_SUCCESS;

} // log_fine


int 
log_finer(const char* module, char* msg) {

  log_message(module, msg, TRACE_LEVEL_FINER, TRACE_LEVEL_FINER_HEADER );
  return EXIT_SUCCESS;

} // log_finer


int 
log_finest(const char* module, char* msg) {

  log_message(module, msg, TRACE_LEVEL_FINEST, TRACE_LEVEL_FINEST_HEADER );
  return EXIT_SUCCESS;

} // log_finest


int 
log_debug(const char* module, char* msg) {

	log_message(module, msg, TRACE_LEVEL_DEBUG, TRACE_LEVEL_DEBUG_HEADER );
	return EXIT_SUCCESS;

} // log_debug

