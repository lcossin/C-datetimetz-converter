
CREATE OR REPLACE PACKAGE BODY TZCONVERTER AS 

	function CConvertISO8601TZToTZ(
		inTsStr 	IN VARCHAR2,
		outTsStr 	IN OUT VARCHAR2,
		inTZ IN VARCHAR2, outTZ IN VARCHAR2,
		inFmt IN BINARY_INTEGER DEFAULT TZCONVERTER_CONSTANTS.iso8601noTZ,
		outFmt IN BINARY_INTEGER DEFAULT TZCONVERTER_CONSTANTS.iso8601noTZ
	) 
	return BINARY_INTEGER
	IS EXTERNAL 
	LANGUAGE C
	LIBRARY &lib_owner..&lib_objname.
	NAME "&lib_c_func."
  PARAMETERS(inTsStr STRING, inFmt INT, outTsStr STRING, outFmt INT, inTZ STRING, outTZ STRING, RETURN INT); 

	function ConvertISO8601TZToTZ(
		inTsStr IN VARCHAR2,
		inTZ IN VARCHAR2, outTZ IN VARCHAR2,
		inFmt IN BINARY_INTEGER DEFAULT TZCONVERTER_CONSTANTS.iso8601noTZ,
		outFmt IN BINARY_INTEGER DEFAULT TZCONVERTER_CONSTANTS.iso8601noTZ
	)
	RETURN VARCHAR2
	IS
		v_in	VARCHAR2(255) ;
		v_res VARCHAR2(255) := '';
		v_rc	BINARY_INTEGER;
	BEGIN
		v_in := TZCONVERTER_FORMAT.FixupToISO8601(inTsStr);
		v_rc := CConvertISO8601TZToTZ(v_in, v_res, inTZ, outTZ, inFmt, outFmt);
		v_res := TZCONVERTER_FORMAT.FixupFromISO8601(v_res, inTsStr, v_in);
		RETURN v_res;
	END ConvertISO8601TZToTZ;

END TZCONVERTER;
/

show errors;
	
CREATE OR REPLACE PACKAGE BODY TZCONVERTER_FORMAT AS 
	
	function FixupToISO8601(TsStr IN VARCHAR2)
	RETURN VARCHAR2
	IS
		v_res	VARCHAR2(255);
	BEGIN
		v_res := REGEXP_REPLACE(TsStr,'^([[:digit:]]{4}-[[:digit:]]{2}-[[:digit:]]{2}) ([[:digit:]]{2}:[[:digit:]]{2}:[[:digit:]]{2})',
			'\1T\2');
		RETURN v_res;
	END FixupToISO8601;
	
	function FixupFromISO8601(resval IN VARCHAR2, origval IN VARCHAR2, effval IN VARCHAR2)
	RETURN VARCHAR2
	IS
		v_res	VARCHAR2(255);
	BEGIN
		IF ( origval != effval ) THEN
			v_res := REGEXP_REPLACE(resval,'^([[:digit:]]{4}-[[:digit:]]{2}-[[:digit:]]{2})T([[:digit:]]{2}:[[:digit:]]{2}:[[:digit:]]{2})',
				'\1 \2');
		ELSE
			v_res := resval;
		END IF;
		
		RETURN v_res;
	END FixupFromISO8601;

END TZCONVERTER_FORMAT;
/

show errors;
