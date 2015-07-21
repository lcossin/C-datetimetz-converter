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

#include <regex.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "libtrace.h"
#include "libregex_custom.h"

int 
regexp_verify(char *string, char *regexpstr) 
{

	log_debug("entering regexp_verify");

	char msg[TRACE_MESSAGE_MAXLENGTH];

	regex_t regex_compiled;
	regex_t* ptr_regex_compiled;

	char regexp_pattern[REGEXPMAXLENGTH];

int res;

	int regcomp_res;
	int regexp_res;

	size_t  regexp_nmatch = 10;
	regmatch_t pmatch[STRINGMAXLENGTH];

	ptr_regex_compiled = &regex_compiled;

	strcpy(regexp_pattern, regexpstr);
	regcomp_res = regcomp(ptr_regex_compiled, regexp_pattern, REG_EXTENDED);

	regexp_res = regexec(ptr_regex_compiled, string, regexp_nmatch, pmatch, 0);

	regfree(ptr_regex_compiled);

	sprintf(msg,"[regexp_pattern] regcomp_res=%d regexp_res=%d %zu %s", regcomp_res, regexp_res, regexp_nmatch, string);
	log_finest(msg);

	if ( ! regexp_res ) {

	#ifdef __CYGWIN__
		sprintf(msg,"[regexp_pattern] matching #%zu #%zu %s", pmatch[0].rm_so, pmatch[0].rm_eo, string+pmatch[0].rm_so);
	#else
		sprintf(msg,"[regexp_pattern] matching #%d #%d %s", pmatch[0].rm_so, pmatch[0].rm_eo, string+pmatch[0].rm_so);
	#endif

		log_finest(msg);

		res = pmatch[0].rm_eo;

	}
	else
		res = 0;

	log_debug("leaving regexp_verify");

	//return EXIT_SUCCESS;
	return res;

} // regexp_verify

