CREATE OR REPLACE PACKAGE TZCONVERTER_CONSTANTS AS

	/* Constants for the routines */

	iso8601noTZ			CONSTANT BINARY_INTEGER := 1;
	iso8601Abbrev		CONSTANT BINARY_INTEGER := 3;
	iso8601Offset		CONSTANT BINARY_INTEGER := 5;
	iso8601Combined	CONSTANT BINARY_INTEGER := 7;
		
END TZCONVERTER_CONSTANTS;
/

show errors;

CREATE OR REPLACE PACKAGE TZCONVERTER AS
	
	/* function to convert a timestamp between timezones, returning the result as OUT parameter */
	
	/*
	
		param[out] outTsStr The timestamp string after conversion
	
		return the result after conversion and the return code (success = 0 or failure <> 0)
		retval the return code of the conversion
		
	*/
	
	function CConvertISO8601TZToTZ(
		inTsStr 	IN VARCHAR2,
		outTsStr 	IN OUT VARCHAR2,
		inTZ IN VARCHAR2, outTZ IN VARCHAR2,
		inFmt IN BINARY_INTEGER DEFAULT TZCONVERTER_CONSTANTS.iso8601noTZ,
		outFmt IN BINARY_INTEGER DEFAULT TZCONVERTER_CONSTANTS.iso8601noTZ
	)  
	return BINARY_INTEGER;

	/* function to convert a timestamp between timezones, returning the result as the return value of the function */

	/*
		
		calls CConvertISO8601TZToTZ
		
		return the result after conversion
		retval the result after conversion
		
	*/
	
	function ConvertISO8601TZToTZ(
		inTsStr IN VARCHAR2,
		inTZ IN VARCHAR2, outTZ IN VARCHAR2,
		inFmt IN BINARY_INTEGER DEFAULT TZCONVERTER_CONSTANTS.iso8601noTZ,
		outFmt IN BINARY_INTEGER DEFAULT TZCONVERTER_CONSTANTS.iso8601noTZ
		)
	RETURN varchar2;
			
END TZCONVERTER;
/

show errors;

CREATE OR REPLACE PACKAGE TZCONVERTER_FORMAT AS
			
	/* Routines to adjust the format before/after calling the converter functions */
			
	/*
			adds "T" delimiter to meet strict ISO8601 format
	*/

	function FixupToISO8601(TsStr IN VARCHAR2)
	RETURN VARCHAR2;

	/*
			removes "T" delimiter 
			
			only if original value has been modified before calling the timezone converter function
						
			origval : original value
			effval  : effectiv original value after ISO8601 fixup

			resval  : result value to be rewritten (if needed)
			
			the function compares origval with effval
			and returns resval in the expected format (with the "T" delimiter or without the "T" delimeter)

	*/	

	function FixupFromISO8601(resval IN VARCHAR2, origval IN VARCHAR2, effval IN VARCHAR2)
	RETURN VARCHAR2;
		
END TZCONVERTER_FORMAT;
/

show errors;
